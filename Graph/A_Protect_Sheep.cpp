#include<bits/stdc++.h>
using namespace std;

bool isvalid(int row, int col, int r, int c) {
    if(row >= 0 && col >= 0 && row < r && col < c)
        return true;
    return false;
}


bool solve(vector<string>& field, int r, int c) {
    vector<pair<int,int>> dogs;
    queue<pair<int,int>> q;
    vector<pair<int,int>> dir = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> vis(r, vector<bool>(c, 0));

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(field[i][j] == 'S') {
                q.push({i,j});
                vis[i][j] = 1;
            }
    
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(auto i:dir) {
            int newRow = row + i.first;
            int newCol = col + i.second;

            if(isvalid(newRow, newCol, r, c) && vis[newRow][newCol] == 0) {
                if(field[newRow][newCol] == 'W') 
                    dogs.push_back({row, col});
                else {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
    }


    for(auto loc:dogs) {
        if(field[loc.first][loc.second] == 'S')
            return false;
        field[loc.first][loc.second] = 'D';
    }

    return true;
}



int main() {
    int r, c, i=0;
    cin >> r >> c;

    vector<string> field;
    while(i < r) {
        string tmp;
        cin >> tmp;

        field.push_back(tmp);
        i++;
    }

    bool possible = solve(field, r, c);

    if(possible) {
        cout << "Yes\n";
        for(auto row:field)
            cout << row << endl;
    }
    else
        cout << "No";

    return 0;
}
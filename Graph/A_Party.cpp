#include<bits/stdc++.h>
using namespace std;


void display(vector<vector<int>>& graph, vector<int>& indeg) {
    cout << "Graph\n";
    for(auto i:graph){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }

    cout << "indeg\n";
    for(auto i:indeg)
        cout << i << " ";
    cout << endl;
}

int solve(vector<vector<int>>& graph, vector<int>& indeg, int n) {
    vector<bool> vis(n, 0);
    queue<vector<int>> q;
    int teams = 0;

    for(int i=0; i<n; i++) {
        // cout << i << " " << indeg[i] << endl;
        if(indeg[i] == 0) {
            // cout << "indeg zero "<< i << endl;
            q.push({i});
            vis[i] = 1;
            int count = 1;

            while(!q.empty()) {
                vector<int> emps = q.front();
                q.pop();
                
                
                vector<int> next;
                for(auto emp:emps) {
                    for(auto underEmp:graph[emp]) {
                        if(!vis[underEmp]) {
                            next.push_back(underEmp);
                            vis[underEmp] = 1;
                        }
                    }
                }

                if(next.size() > 0) {
                    q.push(next);
                    count++;
                }
                // cout << "comparing " << teams << " " << count << endl;
                teams = max(teams, count);
            }
        }
    }

    return teams;
}

int main() {
    int n, i=0;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);

    while(i < n) {
        int sup;
        cin >> sup;

        if(sup != -1) {
            graph[sup-1].push_back(i);
            indeg[i]++;
        }

        i++;
    }
    // display(graph, indeg);
    cout << solve(graph, indeg, n);

    return 0;
}
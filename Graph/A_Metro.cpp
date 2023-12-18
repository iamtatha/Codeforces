#include<bits/stdc++.h>
using namespace std;

bool solve(int n, int s, vector<int>& a, vector<int>& b) {
    s = s-1;

    // CREATE GRAPH
    vector<vector<int>> graph(n);
    vector<int> prefix;
    int left, right;

    for(right=n-1; right>=0; right--) {
        if(a[right]) {
            graph[right] = prefix;
            prefix.push_back(right);
        }
    }
    prefix.clear();
    for(left=0; left<n; left++) {
        if(b[left]) {
            for(auto i:prefix)
                graph[left].push_back(i);
            
            prefix.push_back(left);
        }
    }


    // BFS
    queue<int> q;
    vector<bool> vis(n, 0);

    q.push(0);
    vis[0] = 1;

    while(!q.empty()) {
        int stn = q.front();
        q.pop();

        if(stn == s)
            return true;

        for(auto next:graph[stn]) {
            if(!vis[next]) {
                q.push(next);
                vis[next] = 1;
            }
        }
    }

    return false;
}

int main() {
    int n,s;
    cin >> n >> s;

    vector<int> a, b;
    int i = 0, j = 0;
    while(i<n){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        i++;
    }
    while(j<n){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
        j++;
    }

    if(solve(n, s, a, b))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
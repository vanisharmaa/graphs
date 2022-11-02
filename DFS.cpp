#include<bits/stdc++.h>
using namespace std;

void printDfs(vector<vector<int>>& adj, int n, bool* visited, int sv){
    visited[sv] = true;
    cout << sv << endl;
    for(int i = 0; i < adj[sv].size(); i++){
        if(!visited[adj[sv][i]])
            printDfs(adj, n, visited, adj[sv][i]);
    }
}

void DFS(vector<vector<int>>& adj, int n){
    bool* visited = new bool[n+1];
    for(int i = 0; i <= n; i++){
        visited[i] = false;
    }
    int sv;
    cout << "enter sv: ";
    cin >> sv;
    cout << "DFS Traversal: " << endl;
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            printDfs(adj, n, visited, sv);
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < e; i++){
        int fv, sv;
        cin >> fv >> sv;
        adj[fv].push_back(sv);
        adj[sv].push_back(fv);
    }
    DFS(adj, n);
}

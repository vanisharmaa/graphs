#include<bits/stdc++.h>
using namespace std;

//FOR 1 BASES INDEXING

void printBfs(vector<vector<int>>& adj, int n, bool* visited, int sv){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    cout << "BFS Traversal: " << endl;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for(int i = 0; i < adj[curr].size(); i++){
            if(!visited[adj[curr][i]]){
                q.push(adj[curr][i]);
                visited[adj[curr][i]] = true;
            }
        }
    }
}

void BFS(vector<vector<int>>& adj, int n){
    bool* visited = new bool[n+1];
    for(int i = 0; i <= n; i++){
        visited[i] = false;
    }
    int sv;
    cout << "enter starting vertex" << endl;
    cin >> sv;
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            printBfs(adj, n, visited, sv);
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
    BFS(adj, n);
}

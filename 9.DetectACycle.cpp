/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
*/

bool DFS(vector<int> adj[], int n, int sv, int parent, bool visited[]){
    visited[sv] = true;
    for(int i = 0; i < adj[sv].size(); i++){
        if (!visited[adj[sv][i]]){
            bool b = DFS(adj, n, adj[sv][i], sv, visited);
            if (b){
                return true;
            }
        }
        else{
            if(adj[sv][i] != parent){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int n, vector<int> adj[]) {
    // Code here
    bool visited[n] = {0};
    for(int i = 0; i < n ; i++){
        if (!visited[i]){
            bool b = DFS(adj, n, i, -1, visited);
            if(b){
                return true;
            }
        }
    }
    return false;
}

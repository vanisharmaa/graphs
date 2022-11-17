/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/

bool DFS(vector<int> adj[], int n, int vis[], int pathVis[], int sv){
    vis[sv] = 1;
    pathVis[sv] = 1;
    for(int i = 0; i < adj[sv].size(); i++){
        if(!vis[adj[sv][i]]){
            bool b = DFS(adj, n, vis, pathVis, adj[sv][i]);
            if(b){
                return true;
            }
        }else{
            if(pathVis[adj[sv][i]]){
                return true;
            }
        }
    }
    pathVis[sv] = false;
    return false;
}
bool isCyclic(int n, vector<int> adj[]) {
    // code here
    int vis[n] = {0};
    int pathVis[n] = {0};
    for(int i = 0; i < n; i++){
        if (!vis[i]){
            bool b = DFS(adj, n, vis, pathVis, i);
            if (b){
                return true;
            }
        }
    }
    return false;
}

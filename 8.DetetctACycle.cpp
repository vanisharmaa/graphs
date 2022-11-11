/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.  
*/

bool BFS(vector<int> adj[], int n, int sv, bool visited[]){
    queue<pair<int, int>> q; //to store current node and it's parent
    q.push({sv, -1});
    visited[sv] = true;
    while(!q.empty()){
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int i = 0; i < adj[curr].size(); i++){
            if (!visited[adj[curr][i]]){
                q.push({adj[curr][i], curr});
                visited[adj[curr][i]] = true;
            }else{
                if(parent != adj[curr][i]){ //if it's visited but it's not curr's parent, someone visited it before and hence it is a cycle.
                    return true;
                }
            }
        }
    }
    return false;
}
bool isCycle(int n, vector<int> adj[]) {
    // Code here
    bool visited[n] = {0};
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool b = BFS(adj, n, i, visited);
            if(b){
                return true;
            }
        }
    }
    return false;
}

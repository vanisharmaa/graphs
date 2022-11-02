/*

There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

*/

void DFS(vector<vector<int>>& adj, int n, bool* visited, int sv){
    visited[sv] = true;
    for(int i = 0; i < n; i++){
        if(!visited[i] and adj[sv][i])
            DFS(adj, n, visited, i);
    }
}
int findCircleNum(vector<vector<int>>& isConnected) { //Given an adjacency matrix
    int n = isConnected.size();
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(isConnected, n, visited, i);
            count++;
        }
    }
    return count;
}

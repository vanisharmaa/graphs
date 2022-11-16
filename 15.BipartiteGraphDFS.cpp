/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

bool DFS(vector<vector<int>>& graph, int n, vector<int>& vis, vector<int>& vec, int sv, int color){
    vec[sv] = color;
    vis[sv] = 1;
    for(int i = 0; i < graph[sv].size(); i++){
        if(!vis[graph[sv][i]]){
            bool b = DFS(graph, n, vis, vec, graph[sv][i], !color);
            if(!b){
                return false;
            }
        }else if(vec[graph[sv][i]] == color){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> vec(n, -1);
    for(int i = 0; i < n; i++){
        if (!vis[i]){
            bool b = DFS(graph, n, vis, vec, i, 0);
            if (!b){
                return false;
            }
        }
    }
    return true;
}

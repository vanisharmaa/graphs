/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 
1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not 
equal to another (not rotated or reflected).
*/

/*
LOGIC:
store the indices of islands in a vector and to see if they are unique or not, store them in a set after deleting root indices of i0 and j0 from all the indices.
*/
void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& visited, vector<pair<int, int>>& vec, int i0, int j0){
    visited[i][j] = 1;
    vec.push_back({i - i0, j - j0});
    int di[] = {-1, 0, 0, 1};
    int dj[] = {0, -1, 1, 0};
    for(int x = 0; x < 4; x++){
        int newi = i + di[x];
        int newj = j + dj[x];
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){
            
        }
        else if(!visited[newi][newj] and grid[newi][newj] == 1){
            dfs(grid, newi, newj, n, m, visited, vec, i0, j0);
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid) {
    // code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] and grid[i][j] == 1){
                vector<pair<int, int>> vec;
                dfs(grid, i, j, n, m, visited, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

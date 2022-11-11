/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
*/

vector<vector<int>> BFS(vector<vector<int>>& mat, int n, int m, bool** visited){
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q; //for the indices and nearest distance from 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            if(mat[i][j] == 0){
                q.push({{i,j}, 0});
                visited[i][j] = true;
            }
        }
    }
    while(!q.empty()){
        pair<pair<int, int>, int> p = q.front();
        int i = p.first.first;
        int j = p.first.second;
        int level = p.second;
        q.pop();
        //up
        int newi = i-1, newj = j;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and mat[newi][newj] == 1){
                visited[newi][newj] = true;
                ans[newi][newj] = level+1;
                q.push({{newi, newj}, level+1});
            }
        }
        //left
        newi = i, newj = j-1;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and mat[newi][newj] == 1){
                visited[newi][newj] = true;
                ans[newi][newj] = level+1;
                q.push({{newi, newj}, level+1});
            }
        }
        //right
        newi = i, newj = j+1;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and mat[newi][newj] == 1){
                visited[newi][newj] = true;
                ans[newi][newj] = level+1;
                q.push({{newi, newj}, level+1});
            }
        }
        //down
        newi = i+1, newj = j;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and mat[newi][newj] == 1){
                visited[newi][newj] = true;
                ans[newi][newj] = level+1;
                q.push({{newi, newj}, level+1});
            }
        }
    }
    return ans;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    bool** visited = new bool*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[m];
        for(int j = 0; j < m ; j++){
            visited[i][j] = false;
        }
    }
    return BFS(mat, n, m, visited);
}

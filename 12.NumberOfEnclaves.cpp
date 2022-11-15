void BFS(vector<vector<int>>& grid, int n, int m, int i, int j, bool** visited, int flag, int& count){
    cout << i << " " << j << endl;
    queue<pair<int, int>> q;
    q.push({i, j});
    if(flag){
        count++;
    }
    visited[i][j] = true;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        //up
        int newi = i-1, newj = j;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and grid[newi][newj] == 1){
                if(flag){
                    count++;
                }
                q.push({newi, newj});
                visited[newi][newj] = true;
            }
        }
        //left
        newi = i, newj = j-1;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and grid[newi][newj] == 1){
                if(flag){
                    count++;
                }
                q.push({newi, newj});
                visited[newi][newj] = true;
            }
        }
        //right
        newi = i, newj = j+1;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and grid[newi][newj] == 1){
                if(flag){
                    count++;
                }
                q.push({newi, newj});
                visited[newi][newj] = true;
            }
        }
        //down
        newi = i+1, newj = j;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else{
            if(!visited[newi][newj] and grid[newi][newj] == 1){
                if(flag){
                    count++;
                }
                q.push({newi, newj});
                visited[newi][newj] = true;
            }
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    bool ** visited = new bool*[n];
    for(int i = 0; i < n ; i++){
        visited[i] = new bool[m];
        for(int j = 0; j < m ; j++){
            visited[i][j] = false;
        }
    }
    int nothing = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if (i == 0 or j == 0 or i == n-1 or j == m-1){
                if (grid[i][j] == 1 and !visited[i][j]){
                    BFS(grid, n, m, i, j, visited, 0, nothing);
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(grid[i][j] == 1 and !visited[i][j]){
                BFS(grid, n, m, i, j, visited, 1, count);
            }
        }
    }
    return count;
}

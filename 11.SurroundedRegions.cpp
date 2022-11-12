void DFS(vector<vector<char>>& board, int n, int m, int i, int j, bool** visited, bool flag){
    if (flag){
        board[i][j] = 'X';
    }
    visited[i][j] = true;
    //up
    int newi = i-1, newj = j;
    if (newi >= 0 and newi < n and newj >= 0 and newj < m){
        if(!visited[newi][newj] and board[newi][newj] == 'O'){
            DFS(board, n, m, newi, newj, visited, flag);
        }
    }
    //left
    newi = i, newj = j-1;
    if (newi >= 0 and newi < n and newj >= 0 and newj < m){
        if(!visited[newi][newj] and board[newi][newj] == 'O'){
            DFS(board, n, m, newi, newj, visited, flag);
        }
    }
    //right
    newi = i, newj = j+1;
    if (newi >= 0 and newi < n and newj >= 0 and newj < m){
        if(!visited[newi][newj] and board[newi][newj] == 'O'){
            DFS(board, n, m, newi, newj, visited, flag);
        }
    }
    //down
    newi = i+1, newj = j;
    if (newi >= 0 and newi < n and newj >= 0 and newj < m){
        if(!visited[newi][newj] and board[newi][newj] == 'O'){
            DFS(board, n, m, newi, newj, visited, flag);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    bool** visited = new bool*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 or i == n-1 or j == 0 or j == m-1){
                if(board[i][j] == 'O'){
                    // cout << "-> " << i << " " << j << endl;
                    DFS(board, n, m, i, j, visited, 0);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'O' and !visited[i][j]){
                // cout << "-> " << i << " " << j << endl;
                DFS(board, n, m, i, j, visited, 1);
            }
        }
    }
}

/***
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
***/
void BFS(vector<vector<char>>& grid, int i, int j, int n, int m, bool** visited){
      visited[i][j] = true;
      queue<pair<int, int>> q;
      q.push({i, j});
      while(!q.empty()){
          pair<int, int> p = q.front();
          q.pop();
          cout << ": " << p.first << " " << p.second << endl;
          i = p.first, j = p.second;
          visited[i][j] = true;

          //Checking in all 4 directions
          int newi = i - 1, newj = j; //vertically up
          if (newi < 0 or newi >= n or newj < 0 or newj >= m){

          }
          else if(!visited[newi][newj] and grid[newi][newj] == '1'){
              q.push({newi, newj});
              visited[newi][newj] = true;
          }
          newi = i, newj = j-1; //horizontally left
          if (newi < 0 or newi >= n or newj < 0 or newj >= m){

          }
          else if(!visited[newi][newj] and grid[newi][newj] == '1'){
              q.push({newi, newj});
              visited[newi][newj] = true;
          }
          newi = i, newj = j+1; //horizontally right
          if (newi < 0 or newi >= n or newj < 0 or newj >= m){
          }
          else if(!visited[newi][newj] and grid[newi][newj] == '1'){
              q.push({newi, newj});
              visited[newi][newj] = true;
          }
          newi = i+1, newj = j; //vertically down
          if (newi < 0 or newi >= n or newj < 0 or newj >= m){
          }
          else if(!visited[newi][newj] and grid[newi][newj] == '1'){
              q.push({newi, newj});
              visited[newi][newj] = true;
          }
      }
  }
  int numIslands(vector<vector<char>>& grid) {
      int n = grid.size(), m = grid[0].size();
      bool** visited = new bool*[n];
      for(int i = 0; i < n; i++){
          visited[i] = new bool[m];
          for(int j = 0; j < m; j++){
              visited[i][j] = false;
          }
      }
      int count = 0;
      for(int i = 0; i <  n; i++){
          for(int j = 0; j < m; j++){
              if(!visited[i][j] and grid[i][j] == '1'){
                  cout << "->" << i << " " << j << endl;
                  count++;
                  BFS(grid, i, j, n, m, visited);
              }
          }
      }
      return count;
  }

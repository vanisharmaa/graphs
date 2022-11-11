/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

class Solution {
public:
    int minTime(vector<vector<int>>& grid, int n, int m, int** visited){
        queue<pair<pair<int, int>, int>> q;
        //pushing initially rotten oranges in the queue with time = 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 2;
                }
            }
        }
        int maxTime = 0; //minimium time to rot all oranges.
        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            q.pop();
            int i = curr.first.first;
            int j = curr.first.second;
            int time = curr.second;
            maxTime = max(maxTime, time);
            //vertically up
            int newi = i-1, newj = j;
            if(newi < 0 or newi >= n or newj < 0 or newj >= m){

            }
            else if(!visited[newi][newj] and grid[newi][newj] == 1){
                visited[newi][newj] = 2;
                grid[newi][newj] = 2;
                q.push({{newi, newj}, time+1});
            }
            //horizontally left
            newi = i, newj = j-1;
            if(newi < 0 or newi >= n or newj < 0 or newj >= m){

            }
            else if(!visited[newi][newj] and grid[newi][newj] == 1){
                visited[newi][newj] = 2;
                grid[newi][newj] = 2;
                q.push({{newi, newj}, time+1});
            }
            //horizontally right
            newi = i, newj = j+1;
            if(newi < 0 or newi >= n or newj < 0 or newj >= m){

            }
            else if(!visited[newi][newj] and grid[newi][newj] == 1){
                visited[newi][newj] = 2;
                grid[newi][newj] = 2;
                q.push({{newi, newj}, time+1});
            }
            //vertically down
            newi = i+1, newj = j;
            if(newi < 0 or newi >= n or newj < 0 or newj >= m){

            }
            else if(!visited[newi][newj] and grid[newi][newj] == 1){
                visited[newi][newj] = 2;
                grid[newi][newj] = 2;
                q.push({{newi, newj}, time+1});
            }
        }
        return maxTime;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int** visited = new int*[n];
        for(int i = 0; i < n ; i++){
            visited[i] = new int[m];
            for(int j = 0 ; j < m; j++){
                visited[i][j] = 0;
            }
        }
        int ans = minTime(grid, n, m, visited);
        //Checking if all oranges are rotten or not
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
            cout << endl;
        }
        return ans;
    }
};

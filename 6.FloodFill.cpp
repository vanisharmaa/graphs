/***
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. 
You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally 
to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
***/


void BFS(vector<vector<int>>& image, int sr, int sc, int color, int n, int m, bool** visited){
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        int i = p.first, j = p.second;
        visited[i][j] = true;
        q.pop();
        int newi = i-1, newj = j;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else if(!visited[newi][newj] and image[newi][newj] == image[sr][sc]){
            image[newi][newj] = color;
            q.push({newi, newj});
        }
        newi = i, newj = j-1;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else if(!visited[newi][newj] and image[newi][newj] == image[sr][sc]){
            image[newi][newj] = color;
            q.push({newi, newj});
        }
        newi = i, newj = j+1;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else if(!visited[newi][newj] and image[newi][newj] == image[sr][sc]){
            image[newi][newj] = color;
            q.push({newi, newj});
        }
        newi = i+1, newj = j;
        if(newi < 0 or newi >= n or newj < 0 or newj >= m){

        }
        else if(!visited[newi][newj] and image[newi][newj] == image[sr][sc]){
            image[newi][newj] = color;
            q.push({newi, newj});
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    bool** vis = new bool*[n]; 
    for(int i = 0; i < n; i++){
        vis[i] = new bool[m];
        for(int j = 0; j < m; j++){
            vis[i][j] = false;
        }
    }
    // int arr[][] =  
    BFS(image, sr, sc, color, n, m, vis);
    image[sr][sc] = color;
    return image;
}

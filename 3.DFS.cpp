#include<bits/stdc++.h>
using namespace std;
/*
5 6
0 1
0 2
0 3
0 4
1 3
3 4
*/
void printDFS(vector<int> adjList[], int n, int sv, bool visited[]){
  cout << sv << " ";
  visited[sv] = true;
  for(int i = 0; i < adjList[sv].size(); i++){
    if(!visited[adjList[sv][i]]){
      printDFS(adjList, n, adjList[sv][i], visited);
    }
  }
}
void DFS(vector<int> adjList[], int n){
  bool visited[n] = {false};
  for(int i = 0 ; i < n ; i++){
      if(!visited[i])
          printDFS(adjList, n, i, visited);
  }
}

int main(){
  int v, e;
  cin >> v >> e;
  vector<int> adjList[v];
  for(int i = 0; i < e; i++){
    int fv, sv;
    cin >> fv >> sv;
    adjList[fv].push_back(sv);
    adjList[sv].push_back(fv);
  }
  DFS(adjList, v);
}

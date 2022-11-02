#include<bits/stdc++.h>
using namespace std;
/*
graph
5 6
1 2
2 3
3 4
4 1
3 5
4 5
*/
//VECTOR OF VECTORS

/****************APPROACH 1*****************/
int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < e; i++){
        int fv, sv;
        cin >> fv >> sv;
        adj[fv].push_back(sv);
        adj[sv].push_back(fv);
    }
    cout << "Adjacency list" << endl;
    for(int i = 0; i <= n; i++){
            cout << i << " : ";
        for(int j = 0 ; j < adj[i].size(); j++){
            cout << adj[i][j] << ", ";
        }
        cout << endl;
    }
}


/****************APPROACH 2*****************/
//ARRAY OF VECTORS
int main(){
    int n, e;
    cout << "vertices and edges \n";
    cin >> n >> e;
    vector<int> adj[n+1]; //Array of vectors
    cout << e << " edges: \n";
    for(int i = 0; i < e; i++){
        int fv, sv;
        cin >> fv >> sv;

        adj[sv].push_back(fv);
        adj[fv].push_back(sv);
    }
    cout << "Adjacency list" << endl;
    for(int i = 0; i <= n; i++){
            cout << i << " : ";
        for(int j = 0 ; j < adj[i].size(); j++){
            cout << adj[i][j] << ", ";
        }
        cout << endl;
    }
}


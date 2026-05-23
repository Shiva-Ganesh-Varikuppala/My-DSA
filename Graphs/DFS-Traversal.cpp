#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited){

    // mark current node visited
    visited[node] = true;

    // print current node
    cout << node << " ";

    // traverse all neighbours
    for(int neighbor : graph[node]){

        // visit only univisited neighbors
        if(!visited[neighbor]){
            dfs(graph, neighbor, visited);
        }
    }
}


int main(){

    int n = 6;
    
    // adjacency list
    vector<vector<int>> graph(n);

    // add edges
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[1].push_back(4);
    graph[4].push_back(1);

    graph[2].push_back(5);
    graph[5].push_back(2);

    // visited array
    vector<bool> visited(n, false);

    // start DFS from node 0
    dfs(graph, 0, visited);

    return 0;
}
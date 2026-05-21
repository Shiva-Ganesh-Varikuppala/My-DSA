/* 
BFS(Breadth First Search) is one of the most important algos in DSA

It explores nodes level by level and distance by distance: it visits nearest(breadth) nodes first before going farther.

Real life example: Imaging we throw a stone in water: waves spread first nearby area, then farther area, then more farther
BFS works exactly like this.
Example Graph:

    0
   /  \
  1    2
 / \     \
 3   4     5

- Start BFS from node '0'
- Level 0: 0
- Level 1: Neighbours of '0' - (1, 2)
- Level 2: Neighbours of '1', '2' - (3, 4, 5)

Final BFS order: 0 1 2 3 4 5
Noticeable points: closer nodes visited first, then farther nodes

- BFS needs: Queue and visited array
Because queue follows FIFO(First In First Out) principle - and this perfectly matches level-wise traversal.

*/

/* 
BFS Dry Run: 

0
/   \
1     2
/ \
3   4

Intial State: Queue: [0], visited: 0 = true
Step 1: pop '0'
- output: 0
- push neighbours: (1, 2)
- now queue: [1, 2]
Step 2: pop '1'
- output: 0, 1
- push neighbours: (3, 4)
- now queue: [2, 3, 4]
Step 3: pop '2'
- output: 0, 1, 2
- push neighbours: no neighbours are there to push
- now queue: [3, 4]
Step 4: pop '3'
- output: 0, 1, 2, 3
- push neighbours: no neighbours are there to push
- now queue: [4]
Step 5: pop '4'
- output: 0, 1, 2, 3, 4
- push neighbours: no neighbours are there to push
- now queue: [0]

*/

/* 
BFS Algorithm:
Steps: 
1. Put source node into queue
2. Mark it visited
3. While queue not empty: 
- remove front node
- process it 
- push unvisited neighbours
*/
// CODE: 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << endl;
}

int main(){
    int n = 6;

    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};

    bfs(0, graph);

    return 0;
}
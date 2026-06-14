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

// =========================================================================================================

// CODE: 
/* 
Example graph:
                 0
                / \
               1    2
              / \     \
              3  4     5
*/
/* 
lets start from node '0':
- first visit 0
- then all neighbours of 0
- then next level neighbors
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &graph, int start, int n){

    // visited array to track visited nodes
    vector<bool> visited(n, false);
    
    // queue for bfs traversal
    queue<int> q;

    // pushing starting node
    q.push(start);

    // mark start node as visited
    visited[start] = true;

    // run until queue becomes empty
    while(!q.empty()){

        // get front node
        int node = q.front();

        // remove front node
        q.pop();

        // print current node
        cout << node << " ";

        // traversal all neighbours
        for(int neighbour : graph[node]){

            // if neighbour not visited
            if(!visited[neighbour]){

                // mark visited 
                visited[neighbour] = true;

                // push into queue
                q.push(neighbour);
            }
        }
    }
}

int main(){
    int n = 6;

    // adjacency list
    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[1].push_back(0);
    
    graph[2].push_back(5);
    graph[2].push_back(0);
    
    graph[3].push_back(1);
    
    graph[4].push_back(1);
    
    graph[5].push_back(2);

    bfs(graph, 0, n);

    return 0;
}

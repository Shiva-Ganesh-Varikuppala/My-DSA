#include <iostream>
#include <vector>
using namespace std;

/*
*================* THEORY *================*

A graph is a data structure used to represnt the relationships between objects.
- Objects: vertices(nodes)
- Connections(relationship) between them called 'edges'
Ex:
    - cities connected by roads
    - users connected in social networks
    - webpages connected by hyperlinks
    - computers connected in networks

Basic Terminology:
- consider this graph:

A ----- B
|       |
|       |
C ----- D
Here, A, B, C, D are 'vertices' and the connected lines between them are called
'edges'.

Types of graphs are based on different categories:
1.Based on 'SIZE':
    - finite graph: a finite graph is a graph with finite no of vertices and
edges.
    - infinite graph: this graph has an infinite no of vertices and edges, these
graphs nodes and edges are uncountable.

2.Based on 'STRUCTURE':
    - trivial graph: a graph is said to be trivial if a finite graph having only
1 vertex and 0 edges.
    - simple graph: this graph doesnt contain more than one edge b/w the pair of
vertices.
    - multi graph: graph which contains parallel edges but doesnt contains
self-loop is a multi-graph
    - null graph: a graph of 'order' and 'size' are 0 is called a null graph;
order = no of vertices, size = no of edges
    - complete graph: a simple graph of n vertices in which each node has (n-1)
edges or 'degree' of each node is (n-1), means we can travel to any vertex with
the help of one vertex in this graph; degree of a vertex = no of edges connected
to that vertex.

3.Based on 'DIRECTION':
    - directed graph: graph with edges having direction such that we cant able
to travel directed side from the vertex to another one.
    - un-directed graph: graph with edges having no direction so that we can
travel to any vertex that is connected to the given vertex.

4.Based on 'WEIGHT':
    - weighted graph: graphs in which edges having weight(number) that
represents cost, time or distance.
    - un-weighted graph: graphs in which edges having no weight and all the
edges are treated equally.

5.Based on 'CONNECTIVITY':
    - connected graph: a graph is said to be connected if there exists atleast
one path b/w each n every pair of nodes (we can travel whole graph with the help
of only one node).
    - disconnected graph: a graph where all nodes are NOT reachable from each
other is called a disconnected graph.
*/

/*
Graph Representation are of mainly 2 types:
1. Adjacency Matrix: for the graph:      0 -- 1
                                         |    |
                                         2 -- 3
    the adjacency matrix is:
                                      0   1   2   3
                         rows:  0 : | 0 | 1 | 1 | 0
                                1 : | 1 | 0 | 0 | 1
                                2 : | 1 | 0 | 0 | 1
                                3 : | 0 | 1 | 1 | 0
2. Adjacency List
*/

int main(void) {

  // adjacency matrix representation of a graph

  int n1 = 4;    // no of nodes

  int matrix1[4][4] = {0};

  // edges
  matrix1[0][1] = 1;
  matrix1[1][0] = 1;

  matrix1[0][2] = 1;
  matrix1[2][0] = 1;

  matrix1[1][3] = 1;
  matrix1[3][1] = 1;

  matrix1[2][3] = 1;
  matrix1[3][2] = 1;

  // print matrix1
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n1; j++) {
      cout << matrix1[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // =======================================================================================================================
  // adjacency list representation of a graph
  /*
          0 : 1 2
          1 : 0 3
          2 : 0 3
          3 : 1 2
  */

  int m = 4;

  vector<vector<int>> List(m);

  // add edges
  List[0].push_back(1);
  List[1].push_back(0);

  List[0].push_back(2);
  List[2].push_back(0);

  List[1].push_back(3);
  List[3].push_back(1);

  List[2].push_back(3);
  List[3].push_back(2);

  // print graph
  for (int i = 0; i < n1; i++) {

    cout << i << " : ";

    for (int neighbor : List[i]) {

      cout << neighbor << " ";
    }

    cout << endl;
  }

  cout << endl;






     /*
     Actual Graph: 

            0
           / \
          1   2
         / \   \
        3---4---5
    */

    /* 
    adjacency matrix:
        0   1   2   3   4   5
    0:  0   1   1   0   0   0
    1:  1   0   0   1   1   0
    2:  1   0   0   0   0   1
    3:  0   1   0   0   1   0
    4:  0   1   0   1   0   1
    5:  0   0   1   0   1   0
    */
    
    
    int n2 = 6;   // no of nodes
    int matrix[6][6] = {0};

    matrix[0][1] = 1;
    matrix[1][0] = 1;
    
    matrix[0][2] = 1;
    matrix[2][0] = 1;
    
    matrix[3][1] = 1;
    matrix[1][3] = 1;
    
    matrix[4][1] = 1;
    matrix[1][4] = 1;

    matrix[4][3] = 1;
    matrix[3][4] = 1;
    
    matrix[4][5] = 1;
    matrix[5][4] = 1;
    
    matrix[5][2] = 1;
    matrix[2][5] = 1;

    // priting
    for(int i = 0; i < n2; i++){
        for(int j = 0; j < n2; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    // adjacency list representation
    
    /* 
    0:  1   2
    1:  0   3   4
    2:  0   5
    3:  1   4
    4:  1   3   5
    5:  2   4
    */
    
    int m2 = 6;
    vector<vector<int>> adjList(m2);

    adjList[0].push_back(1);
    adjList[0].push_back(2);

    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    
    adjList[2].push_back(0);
    adjList[2].push_back(5);
    
    adjList[3].push_back(1);
    adjList[3].push_back(4);

    adjList[4].push_back(1);
    adjList[4].push_back(3);
    adjList[4].push_back(5);

    adjList[5].push_back(2);
    adjList[5].push_back(4);


    for(int i = 0; i < m2; i++){
        cout << i << " : ";

        for(int neighbour : adjList[i]){
            cout << neighbour << " ";
        }
        cout << endl;
    }
    cout << endl;

  return 0;
}
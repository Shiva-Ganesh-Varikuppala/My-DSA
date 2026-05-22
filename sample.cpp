#include<iostream>
#include<vector>
using namespace std;


int main(){

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
    
    
    int n = 6;   // no of nodes
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
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
    
    int m = 6;
    vector<vector<int>> adjList(m);

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


    for(int i = 0; i < m; i++){
        cout << i << " : ";

        for(int neighbour : adjList[i]){
            cout << neighbour << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
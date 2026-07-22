#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  // constructor for intialising variables everytime after creating an obj
  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

Node *buildTree(vector<int>& preorder, int &idx) {
  idx++;

  if (idx >= preorder.size() || preorder[idx] == -1) { // base case
    return NULL;
  }

  Node *root = new Node(preorder[idx]);
  root->left = buildTree(preorder, idx);  // for left
  root->right = buildTree(preorder, idx); // for right

  return root;
}

int main() {

  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, 5, -1, -1};
  int idx = -1;
  Node *root = buildTree(preorder, idx);

  cout << root->data << " ";
  cout << root->left->data << " ";
  cout << root->right->data << " ";

  return 0;
}

  /* 
  In the given preoder '-1' means NULL and first element in the preorder represents the root node and the next follows 
  for the left node then right if any child nodes have its sub-nodes then it will be represented after the given preorder element
  
  Here in the preorder = {1, 2, -1, -1, 3, 4, -1, 5, -1, -1};
  - '1' means the root node
  - '2' means the left to the root node
  - '-1' means the left to the '2' node and other '-1' means the right to the '2' node
  - '3' means the right to the root node
  - '4' means the left to the '3' node
  - '-1' means the left to the '4' node
  - '5' means the right to the '4' node
  - '-1' means the left to the '5' node and otber '-1' means the right to the '5' node
  
  So that's how the tree will be represented with the preorder array
  
  DIAGRAM:
  
  1 -------->(root)
  /     \
  2       3
  / \     / \
  NULL NULL 4  NULL
  / \
  NULL  5
  / \
  NULL NULL
  
  TERMS IN TREE:
  1.Root             : The topmost node of the tree from where we can able to traverse the whole tree(1)
  2.Parent & child   : If a node is connected downward (1 -> parent, 2, 3 -> children)
  3.Leaf Node        : Node with node children (2, 5 -> leaf nodes) 
  4.Internal Node    : Node having atleast one child
  5.Subtree          : Any node + its children forms a subtree (subtree of 3 -> (3, 4, 5))
  6.Height of tree   : Number of edges in longest path from the root to leaf (height = 3) (path: 1->3->4->5, edges: 3,4,5)
  7.Depth of Node    : Distance from root to that node (Depth of 1 = 0, for 3 = 1, for 5 = 3)
  8.Level            : Same as depth but starts from 1 (Level of 1 = 1, for 3 = 2, for 5 = 4)
  9.Degree of Node   : Number of children
  10.Binary Tree     : Each node has atmost 2 children (left n right)
  
  11.Full Binary Tree  : Every node has either 0 or 2 children
  12.Complete Binary Tree : All levels are completely filled except possibly the last, and last level is filled from left
  13.Perfect Binary Tree  : All internal nodes have 2 children and all leaves are at same level
  14.Balanced Tree     : Height difference between left and right subtree is at most 1
  15.Skewed Tree       : Tree where all nodes are either left or right child (like a linked list)
  16.Ancestor          : Any node on the path from root to a given node (for 5 → 1,3,4 are ancestors)
  17.Descendant        : Any node in the subtree of a node (for 3 → 4,5 are descendants)
  18.Sibling           : Nodes having the same parent (2 and 3 are siblings)
  19.Path              : Sequence of nodes from one node to another (1→3→4→5)
  20.Diameter of Tree  : Longest path between any two nodes in the tree
  21.Siblings          : Nodes having the same parent
  */
  
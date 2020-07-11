#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

vector<Node> tree;

bool IsBinarySearchTree(Node p, int min, int max) {
  // Implement correct algorithm here
  if (p.key < min || p.key > max)  
        return false;
  if(p.left == -1 && p.right == -1) return true;
  else if(p.left == -1) return IsBinarySearchTree(tree[p.right], p.key+1, max);
  else if(p.right == -1) return IsBinarySearchTree(tree[p.left], min, p.key-1);
  else return
        IsBinarySearchTree(tree[p.left], min, p.key-1) &&
        IsBinarySearchTree(tree[p.right], p.key+1, max);
}

int main() {
  int nodes;
  cin >> nodes;
  if(nodes == 0){
    cout<<"CORRECT\n";
    return 0;
  }
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree[0], INT_MIN, INT_MAX))
    cout << "CORRECT" << endl;
  else
    cout << "INCORRECT" << endl;
  return 0;
}


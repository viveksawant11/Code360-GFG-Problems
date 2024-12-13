#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> findVertical(Node* root){
    map<int, map<int, multiset<int>>> nodes;			
    // Map automatically keeps elements sorted by the key
    // Multiset - Also stores elements in sorted order, but allows multiple duplicate elements
    
    queue<pair<Node*, pair<int, int>>> todo;
    
    todo.push({root, {0, 0}});
    
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* temp = p.first;
        
        int x = p.second.first;  
        int y = p.second.second; 
        
        nodes[x][y].insert(temp->data);
        
        // Process left child
        if(temp->left){
            todo.push({temp->left,{x-1,y+1}});
        }
        
        // Process right child
        if(temp->right){
            todo.push({temp->right,{x+1,y+1}});
        }
    }
    
    vector<vector<int>> ans;
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());	// col.insert(position, start, end)
        }
        ans.push_back(col);
    }
    return ans;
}

void printResult(const vector<vector<int>>& result) {
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);
    
    vector<vector<int>> verticalTraversal = findVertical(root);

    cout << "Vertical Traversal- " << endl;
    printResult(verticalTraversal);

    return 0;
}

// The insert function is capable of adding a range of elements from another container to the vector in one go. 
// This is particularly useful when you want to append all elements from a container (e.g., a multiset) to 
// the end of the vector. Yes, you could use push_back, but it adds single element, & it would require a
// loop to individually add each element from the multiset to the vector, like this:

// 			for (int value : q.second) {
//   				col.push_back(value);
// 			}
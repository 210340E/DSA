#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// creating a new node
struct node* New_node(int data){
    node* newNode = new node();
    newNode -> key = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

//Find and return the node with minimum key value
struct node* minimum(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL){
        current = current -> left;
    }
    return current;
}   

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root != NULL){
      //traverse left
      traverseInOrder(root -> left);
      //traverse root
      cout << root -> key << " ";
      //traverse right
      traverseInOrder(root -> right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL){
      return New_node(key);
    }
    else if (key < node -> key){
      node -> left = insertNode(node -> left, key);
    }
    else {
      node -> right = insertNode(node->right,key);
    }
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root ==NULL){
        return root;
    }
    if (key < root -> key){
        root -> left = deleteNode(root->left,key);
    }
    else if (key > root -> key){
        root -> right = deleteNode(root->right,key);
    
    }
    else{
        //node has no child
        if (root -> left == NULL and root -> right == NULL){
            return NULL;
        }
        
        //node has only right Child
        else if (root -> left == NULL){
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        
        //node has only left child
        else if (root -> right == NULL){
            struct node* temp = root -> left;
            free(root);
            return temp;
        }
        
        //Node has two children
        else{
            //find the inorder successor
            struct node* temp = minimum(root->right);
            root -> key = temp -> key;
            //delete the inorder successor
            root -> right = deleteNode(root->right, temp -> key);
        }
 
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
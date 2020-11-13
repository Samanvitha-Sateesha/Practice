// C++ program to perform zig zag traversal of binary tree

#include <iostream>
#include <stack>
using namespace std;
struct Node {
   int data;
   struct Node *left, *right;
};
void zigZagTreeTraversal(struct Node* root){
   if (!root)
      return;
   stack<struct Node*> currentlevel;
   stack<struct Node*> nextlevel;
   currentlevel.push(root);
   bool LtR = true;
   while (!currentlevel.empty()) {
      struct Node* temp = currentlevel.top();
      currentlevel.pop();
      if (temp) {
         cout<<temp->data<<"\t";
         if (LtR) {
            if (temp->left)
               nextlevel.push(temp->left);
            if (temp->right)
               nextlevel.push(temp->right);
         }
         else {
            if (temp->right)
               nextlevel.push(temp->right);
            if (temp->left)
               nextlevel.push(temp->left);
         }
      }
      if (currentlevel.empty()) {
         LtR = !LtR;
         swap(currentlevel, nextlevel);
      }
   }
}
struct Node* insertNode(int data){
   struct Node* node = new struct Node;
   node->data = data;
   node->left = node->right = NULL;
   return (node);
}
int main() {
   struct Node* root = insertNode(1);
   root->left = insertNode(2);
   root->right = insertNode(3);
   root->left->left = insertNode(4);
   root->left->right = insertNode(5);
   root->right->left = insertNode(6);
   root->right->right = insertNode(7);
   cout << "ZigZag traversal of the given binary tree is \n";
   zigZagTreeTraversal(root);
   return 0;
}
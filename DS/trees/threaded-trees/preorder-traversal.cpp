//Preorder traversal in Inorder Threaded Binary Search Tree. 
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	struct Node *left, *right; 
	int info; 

	// True if left pointer points to predecessor 
	// in Inorder Traversal 
	bool lthread; 

	// True if right pointer points to predecessor 
	// in Inorder Traversal 
	bool rthread; 
}; 

// Insert a Node in Binary Threaded Tree 
struct Node *insert(struct Node *root, int ikey) 
{ 
	// Searching for a Node with given value 
	Node *ptr = root; 
	Node *par = NULL; // Parent of key to be inserted 
	while (ptr != NULL) 
	{ 
		// If key already exists, return 
		if (ikey == (ptr->info)) 
		{ 
			printf("Duplicate Key !\n"); 
			return root; 
		} 

		par = ptr; // Update parent pointer 

		// Moving on left subtree. 
		if (ikey < ptr->info) 
		{ 
			if (ptr -> lthread == false) 
				ptr = ptr -> left; 
			else
				break; 
		} 

		// Moving on right subtree. 
		else
		{ 
			if (ptr->rthread == false) 
				ptr = ptr -> right; 
			else
				break; 
		} 
	} 

	// Create a new node 
	Node *tmp = new Node; 
	tmp -> info = ikey; 
	tmp -> lthread = true; 
	tmp -> rthread = true; 

	if (par == NULL) 
	{ 
		root = tmp; 
		tmp -> left = NULL; 
		tmp -> right = NULL; 
	} 
	else if (ikey < (par -> info)) 
	{ 
		tmp -> left = par -> left; 
		tmp -> right = par; 
		par -> lthread = false; 
		par -> left = tmp; 
	} 
	else
	{ 
		tmp -> left = par; 
		tmp -> right = par -> right; 
		par -> rthread = false; 
		par -> right = tmp; 
	} 
	return root; 
} 

// Returns inorder successor using rthread 
struct Node *preorderSuccessor(struct Node *ptr) 
{ 
	// If lthread is set, we can quickly find.
	
	if (ptr -> lthread == false) 
		return ptr->left; 

	// Else return rightmost child of right subtree 
	// ptr = ptr -> right; 
	while (ptr -> rthread == true) 
		ptr = ptr -> right; 
	return ptr->right;
} 

// Printing the threaded tree 
void preorder(struct Node *root) 
{ 
	// if (root == NULL) 
	// 	printf("Tree is empty"); 
	// Reach leftmost node 
	cout<<root->info<<" ";
	struct Node *ptr = preorderSuccessor(root); 
	cout<<ptr->info<<" ";
	while (ptr!=root && ptr->right!=NULL){
		ptr = preorderSuccessor(ptr);
		cout<<ptr->info<<" ";	
	} 
} 

// Driver Program 
int main() 
{ 
	struct Node *root = NULL; 
	root = insert(root, 20); 
	root = insert(root, 10); 
	root = insert(root, 30); 
	root = insert(root, 5); 
	root = insert(root, 16); 
	root = insert(root, 14); 
	root = insert(root, 17); 
	root = insert(root, 13); 
	preorder(root); 
	return 0; 
} 

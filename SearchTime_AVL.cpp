/*
    Reference: https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
*/
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

class Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
}; 

int height(Node *N) 
{ 
	if (N == NULL) 
		return 0;
	return N->height;
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

Node* newNode(int key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially 
					// added at leaf 
	return(node); 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	// Return new root 
	return y; 
}
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
}

Node* insertNode(Node* node, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insertNode(node->left, key); 
	else if (key > node->key) 
		node->right = insertNode(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
}

bool searchNode(Node *node, int key){
    if (node == nullptr){
        return false;
    }
    else if (key == node->key){
        return true;
    }
    else if (key < node->key){
        return searchNode(node->left, key);
    }
    else{
        return searchNode(node->right, key);
    }
}

void preOrder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->key << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
}

int main() 
{ 
	int treeSizes[]={10,100,1000,5000,10000,50000,100000};
    cout<<"AVL Tree\n";
    for(int i=0; i<7; ++i){

        Node* root = NULL;
        srand(time(0));

        for(int j=0; j<treeSizes[i]; ++j){
            root = insertNode(root,rand()%(treeSizes[i]+100));
        }

        auto startTime = high_resolution_clock::now();
        for(int k=0; k<100; ++k){
            searchNode(root,rand()%(treeSizes[i]+100));
        }
        auto endTime = high_resolution_clock::now();
        
        auto duration = duration_cast<microseconds>(endTime - startTime);
        cout<<"Time elapsed - "<<treeSizes[i]<<" : "<<duration.count()<<" microseconds\n"<<endl;
    }
	
	return 0; 
}
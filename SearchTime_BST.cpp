#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Node{
    public:
        int key;
        Node *left, *right;

        Node(): left(nullptr),right(nullptr),key(0) {}

};

Node* newNode(int item){
	Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = nullptr;
	return temp;
}

Node* insertNode(Node* node, int key){
	if (node == nullptr)
		return newNode(key);

	if (key < node->key)
		node->left = insertNode(node->left, key);
	else if (key > node->key)
		node->right = insertNode(node->right, key);

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

int main(){
    int treeSizes[]={10,100,1000,5000,10000,50000,100000};
    cout<<"BST Tree\n";

    for(int i=0; i<7; ++i){
        Node* root = nullptr;
        root = insertNode(root, 50);
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
}

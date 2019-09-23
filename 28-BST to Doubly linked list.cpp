#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node* newNode(int data) {
	Node* node= new Node;
	node->data= data; 
	node->left= node->right = NULL; 
	return node;
}

void printInorder(Node* root){
	if(root== NULL) return;
	else{
		if(root->left!=NULL) printInorder(root->left);
		cout<< root->data<<", ";
		if(root->right!=NULL) printInorder(root->right);
	}
	return;
}

void BSTtoDLL(Node* root, Node** head){
	if(root==NULL) return;
	
	static Node* prev=NULL;
	
	BSTtoDLL(root->left, head);
	if(prev == NULL){
		*head= root;
	}
	else{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	
	BSTtoDLL(root->right, head);
	
}

void printDLL(Node * node){
	while(node!=NULL){
		cout<<node->data<<", ";
		node= node->right;
	}
}

int main() {
	
	Node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
    root->right->left->right = newNode(75);
	printInorder(root);
	cout<<endl;
	
	Node *head = NULL;
	BSTtoDLL(root, &head);
	printDLL(head);
	
	return 0;
}
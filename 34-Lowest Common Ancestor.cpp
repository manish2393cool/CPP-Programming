/*
	Lowest Common Ancestor
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

void inorder(Node* temp){
	if(!temp) 
        return;
    cout<<" (";
    inorder(temp->left); 
    cout<<temp->data<< ","; 
    inorder(temp->right); 
    cout<<") ";
} 

Node* getLCA(Node *curr, int A, int B){
	if(curr==NULL) return NULL;
	if(curr->data==A || curr->data==B) return curr;
	
	Node *left  = getLCA(curr->left, A, B);
	Node *right  = getLCA(curr->right, A, B);
	
	if(left!=NULL && right!=NULL) return curr;
	
	if(left==NULL) return right;
	else return left;
	
}

int main() {
	Node *root=new Node(10);
	root->left = new Node(3);
	root->right = new Node(8);
	root->left->left = new Node(9);
	root->left->right = new Node(12);
	root->right->left = new Node(7);
	root->right->right = new Node(2);
	root->left->left->left = new Node(1);
	root->left->left->right = new Node(4);
	inorder(root);
	Node *temp = getLCA(root,1,12);
	cout<<"\n"<<temp->data;
	return 0;
}
#include <iostream>
#include <climits>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

bool isBST(Node *root,Node *&prev){
	if(root==NULL) return true;
	
	if(isBST(root->left,prev)==false)			return false;
	if(prev!=NULL && prev->data >= root->data)	return false;
	prev=root;
	cout<<root->data<<" : ";
	return isBST(root->right,prev);
}


int main() {
	Node *root=new Node(10);
	root->left = new Node(3);
	root->right = new Node(18);
	root->left->left = new Node(1);
	root->left->right = new Node(7);
	root->right->left = new Node(15);
	root->right->right = new Node(19);
	root->left->right->left = new Node(4);
	root->left->right->right = new Node(9);
	//used for inorder traversal
	Node *prev=NULL;
	
	if(isBST(root, prev))
		cout<<"BST";
	else
		cout<<"Not a BST";
	return 0;
}
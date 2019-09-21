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

bool findBST(Node *root,int left_lim,int right_lim){
	if(root==NULL) return true;
	cout<<root->data<<":"<<left_lim<<":"<<right_lim<<endl;
	if(left_lim < root->data && root->data < right_lim){
		return findBST(root->left, left_lim, root->data) && findBST(root->right, root->data, right_lim);
	}
	return false;
}


int main() {
	Node *root=new Node(10);
	root->left = new Node(3);
	root->right = new Node(2);
	root->left->left = new Node(1);
	root->left->right = new Node(7);
	root->right->left = new Node(15);
	root->right->right = new Node(20);
	root->left->right->left = new Node(4);
	root->left->right->right = new Node(9);
	int left_lim=INT_MIN,right_lim=INT_MAX;
	//cout<<left_lim<<":"<<right_lim<<endl;
	if(findBST(root, left_lim, right_lim))
		cout<<"BST";
	else
		cout<<"Not a BST";
	return 0;
}
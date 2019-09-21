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

void levelorder(Node *root, int x){
	queue<Node *> q;
	q.push(root);
	int curr_l=0;
	while(q.empty()==false){
		int count = q.size();
		curr_l+=1;
		for(int i=0;i<count;i++){
			Node *curr=q.front();
			q.pop();
			if(curr_l==x || x==-1)
				cout<<curr->data<<" - ";
			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
		cout<<"\n";
	}
}

int main() {
	Node *root=new Node(10);
	root->left = new Node(3);
	root->right = new Node(8);
	root->left->left = new Node(9);
	root->left->right = new Node(12);
	root->right->left = new Node(7);
	root->right->right = new Node(2);
	root->left->right->left = new Node(1);
	root->left->right->right = new Node(5);
	int x;
	cin>>x;
	levelorder(root,x);
	return 0;
}
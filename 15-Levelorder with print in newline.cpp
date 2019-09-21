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

void levelorder(Node *root){
	queue<Node *> q;
	q.push(root);
	while(q.empty()==false){	
		int count = q.size();
		for(int i=0;i<count;i++){
			Node *curr=q.front();
			q.pop();
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
	levelorder(root);
	return 0;
}
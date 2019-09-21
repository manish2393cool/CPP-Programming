#include <iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;

struct Node{
	char data;
	Node *left,*right;
	Node (char x){
		data=x;
		left=right=NULL;
	}
};

void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int flag=-1;
void printmap(Node *root,int i,int index)
{
	if (root == nullptr)
		return;
	printmap(root->left, i-1, index);
	printmap(root->right, i+1, index);
	if(i==index) { cout<<root->data; flag=1;}
	//cout << root->data << " || "<<i<<endl;
}

stack<Node*> lifo;

Node* createtree(string str,Node *root,int i, int n){
	//cout<<i<<"::::"<<n<<endl;
	Node *temp;
	temp=root;
	if(root!=NULL && i!=0){
		Node* t=lifo.top();
		if (t!=root){
			lifo.push(root);
		}
		// cout<<"i= "<<i<<" root="<<root->data<<endl;
	}
	if(i==n){
		return root;
	}
	if(i==0){
		//cout<<";;1"<<endl;
		root = new Node(str[0]);
		lifo.push(root);
		// cout<<"i= "<<i<<" root="<<root->data<<endl;
		temp = createtree(str,root,i+1,n);
	}
	else{
		if(str[i]=='('){
			//next is root->left
			if(str[i+1]=='.'){
				//left node is NULL
				root->left=NULL;
				temp=createtree(str,root,i+2,n);
			}
			else{
				root->left=new Node(str[i+1]);
				temp=createtree(str,root->left,i+2,n);
			}
		}
		else if(str[i]=='.'){
			if(str[i+1]==')'){
				//right node is NULL return to parent
				root->right=NULL;
				//pop top and send
				lifo.pop();
				Node * temp1=lifo.top();
				temp=createtree(str,temp1,i+2,n);
			}
			else{
				cout<<"wrong entry"<<endl;
			}
		}
		else if(str[i]==')'){
			//pop top and send
			lifo.pop();
			if(lifo.empty()==true){
				return root;
			}
			Node * temp1=lifo.top();
			temp=createtree(str,temp1,i+1,n);
		}
		else{
			root->right=new Node(str[i]);
			temp=createtree(str,root->right,i+1,n);
		}
	}
	return temp;
}



int main() {
	int T,index;
	cin>>T;
	while(T!=0){
		flag=-1;
		cin>>index;
		string ip;
		cin>>ip;
		//cout<<ip<<endl;
		Node* root;
		// cout<<ip.size()<<endl;
		root = createtree(ip,NULL,0,ip.size());
		//cout<<root->data<<endl;
		inorder(root);cout<<endl;
		printmap(root,0,index);
		if(flag==-1) cout<<"Hallelujah!";
		cout<<endl;
		T--;
	}
	return 0;
}
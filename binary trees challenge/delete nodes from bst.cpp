#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*left;
		node*right;
		node(int d)
		{
			data=d;
			left=right=NULL;
		}
		
		
};
node* build(node*root,int d)
{
	
	if(root==NULL)
	{
		return new node(d);
	}
	if(d<=root->data)
	{
		root->left=build(root->left,d);
	}
	else if(d>root->data)
	{
		root->right=build(root->right,d);
	}
	return root;
}

node* deleteinBST(node*root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(data<root->data)
	{
		root->left=deleteinBST(root->left,data);
		return root;
	}
	else if(data==root->data)
	{
		if(root->right==NULL && root->left==NULL)
		{
			delete root;
			return NULL;
		}
		else if(root->right!=NULL && root->left==NULL)
		{
			node*temp=root->right;
			delete root;
			return temp;
		}
		
		else if(root->right==NULL && root->left!=NULL)
		{
			node*temp=root->left;
			delete root;
			return temp;
		}
		node*replace=root->right;
		while(replace->left!=NULL)
		{
			replace=replace->left;
		}
		root->data=replace->data;
		root->right=deleteinBST(root->right,replace->data);
		
		return root;
		
		
		
	}
	else
	{
		root->right=deleteinBST(root->right,data);
		return root;
	}
}
void print(node*root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	node*root=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		root=build(root,arr[i]);
		
	}
	int m;
	cin>>m;
	int del[m];
	for(int i=0;i<m;i++)
	{
		cin>>del[i];
		root=deleteinBST(root,del[i]);
	}
	print(root);
}



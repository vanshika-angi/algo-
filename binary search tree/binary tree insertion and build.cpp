#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class node{
	public:
		int data;
		node*left;
		node*right;
		node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};
node* insertinBST(node* root, int d)
{
	if(root==NULL)
	{
		return new node(d);
	}
	
	if(d<root->data)
	{
		root->left=insertinBST(root->left,d);
	}
	else{
		root->right=insertinBST(root->right,d);
	}
	return root;
}
node* build()
{
	int d;
	cin>>d;
	node*root=NULL;
	while(d!=-1)
	{
		root=insertinBST(root,d);
		cin>>d;
	}
	return root;
}
void bfs(node*root)
{
	queue<node*>q;
	q.push(root );
	q.push(NULL);
	while(!q.empty())
	{
		node*f=q.front();
		if(f==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
			{
				q.push(NULL);
			}
			
		}
		else{
		
		cout<<f->data<<",";
		q.pop();
		if(f->left)
		{
			q.push(f->left);
		}
		if(f->right)
		{
			q.push(f->right);
		}
	}
	}
	return;
}
bool search(node*root,int d)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->data==d)
	{
		return true;
	}
	if(root->data>=d)
	{
		return search(root->left,d);
	}
	else{
		return search(root->right,d);
	}
	
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
bool isBST(node*root,int minV=INT_MIN,int maxV=INT_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->data >=minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV))
	{
		return true;
	}
	return false;
}

int main()
{
	node*root=build();
	bfs(root);
	
	
	return 0;
}

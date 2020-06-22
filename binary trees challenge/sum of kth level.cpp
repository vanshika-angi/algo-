#include<iostream>
using namespace std;

int sum=0;
class node{
	public:
		int data;
		node*left;
		node*right;
		node(int d)
		{
			data=d;
			right=NULL;
			left=NULL;
		}
};

node* build()
{
	int n;
	cin>>n;
	int child;
	cin>>child;
	node*root=new node(n);
	if(child==0)
	{
		return root;
	}
	if(child==1)
	{
		root->left=build();
	}
	if(child==2)
	{
		root->left=build();
		root->right=build();
	}
	
	
	return root;
	
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

int sumkthLevel(node*root,int k)
{
	if(root==NULL)
	{
		return 0;
	}
	if(k==1)
	{
//		cout<<root->data<<" ";
		sum=sum+root->data;
	}
	sumkthLevel(root->left,k-1);
	sumkthLevel(root->right,k-1);
//	cout<<sum;
	return sum;
}

int main()
{
	
	node*root=build();
//	print(root);
	int t;
	cin>>t;
	int k=t+1;
	int v=sumkthLevel(root,k);
	cout<<v;
	
	return 0;
}

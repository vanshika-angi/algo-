#include<iostream>
#include<set>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data=d;
		left=right=NULL;
	}
};
set<int> s;

node* buildbst(node*root,int data){
	if(root==NULL)
	{
		return new node(data);
		
	}
	if(data<root->data)
	{
		root->left=buildbst(root->left,data);
		
	}
	if(data>root->data)
	{
		root->right=buildbst(root->right,data);
		
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
void inorder(node*root,int k1,int k2)
{
	if(root==NULL)
	{
		return;
	}
	if(k1<root->data)
{
inorder(root->left,k1,k2);
}
if(k1<=root->data && k2>=root->data)
{
cout<<root->data<<" ";
}
if(k2>root->data)
{
inorder(root->right,k1,k2);
}
}

int main()
{
	int w;
	cin>>w;
	while(w--)
	{
		int n;
		cin>>n;
		int arr[n];
		node*root=NULL;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			root=buildbst(root,arr[i]);
		}
		
		
		int z1,z2;
		cin>>z1>>z2;
		print(root);
		cout<<endl;
		inorder(root,z1,z2);
		cout<<endl;
//		for( set<int>::iterator it=s.begin();it!=s.end();it++)
//	{
//		cout<<*(it)<<",";
//	}
		
		
		
	}
}

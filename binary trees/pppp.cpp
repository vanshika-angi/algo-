#include<iostream>
#include<queue>
using namespace std;

class node{
	public:
		int data;
		node*left;
		node*right;
		
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};
node* build(string s)
{
	if(s=="true")
	{
		int d;
		cin>>d;
		node*root=new node(d);
		string l;
		cin>>l;
		if(l=="true")
		{
			root->left=build(l);
		}
		string r;
		cin>>r;
		if(r=="true")
		{
			root->right=build(r);
		}
		return root;
	}
	
	
	
}
int height(node*root)
{
	if(root==NULL)
	return 0;
	
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}
void printkthLevelodd(node*root,int k)
{
	
	if(root==NULL)
	{
		return;
	}
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printkthLevelodd(root->left,k-1);
	printkthLevelodd(root->right,k-1);
	return;
}
void printkthLeveleven(node*root,int k)
{
	
	if(root==NULL)
	{
		return;
	}
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printkthLeveleven(root->right,k-1);
	printkthLeveleven(root->left,k-1);
	
	return;
}
void printallLevels(node*root)

{
	int h=height(root);
	for(int i=0;i<=h;i++)
	{
		if(i%2==1)
		printkthLevelodd(root,i);
		else
		printkthLeveleven(root,i);
	}
}

int main()
{
	node*root=build("true");
	printallLevels(root);
	
}

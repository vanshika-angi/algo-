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


void printkthLevel(node*root,int k)
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
	printkthLevel(root->left,k-1);
	printkthLevel(root->right,k-1);
	return;
}
//void printallLevels(node*root)
//
//{
//	int h=height(root);
//	for(int i=0;i<h;i++)
//	{
//		printkthLevel(root,i);
//		cout<<endl;
//	}
//}



int main()
{
	node*root=build("True");
	printkthLevel(root,0);
	
	
	
	
	return 0;
}

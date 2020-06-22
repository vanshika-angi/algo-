#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node*right;
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};

node* createtree(int pre[],int in[],int s,int e)
{
	static int i=0;
	if(s>e)
	{
		return NULL;
	}
	node*root=new node(pre[i]);
	int index=-1;
	for(int j=s;j<=e;j++)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
	}
	i++;
	root->left=createtree(pre,in,0,index-1);
	root->right=createtree(pre,in,index+1,e);
	return root;
}
void print(node*root)
{
	if(root==NULL)
	{
		return;
	}
	if(root->left!=NULL)
	{
		cout<<root->left->data<<"=>";
	}
	else
	{
	cout<<"NULL =>";	
	}
	cout<<" "<<root->data<<" ";
		if(root->right!=NULL)
	{
		cout<<"<="<<root->right->data;
	}
	else
	{
	cout<<"<= END";	
	}
	cout<<endl;
	print(root->left);
	print(root->right);
	
	
}



int main(){
	int n;
	cin>>n;
	int pre[n];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	int m;
	cin>>m;
	int in[m];
	for(int i=0;i<m;i++)
	{
		cin>>in[i];
	}
	node*root=createtree(pre,in,0,n-1);
	 print(root);
}

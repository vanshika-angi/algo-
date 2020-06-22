#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int maxcheck(int arr[],int s,int e);

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
node* build(int arr[],int s,int e)
{

	int i=maxcheck(arr,e,s);

	node* root= new node(arr[i]);
	if(s==e)
	{
		return root;
	}
	root->left=build(arr,s,i-1);
	root->right=build(arr,i+1,e);
	
	return root;
	

}

int maxcheck(int arr[],int s,int e)
{
	int max1=arr[s],maxind=s;
	for(int i=s;i<=e;i++)
	{
		if(arr[i]>max1)
		{
			max1=arr[i];
			maxind=i;
		}
	}
	return maxind;
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
	for(int i=0;i<n;i++)
	{
		cin>>arr[n];
	}
	node*root=build(arr,0,n-1);
//	print(root);
}

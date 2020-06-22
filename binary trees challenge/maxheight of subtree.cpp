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
node* preIno(int *inorder,int * preorder,int s,int e){
    static int i=0;
    //base case
    if(s>e)
        return NULL ;
    //rec
    node *root=new node(preorder[i]);
    int index=-1;
    for(int j=s;j<=e;j++)
        if(inorder[j]==preorder[i])
        {
            index=j;
            break;
        }
    ++i;//moving ahead in preorder array;
    root->left=preIno(inorder,preorder,s,index-1);
    root->right=preIno(inorder,preorder,index+1,e);
    return root;

}
int height(node*root)
{
	if(root==NULL)
	return 0;
	
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}



int main(){
	int n;
	cin>>n;
	int pre[n];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	
	int in[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node*root=preIno(pre,in,0,n-1);
	int x=height(root);
	cout<<x-1;
}

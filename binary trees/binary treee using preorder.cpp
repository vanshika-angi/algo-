#include<iostream>
using namespace std;

class TreeNode{
	public:
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int data){
		this->val=data;
		this->right=NULL;
		this->left=NULL;
	}
	
};
TreeNode* buildtree()
{
	int d;
	cin>>d;
	if(d==-1) return NULL;
	TreeNode* root= new TreeNode(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
	
}
void print(TreeNode*root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->val<<" ";
	print(root->left);
	print(root->right);
}
int main()
{
	TreeNode* root=buildtree();
	print(root);
}

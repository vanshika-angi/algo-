#include<iostream>
using namespace std;
class TreeNode{
	public:
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){	}
	
};
class Custom{
	public:
		bool haskey1;
		bool haskey2;
		TreeNode* node;
};
Custom* helper(TreeNode*root,TreeNode*p,TreeNode*q)
{
	if(root==NULL)return NULL;
	Custom*leftans=helper(root->left,p,q);
	if(leftans!=NULL and leftans->node!=NULL)
	{
		return leftans;
	}
	Custom*rightans=helper(root->right,p,q);
	if(rightans!=NULL and rightans->node!=NULL)
	{
		return rightans;
	}
	Custom* result=new Custom();
	if(leftans!=NULL and rightans!=NULL)
	{
		result->node=root;
		result->haskey1=true;
		result->haskey2=true;
		return result;
	}
	else if(root->val==p->val)
	{
		result->haskey1=true;
		result->haskey2=(leftans)?leftans->haskey2:false or (rightans)?rightans->haskey2:false;
		if(result->haskey1 and result->haskey2)
		{
			result->node=root;
		}
		return result;
	}
	else if(root->val==q->val)
	{
		result->haskey2=true;
		result->haskey1=(leftans)?leftans->haskey1:false or (rightans)?rightans->haskey1:false;
		if(result->haskey1 and result->haskey2)
		{
			result->node=root;
		}
		return result;
	}
	else if(leftans){
		return leftans;
	}
	else if(rightans)
	{
		return rightans;
	}
	return NULL;
}
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode*p,TreeNode*q)
{
	Custom* result=helper(root,p,q);
	if(result==NULL)return NULL;
	else return result->node;
}
int main()
{
	
	return 0;
}

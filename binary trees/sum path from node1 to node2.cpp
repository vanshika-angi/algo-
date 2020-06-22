#include<iostream>
using namespace std;

class TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(x):val(x),left(NULL),right(NULL){
	}
	
};
class Solution{
	int globalMax=INT_MIN;
	int maxpath(TreeNode root)
	{
		if(root==NULL)return 0;
		int ls=maxpath(root->left);
		int rs=maxpath(root->right);
		int cand1=root->val;
		int cand2=ls+root->val;
		int cand3=rs+root->val;
		int cand4=ls+rs+root->val;
		globalMax=max(cand1,max(cand2,max(cand3,max(cand4,globalMax))));
		return max(ls,max(rs,0))+root->val;	
	}
};

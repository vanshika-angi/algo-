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
	TreeNode* prev;
	Treenode* head;
	void b2ll(TreeNode* root)
	{
		if(root==NULL) return;
		b2ll(root->left);
		if(prev==NULL)
		{
			head=root;
		}else{
			root->left=prev;
			prev->right=root;
		}
		prev=root;
		b2ll(root->right);
		
	}
	
};
int main(){
	
	return 0;
}


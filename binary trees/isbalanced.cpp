#include<iostream>
#include<queue>
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
class HBPair{
	public:
		int height;
		bool balance;
		
};
HBPair p;

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
void print(node*root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
void bfs(node*root)
{
	queue<node*>q;
	q.push(root );
	q.push(NULL);
	while(!q.empty())
	{
		node*f=q.front();
		if(f==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
			{
				q.push(NULL);
			}
			
		}
		else{
		
		cout<<f->data<<",";
		q.pop();
		if(f->left)
		{
			q.push(f->left);
		}
		if(f->right)
		{
			q.push(f->right);
		}
	}
	}
	return;
}
HBPair isHeightBalance(node*root)
{
	
	if(root==NULL)
	{
		p.height=0;
		p.balance=true;
		return p;
	}
	
	HBPair left=isHeightBalance(root->left);
	HBPair right=isHeightBalance(root->right);
	p.height=max(left.height,right.height)+1;
	if((left.height-right.height)<=1 &&(left.height-right.height)>=-1 && left.balance && right.balance)
	{
		p.balance=true;
		
	}
	else{
		p.balance=false;
	}
	return p;
}

int main()
{
	node*root=build("true");
//	print(root);
	bfs(root);
	HBPair res=isHeightBalance(root);
	if(res.balance)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}

#include<iostream>
3include<stack>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		stack<int>q;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int span=0;
		for(int i=0;i<n;i++)
		{
			if(s.empty())
			{
				s.push(i);
			}
			else{
				if(arr[i]>arr[s.top()])
				{
				int t=s.top();
				s.pop();
				span=max(span,i-t);
					s.push(i);
				}
			}
		}
		
	}
}

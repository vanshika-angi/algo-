#include<iostream>
using namespace std;


int main()
{
	int n;
	int k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int zero_count=0,max_value=0,max_r=0,max_l=0;
	int l=0,r=0;
	while(r<n)
	{
		if(arr[r]==0)
		{
			zero_count++;
			while(zero_count>k)
			{
				if(arr[l]==0)
				zero_count--;
				
				l++;
			}
		}
		int q=r-l+1;
		if(q>max_value)
		{
			max_value=q;
			max_l=l;
			max_r=r;
		}
		r++;
	}
	cout<<max_value<<endl;
	for(int i=max_l;i<=max_r;i++)
	{
		if(arr[i]==0)
		{
			arr[i]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}

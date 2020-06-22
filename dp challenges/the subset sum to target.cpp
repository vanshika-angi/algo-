#include<iostream>
using namespace std;

int dp[100000][1000000]={-1};
bool maxsum(int*arr,int n,int sum)
{
	if(sum==0)
	{
		return true;
	}
	if(n==0&&sum!=0)
	{
		return false;
	}
	if(dp[n][sum]!=-1)
	{
		return dp[n][sum];
	}
	
	

}

int main()
{
	int n,sum;
	cin>>n>>sum;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(maxsum(arr,n-1,sum))
	cout<<"Yes";
	else
	cout<<"No";
}

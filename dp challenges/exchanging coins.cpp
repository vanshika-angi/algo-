#include<iostream>
using namespace std;

long long int dp[1000000];
long long int gold(long long int n)
{
	if(n<=1000000 && dp[n]!=-1)
	{
		return dp[n];
	}
	if(n<=11)
	{
		dp[n]=n;
		return dp[n];
	}
	long long int ans=max(n,gold(n/2)+gold(n/3)+gold(n/4));
	if(n<=1000000)
	{
		dp[n]=ans;
		return ans;
	}
	return ans;
}
int main()
{
	long long n;
	cin>>n;
	for(int i=0;i<=1000000;i++)
	{
		dp[i]=-1;
	}
	cout<<gold(n);
}

#include<iostream>
using namespace std;

int dp[100000][100000];
int knapsack(int size[],int value[],int n,int s)
{
	for(int i=0;i<=s;i++)
	dp[0][i]=0;
	for(int j=0;j<=n;j++)
	dp[j][0]=0;
	int max2=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			int a=dp[i-1][j];
			if(j-size[i-1]>=0)
			{
				int b=dp[i][j-size[i-1]]+value[i-1];
			dp[i][j]=max(a,b);
			}
			else{
				dp[i][j]=a;
			}
			
			max2=max(max2,dp[i][j]);
			
		}
		
	}
	return max2;
}
int main()
{
	int n;
	cin>>n;
	int s;
	cin>>s;
	int size[n];
	int value[n];
	for(int i=0;i<n;i++)
	{
		cin>>size[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}
	cout<<knapsack(size,value,n,s);
}

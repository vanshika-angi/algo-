#include<iostream>
#include<vector>
#define INF 100000000
#define ll long long
using namespace std;

ll minamount(vector<int>&cost,vector<int>&weight,int n,int w)
{
	ll dp[n+1][w+1];
	for(int i=0;i<=n;i++)dp[i][0]=0;
	for(int j=0;j<=w;j++)dp[0][j]=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			
			if(weight[i-1]>j)dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=min(dp[i-1][j],dp[i][j-weight[i-1]]+cost[i-1]);
			}
		}
	}
	return (dp[n][w]==INF)? -1:dp[n][w];
}
int main()
{
	int n,w;
	cin>>n>>w;
	vector<int>cost;
	vector<int>weight;
	for(int i=0;i<w;i++)
	{
		int q;
		cin>>q;
		if(q!=-1)
		{
			cost.push_back(q);
			weight.push_back(i+1);
		}
		
	}
	cout<<minamount(cost,weight,cost.size(),w);
}

#include<iostream>
using namespace std;

int dp[1000][2];
int count(int t)
{
	int p;
	int sum=0;
for( p=1;p<=t;p++)
{
		if(p==1)
	{
		dp[p][0]=1;
		dp[p][1]=1;
//		cout<<"p:"<<p<<" "<< dp[p][0]<<"-"<<dp[p][1]<<endl;
		sum=2;
	}
	else{
		dp[p][0]=dp[p-1][0]+dp[p-1][1];
		dp[p][1]=dp[p-1][0];
//		cout<<"p:"<<p<<" "<< dp[p][0]<<"-"<<dp[p][1]<<endl;
		sum=dp[p][0]+dp[p][1];
	}
	
}
return sum;
	

}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int p;
		cin>>p;
		
		cout<<count(p)<<endl;
	}
}

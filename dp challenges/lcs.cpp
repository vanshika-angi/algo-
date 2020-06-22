#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int dp[10001][10001]={0};
stack<char> s;
void lcs(char s1[],char s2[])
{
	int m=strlen(s1);
	int n=strlen(s2);
	for(int i=0;i<=m;i++)dp[0][i]=0;
	for(int i=0;i<=n;i++)dp[i][0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int q=0;
			if(s1[i-1]==s2[j-1])
			{
				q=1+dp[i-1][j-1];
				
			}else{
				q=max(dp[i-1][j],dp[i][j-1]);
			}
			dp[i][j]=q;
		}
	
	}
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<dp[i][j];
		}cout<<endl;
	}
		int i=m;
		int j=n;
		int index=dp[m][n];
		char lcs[index+1];
		lcs[index]=' ';
		while(i>0 && j>0)
		{
			if(dp[i][j]==dp[i-1][j])
			{
				i=i-1;
			}
			else if(dp[i][j]==dp[i][j-1])
			{
				j=j-1;
			}
			else{
				lcs[index-1]=s1[i-1];
				i=i-1;
				j=j-1;
				index--;
				
				
				

			}
		}
//		cout<<lcs;
			
	
//	return dp[m][n];
}
int main()
{
	char s1[1000],s2[1000];
	cin>>s1>>s2;
	lcs(s1,s2);
}

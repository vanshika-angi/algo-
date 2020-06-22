#include<iostream>
#include<cstring>
using namespace std;

char dp[1000][1000][1000]={0};
void lcs(char s1[],char s2[],char s3[])
{
	int m=strlen(s1);
	int n=strlen(s2);
	int o=strlen(s3);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=o;k++)
			{
				int q=0;
				if(s1[i-1]==s2[j-1]==s3[k-1])
				{
					q=1+dp[i-1][j-1][k-1];
				}else{
					q=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
				dp[i][j][k]=q;
			}
		}
	}
	cout<<dp[m][n][o];
	int i=m;
	int j=n;
	int k=0;
	int index=dp[i][j][k];
	char result[index+1];
	result[index]=' ';
	while(i>0 && j>0 && k>0)
	{
		if(dp[i][j][k]=dp[i-1][j][k])
		{
			i--;
		}
		else if(dp[i][j][k]=dp[i][j-1][k])
		{
			j--;
		}
		else if(dp[i][j][k]=dp[i][j][k-1])
		k--;
		else{
			result[index-1]=s1[i-1];
			i--;
			k--;
			j--;
			index--;
			
		}
	}
//	cout<<result;
	
}
int main()
{
	char s1[1000],s2[1000],s3[1000];
	cin>>s1>>s2>>s3;
	lcs(s1,s2,s3);
	
}

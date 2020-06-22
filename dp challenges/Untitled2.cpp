#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	int i=0,j=0;
	while(i<n && j<m && i>=0 &&j>=0)
	{
		if(arr[i][j+1]==1)
		{
			j++;
		}
		if(arr[i+1][j]==1)
		{
		}
	}
	
}

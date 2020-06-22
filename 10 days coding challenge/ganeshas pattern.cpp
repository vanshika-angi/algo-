#include<iostream>
using namespace std;

int main()
{
	
	int n;
	cin>>n;
	char arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=' ';
		}
	}
	for(int i=0;i<n;i++)
	{
		arr[n/2][i]='*';
	}
	
	for(int i=0;i<n;i++)
	{
		arr[i][n/2]='*';
	}
	for(int i=0;i<n;i++)
	{
		if(i<n/2)
		{
			arr[i][0]='*';
		}else{
			arr[i][n-1]='*';
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(i<n/2)
		{
			arr[n-1][i]='*';
		}else{
			arr[0][i]='*';
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j];
		}cout<<endl;
	}
}

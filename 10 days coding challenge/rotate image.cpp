#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	int arr2[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
//			arr2[i][j]=arr[n-1-i][i]
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
}

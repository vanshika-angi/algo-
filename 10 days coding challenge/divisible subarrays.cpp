#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int arr2[n]={0};
		long long int sum=0;
		for(int i=0;i<n;i++){
			sum=sum+arr[i];
			arr2[i]=sum;
		}
		long long int arr3[n]={0};
		for(int i=0;i<n;i++)
		{
			arr3[(((arr2[i]%n)+n)%n)]++;	
		}
//		for(int i=0;i<n;i++)
//		{
//			cout<<arr2[i]<<" ";
//		}
//		cout<<endl;
//			for(int i=0;i<n;i++)
//		{
//			cout<<arr3[i]<<" ";
//		}
		long long int result=0;
		for(int i=0;i<n;i++)
		{
			if(arr3[i]>1)
			{
			long long int t=(arr3[i]*(arr3[i]-1))/2;
			result=result+t;	
			}
		}
		result+=arr3[0];
		cout<<result<<endl;;
	}
}

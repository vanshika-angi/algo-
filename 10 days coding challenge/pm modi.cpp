#include<iostream>
using namespace std;

bool check(int n){
	if(n<=1)
	return false;

	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main() {

	int t;
	cin>>t;
	while(t--)
	{
			int a,b;
	cin>>a>>b;
	int count=0;
	for(int i=a;i<=b;i++)
	{
		bool result=check(i);
		if(result)
		{
			count++;
		}
	}
	cout<<count<<endl;
	}
	return 0;
}

#include<iostream>
using namespace std;


int main()
{
	long long int n1,n2;
	cin>>n1>>n2;
	long long min1=min(n1,n2);
	long long int gcd=1;
	for(long long int i=1;i<=min1;i++)
	{
		if(n1%i==0 && n2%i==0)
		{
			gcd=i;
//			cout<<i;
		}
	}
	cout<<gcd<<endl;
}

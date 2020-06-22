#include<iostream>
using namespace std;


int main()
{
	int n,m,s,k;
	cin>>n>>m>>k>>s;
	char arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			while(s>=k)
			{
					if(j==m-1)
			{
                	if(arr[i][j]=='.')
				{
					s=s-2;
                    cout<<s<<"-";
				}
				else if(arr[i][j]=='*')
				{
					s=s+5;
                    cout<<s<<"-";
				}
				else if(arr[i][j]=='#')
				break;
				
			}
			else{
                if(arr[i][j]=='.')
				{
					s=s-3;
                    cout<<s<<"-";
				}
				else if(arr[i][j]=='*')
				{
					s=s+4;
                    cout<<s<<"-";
				}
				else 
				{
					break;
                    // cout<<s<<"-";
				}
			
			}
			}
			
		}
	}
    cout<<endl;
	if(s>=k)
	{
		cout<<"Yes"<<endl;
		cout<<s;
	}else{
		cout<<"No";
	}
}

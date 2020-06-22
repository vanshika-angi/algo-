#include<stack>
#include<iostream>
using namespace std;
void function(stack<int>&s,int n);
int platformsNeeded(int arrival[], int departure[], int n) {
    /*
     * Don't write main().
     * Don't read input, it is passed as function argument.
     * Don't print anything just return integer value.
     */
    stack<int> s;
    int count=0;
    int max1=0;
    int arr[n]={0};
    for(int i=0;i<n;i++)
    {
    	arr[i]=arrival[i];
	}
    for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp  =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	int arr2[n]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i]==arrival[j])
			{
				arr2[i]=departure[j];
			}
		}
		
	}
	for(int i=0;i<n;i++)
	{
		arrival[i]=arr[i];
		departure[i]=arr2[i];
	}
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            s.push(departure[i]);
            
            int t=s.size();
            max1=max(max1,t);
//            cout<<count<<"-"<<departure[i]<<endl;
        }
        
        else if(arrival[i]>=s.top())
        {
            while(!s.empty() && arrival[i]>s.top())
            {
                s.pop();
            }
            s.push(departure[i]);
        }
        else
        {
            if(departure[i]>s.top()){
                 function(s,departure[i]);
            int f=s.size();
            max1=max(max1,f);
            
//            cout<<count<<"-"<<departure[i]<<endl;
            }
               
            else
            {
                s.push(departure[i]);
                int p=s.size();
                max1=max(max1,p);
//                cout<<count<<"-"<<departure[i]<<endl;
            }
        }
    }
    return max1;
}
void function(stack<int>&s,int n)
{
    int x=s.top();
    s.pop();
    if(!s.empty() && n>s.top())
    {
        function(s,n);
    }
    
        s.push(n);
        s.push(x);
        return;
    
}
int main()
{
    int n=4;
    int arr1[]={0310,2329,2358,995};
    int arr2[]={0315 ,2338 ,2359 ,1018};
    int t=platformsNeeded(arr1,arr2,n);
    cout<<t;
    
}


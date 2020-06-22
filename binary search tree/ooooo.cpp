#include<stack>
#include<iostream>
using namespace std;

stack<int> s;
stack<int> s2;
int arr2[1000000];
void print(stack<int>&s);

void Leaders(int* arr,int len)
{
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/
  
    for(long long int i=0;i<len;i++)
    {
        if(s.empty())
        {
            s.push(arr[i]);
        }
        else{
            while(!s.empty()&&[i]>s.top())
            {
                s.pop();
                
            }
            s.push(arr[i]);
            
        }
    }
    print(s);

}

void print(stack< int>&s)
{
    if(s.empty())
    {
        return;
    }
    int g=s.top();
    s.pop();
    print(s);
    cout<<g<<" ";
}
int main()
{
	int len=5;
	int arr[]={13 ,17 ,5 ,4,6};
	Leaders(arr,len);
	
	return 0;
}

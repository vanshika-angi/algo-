#include<iostream>
#include<deque>
#include<cstring >
using namespace std;
int main()
{
	char a[]="abcdefcghijkzyxyz";
	int n=strlen(a);
	int curr_len=1;
	int max_len=1;
	int visited[256];
	for(int i=0;i<256;i++)
	{
		visited[i]=-1;
	}
	 visited[a[0]]=0;
	 for(int i=1;i<n;i++)
	 {
	 	int last_occ=visited[a[i]];
	 	
	 	if(last_occ==-1||i-curr_len>last_occ){
	 		curr_len+=1;
	 		max_len=max(curr_len,max_len);
		 }
		 else{
		 	if(curr_len>max_len){
		 		max_len=curr_len;
			 }
		 	curr_len=i-last_occ;
		 	
		 }
		 visited[a[i]]=i;
	 }
	 cout<<max_len<<endl;
	
	
	return 0;
}

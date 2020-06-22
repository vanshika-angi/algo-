#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<pair<int,int>> s;
	s.insert(make_pair(10,5));
	s.insert(make_pair(13,34));
	s.insert(make_pair(90,8));
	s.erase(s.find(make_pair(13,34)));
	s.insert(make_pair(67,99));
	for(auto p:s)
	{
		cout<<p.first<<"and"<<p.second<<endl;
	}
	
	return 0;
}

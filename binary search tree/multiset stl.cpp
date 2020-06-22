#include<iostream>
#include<set>
using namespace std;

typedef multiset<int>::iterator IT;
int main()
{
	int arr[]={10,20,30,20,10,10};
	multiset<int>m(arr,arr+6);
    m.erase(20);
    m.insert(80);
	for(int x:m)
	{
		cout<<x<<endl;
	}
    cout<<m.count(10);
    auto it=m.find(30);
    cout<<(*it)<<endl;
    pair<IT,IT> range=m.equal_range(30);
    for(auto it=range.first;it!=range.second;it++)
    {
        cout<<*it<<"-";
    }

    for(auto it=m.lower_bound(10);it!=m.upper_bound(77);it++)
    {
        cout<<*it<<"-";
    }

    return 0;
}

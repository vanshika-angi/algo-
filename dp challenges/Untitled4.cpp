#include<iostream>
#include<list>
#include<set>
#include<map>
#include<climits>
using namespace std;

class Graph(){
	map<int,list<pair<int,int> > > m;
	public:
		void add(int x,int y)
		{
			m[x].push_back(make_pair(y,6));
			m[y].push_back(make_pair(x,6));
			
		}
		void dij(int src)
		{
			map<int,int>dist;
			for(auto j:m){
				dist[j.first]=INT_MAX;
			}
			set<pair<int,int> >s;
			dist[src]=0;
			s.insert(make_pair(0,src));
			while(!s.empty()){
				auto p=*(s.begin());
				int node=p.second;
				int nodeD=p.first;
				s.erase(s.begin());
				for(auto child:m[node]){
					if(nodeD+child.second<dist[child.first])
					{
						int dest=child.first;
						auto f=s.find(make_pair(dist[dest],dest));
						if(f!=s.end()){
							s.erase(f);
						}
						dist[dest]=nodeD+child.second;
						s.insert(dist[dest],dest);
					}
				}
				for(auto x:dist)
				{
					if(x,first==INT_MAX ||x.first<0)
					{
						x.first=-1;
						if(x.second!=src)
					{
						cout<<x.first<<" ";
					}
					}
					
				}
			}
		}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Graph g;
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			g.addEdge(x,y);
			
		}
		int src;
		cin>>src
		g.dij(src);
		cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
class edge{
	public:
		int v1;
		int v2;
		int w;
};

bool comparator(edge e1,edge e2){
	return e1.w<e2.w;
}

void Kruskal(edge *edges,int v,int e,vector<edge> *ans){
	int *parent=new int[v];
	for(int i=0;i<v;i++){
		parent[i]=i;
	}
	for(int i=0;i<e;i++){
		if(ans->size()==v-1){
			break;
		}
		int v1=edges[i].v1;
		int v2=edges[i].v2;
		int p1,p2;
		p1=parent[v1];
		p2=parent[v2];
		while(p1!=v1){
			v1=p1;
			p1=parent[v1];
		}
		while(p2!=v2){
			v2=p2;
			p2=parent[v2];
		}
		if(p1==p2){
			continue;
		} else {
			parent[p2]=p1;
			edge myedge;
			if(edges[i].v1<edges[i].v2){
				myedge.v1=edges[i].v1;
				myedge.v2=edges[i].v2;
			} else {
				myedge.v1=edges[i].v2;
				myedge.v2=edges[i].v1;
			}
			myedge.w=edges[i].w;
			ans->push_back(myedge);
		}
	}
}

int main(){
	int v,e;
	cin>>v>>e;
	edge *edges=new edge[e];
	for(int i=0;i<e;i++){
		cin>>edges[i].v1>>edges[i].v2>>edges[i].w;
	}
	sort(edges,edges+e,comparator);
	vector<edge> *ans=new vector<edge>();
	Kruskal(edges,v,e,ans);
	for(auto it=ans->begin();it!=ans->end();it++){
		cout<<it->v1<<" "<<it->v2<<" "<<it->w<<endl;
	}
	return 0;
}

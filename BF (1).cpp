/*#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
const int INF = 1e9;

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;
    cin>>src;
    vector<int> dist(n,INF);
    dist[src]=0;

    for(int iter=0; iter<n-1; iter++){
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        dist[v] = min(dist[v],w+dist[u]);
    }
    }
    for(auto i : dist){
        cout<<i;
        cout<<"\n";
    }
}*/

#include<iostream>
#define MAX 10
using namespace std;

typedef struct edge
{
  int src;
  int dest;
  int wt;
}edge;

void bellman_ford(int nv, edge e[], int src_graph, int ne)
{
  int u,v,weight,i,j=0;
  int dis[MAX];
  
  /* initializing array 'dis' with 999. 999 denotes infinite distance */
  for(i=0;i<nv;i++)
  {
    dis[i]=999;
  }
    
  /* distance of source vertex from source vertex is o */
  dis[src_graph]=0;
  
  /* relaxing all the edges nv - 1 times */
  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].src;
      v=e[j].dest;
      weight=e[j].wt;
    
      if(dis[u]!=999 && dis[u]+weight < dis[v])
      {
        dis[v]=dis[u]+weight;
      }  
    }
    
  }
  
  /* checking if negative cycle is present */
  for(j=0;j<ne;j++)
  {
    u=e[j].src;
    v=e[j].dest;
    weight=e[j].wt;
    
    if(dis[u]+weight < dis[v])
    {
      cout<<"\n\nNEGATIVE CYCLE PRESENT..!!\n";
      return;
    }  
  }
  
  cout<<"\nVertex"<<"  Distance from source";
  for(i=1;i<=nv;i++)
  {
    cout<<"\n"<<i<<"\t"<<dis[i];
  }

}

int main()
{
  int nv,ne,src_graph;
  edge e[MAX];
  
  cout<<"Enter the number of vertices: ";
  cin>>nv;  
  
  /* if you enter no of vertices: 5 then vertices will be 1,2,3,4,5. so while giving input enter source and destination vertex accordingly */
  printf("Enter the source vertex of the graph: ");
  cin>>src_graph;  
  
  cout<<"\nEnter no. of edges: ";
  cin>>ne;
  
  for(int i=0;i<ne;i++)
  {
    cout<<"\nFor edge "<<i+1<<"=>";
    cout<<"\nEnter source vertex :";
    cin>>e[i].src;
    cout<<"Enter destination vertex :";
    cin>>e[i].dest;
    cout<<"Enter weight :";
    cin>>e[i].wt;  
  }
  
  bellman_ford(nv,e,src_graph,ne);
  
  return 0;
}
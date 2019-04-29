#include<iostream>
using namespace std;

int minimum(int *v,int *d, int n)
{
	
	int index;
	int min=9999;
	
	for(int i=0;i<n;i++)
	   {
	   	if(d[i]<min && v[i]==0)
	   	{
	   		min= d[i];
	   		index=i;
	   		
		   }
	   	
	   	
	   }
	   return index;
	
}



int main()
{
	int n_v,n_e,u,v,value;
	
	cout<<"enter the no of vertices and no of edges";
	cin>>n_v>>n_e;
	
	int g[n_v][n_v];
	int parent[n_v];
	int visited[n_v];
	int distance[n_v];
	
	for(int i=0;i<n_v;i++)
	{
		distance[i]=9999;
		parent[i]=0;
		visited[i]=0;
		
	}
	
for(int i=0;i<n_v;i++)
	for(int j=0;j<n_v;j++)
	      g[i][j]=0;
	
	distance[0]=0;
	
	
	
	
	
	
	
	for(int i=0;i<n_e;i++)
	 {
	 	cout<<"enter the u,v,value";
	 	cin>>u>>v>>value;
	 	
	g[u][v]=g[v][u]=value;
	 }
	
cout<<"the g matrix is";
   for(int i=0;i<n_v;i++)
   {
   	cout<<endl;
   	for(int j=0;j<n_v;j++)
	{
	cout<<g[i][j]<<"\t";	
	}
   }
	
	  	
	
	
	
for(int j=0;j<n_v-1;j++)
{
	int v= minimum(visited, distance,n_v);
	      visited[v]=1;
	      
	      cout<<"the "<<j<<"loop run"<<endl;
	      cout<<"the minimum value is"<<v<<endl;
	      
	
	for(int i=0;i<n_v;i++)
	{
		if(g[v][i]!=0 && (distance[i]>g[v][i]) && visited[i]==0)
		{
			distance[i]=g[v][i];
			parent[i]=v;
			
		}
		
		
	}
	
/*	cout<<"the distance matrix is"<<endl;
	for(int i=0;i<n_v;i++)
   cout<<"0 ->"<<i<<" "<<"= "<<distance[i]<<endl;
	
	cout<<"the parent matrix is "<<endl;
	for(int i=0;i<n_v;i++)
   cout<<i<<" "<<"= "<<parent[i]<<endl;*/
	
}
cout<<"***************************************0";
cout<<"\n\n\n\n";
cout<<"the path summary is";
for(int i=0;i<n_v;i++)
   {
   	cout<<" vertex1  "<<" vertex2 "<< " distance ";
   	cout<<i<<" --->"<<parent[i]<<" == "<<distance[i];
   	cout<<endl;
   }


int p,sum;
cout<<"enter -1 to close";
do
{
	sum=0;
	cout<<"enter the destination";
cin>>p;

cout<<"required path"<<p;
sum=sum+distance[p];
	while(p!=0)
{
	p=parent[p];
	sum+=distance[p];
	cout<<"<--"<<p;
	
}
cout<<"total path length "<<sum<<endl;	
	
}while(p!=-1);

	
	return 0;
}
/*enter the no of vertices and no of edges5
6
enter the u,v,value0
1
10
enter the u,v,value0
3
5
enter the u,v,value1
2
3
enter the u,v,value2
3
31
enter the u,v,value1
4
20
enter the u,v,value2
4
22
the g matrix is
0       10      0       5       0
10      0       3       0       20
0       3       0       31      22
5       0       31      0       0
0       20      22      0       0       the 0loop run
the minimum value is0
the 1loop run
the minimum value is3
the 2loop run
the minimum value is1
the 3loop run
the minimum value is2



the path summary is
 vertex1   vertex2  distance
 0 --->0 == 0
 vertex1   vertex2  distance
  1 --->0 == 10
 vertex1   vertex2  distance
  2 --->1 == 3
 vertex1   vertex2  distance
  3 --->0 == 5
 vertex1   vertex2  distance
  4 --->1 == 20
  
enter -1 to closeenter the destination4
required path4<--1<--0
total path length 30

enter the destination2
required path2<--1<--0
total path length 13

enter the destination3
required path3<--0
total path length 5
enter the destination

*/


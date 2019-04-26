#include <iostream>
using namespace std;

int min_distance(int *dis, int *vis, int n_v)
{
	int min_value=9999;
	int v_index;
	
	for(int i=0;i<n_v;i++)
	{
		if(vis[i]==0 && dis[i]<min_value)
		 {
		 	min_value=dis[i];
		 	v_index=i;
		 	
		 }
		
		
	}
	return v_index;
	
	
}



int main() 
{
	int n_v,n_e,v1,v2,value;
	cout<<"\n enter the no of vertices  ";
	cin>>n_v;
	cout<<"\n enter the no of edges ";
	cin>>n_e;
	
	int g[n_v][n_v];
	int distance[n_v],visited[n_v],parent[n_v];
	
	for(int i=0;i<n_v;i++)
	{
		distance[i]=9999;
		visited[i]=0;
		parent[i]=0;
	}
	
	distance[0]=0;
	
	
	for(int i=0;i<n_v;i++)
	{
		for(int j=0;j<n_v;j++)
	  {
	  	g[i][j]=0;
	  }
	     
	}
	      
	         
	
		for(int j=0;j<n_e;j++)
		{
			cout<<"enter the starting vertex, ending vertex and the value ";
			cin>>v1;
			cin>>v2;
			cin>>value;
			
			g[v1][v2]=g[v2][v1]=value;
		}
		
		for(int i=0;i<n_v-1;i++)
		{
			int min= min_distance(distance, visited,n_v);
		
			visited[min]=1;
			
			for(int i=0;i<n_v;i++)
			{
				if(distance[i]>g[min][i]  && g[min][i]!=0&& visited[i]==0)
				{
						distance[i]=g[min][i];
					    parent[i]=min;
				}
			}
		}
		
		int p;
		cout<<"the path summary will be";
		for (int i=0;i<n_v;i++)
cout<<"0 -> "<<i<<" "<<" = "<<distance[i]<<endl;


cout<<"the parent matrix is";
for(int i=0;i<n_v;i++)
   cout<<parent[i]<<endl;
		
		
	cout<<" enter the distination to which you wnat to go "<<endl;
 cin>>p;

 cout<<" Required path is  "<<p;
  while(p!=0)
{
   p=parent[p];
  cout << " <--" << p ;

}
	
	
	
	
	return 0;
}





/* enter the number of vertices 7
 enter the number edges 12
enter the vertices and the vaule of their edge
0
1
3
enter the vertices and the vaule of their edge
0
2
5
enter the vertices and the vaule of their edge
0
3
6
enter the vertices and the vaule of their edge
1
3
2
enter the vertices and the vaule of their edge
2
3
2
enter the vertices and the vaule of their edge
3
5
9
enter the vertices and the vaule of their edge
2
5
3
enter the vertices and the vaule of their edge
2
4
6
enter the vertices and the vaule of their edge
2
6
7
enter the vertices and the vaule of their edge
4
5
5
enter the vertices and the vaule of their edge
4
6
2
enter the vertices and the vaule of their edge
5
6
1

0 -> 0  = 0
0 -> 1  = 3
0 -> 2  = 5
0 -> 3  = 5
0 -> 4  = 11
0 -> 5  = 8
0 -> 6  = 9


0 ->1 = 3
0 ->2 = 2
0 ->3 = 2
0 ->4 = 2
0 ->5 = 3
0 ->6 = 1


0.stop
 1.countinue1
 enter the starting vertes to print the shortest path
1
 Required path is  1 <--0
 total distance of required path is  0
 enter the starting vertes to print the shortest path
5
 Required path is  5 <--2 <--0
 total distance of required path is  0
 enter the starting vertes to print the shortest path
6
 Required path is  6 <--5 <--2 <--0
 total distance of required path is  0
 enter the starting vertes to print the shortest path
4
 Required path is  4 <--2 <--0
 total distance of required path is  0
 enter the starting vertes to print the shortest path

*/


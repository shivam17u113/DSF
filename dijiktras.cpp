// name : shivam parve
// Div: B
// Roll no: 222020
// GR no: 17u113
// assignment shortest path

#include <iostream>

using namespace std;
int mini(int *d,int * visited,int n)
{
    int mvalue=9999, v_index;
 for ( int i=0;i<n;i++ )
 {
   if((d[i] <mvalue) && (visited[i]==0))
       {
                  v_index=i;
        mvalue=d[i];
        }
 }

    return v_index;

}


int main()
{
	
	 int v1,v2,value;
 int e;
    int n;
   cout<<" enter the number of halts or between station ";
    cin>>n;
    cout<<" enter the number roads to reach destination ";
     cin>>e;
    
    int g[n][n];
    int dis[n],visited[n],parent[n];

    for (int i=0;i<n;i++)
    {
        dis[i]=9999;
        
        visited[i]=0;
        parent[i]=0;
        
    }
    dis[0]=0;
    for (int i=0;i<n;i++)
    {
    	for (int j=0;j<n;j++)
            {
            	 g[i][j]=0;
			}
	}
            
        
 for (int i=0;i<e;i++)
 {
    
   cout<<"enter the two stations between root and their distance "<<endl;
     cin>>v1;
	 cin>>v2;
	 cin>>value;
	 
     g[v1][v2]=value;
    g[v2][v1]=value;


 }

    for( int j=0;j<n-1;j++)
 {
        int v = mini (dis,visited,n);
        visited[v]=1;

        for (int i=0;i<n;i++)

      {
           if(g[v][i]!=0)
           if(dis[i]>dis[v]+g[v][i])
             {

            dis[i]=dis[v]+g[v][i];
            parent[i]=v;
             }


      }
    }
    cout<<endl;
    cout<<"\n the path summary will be like this";
for (int i=0;i<n;i++)
cout<<"0 -> "<<i<<" "<<" = "<<dis[i]<<endl;

cout<<endl;
//for (int i=0;i<n;i++)
  //cout<<parent[i]<<"  ";
  int p;
  int ch;
  cout<<"0.stop \n 1.countinue";
  cin>>ch;
  do
  {


 cout<<" enter the distination to which you wnat to go "<<endl;
 cin>>p;




 cout<<" Required path is  "<<p;
  while(p!=0)
{
   p=parent[p];
  cout << " <--" << p ;

}

 
}while(ch!=0);


    return 0;
}



 /*
 enter the number of halts or between station 7
 enter the number roads to reach destination 12
enter the vertices and the vaule of their edge
0
1
3
enter the two stations between root and their distance
0
2
5
enter the two stations between root and their distance
0
3
6
enter the two stations between root and their distance
1
3
2
enter the two stations between root and their distance
2
3
2
enter the two stations between root and their distance
3
5
9
enter the two stations between root and their distance
2
5
3
enter the two stations between root and their distance
2
4
6
enter the two stations between root and their distance
2
6
7
enter the two stations between root and their distance
4
5
5
enter the two stations between root and their distance
4
6
2
enter the two stations between root and their distance
5
6
1

the path summary will be like this
0 -> 0  = 0
0 -> 1  = 3
0 -> 2  = 5
0 -> 3  = 5
0 -> 4  = 11
0 -> 5  = 8
0 -> 6  = 9

0.stop
 1.countinue1

enter the distination to which you wnat to go
5
 Required path is  5 <--2 <--0
 enter the starting vertes to print the shortest path
6
 Required path is  6 <--5 <--2 <--0

 enter the starting vertes to print the shortest path
4
 Required path is  4 <--2 <--0

 enter the starting vertes to print the shortest path
*/

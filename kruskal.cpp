#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
 {
 	int n_v,n_e,v1,v2,value,k=0;
	cout<<"\n enter the no of vertices  ";
	cin>>n_v;
	cout<<"\n enter the no of edges ";
	cin>>n_e;
	
	int g[n_v][n_v];
	int distance[n_v],visited[n_v],parent[n_v];
	
	int sort_arr[n_v];
	
	for(int i=0;i<n_v;i++)
	{
		distance[i]=0;
		visited[i]=0;
	//	parent[i]=0;
		sort_arr[i]=0;
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
			
			g[v1][v2]=value;
		}
		
		cout<<"the given mateix is";
		for(int i=0;i<n_v;i++)
	{ 
	   cout<<endl;
		for(int j=0;j<n_v;j++)
	  {
	  	cout<<g[i][j];
	  	cout<<"  ";
	  }
	     
	}
		cout<<endl;
		
 	 k=0;
 	for(int i=0; i<n_v;i++)
	 {
	 	for(int j=0;j<n_v;j++)
	 	{
	 		if(g[i][j]!=0)
                            {
                 	sort_arr[k]=g[i][j];
                 	cout<<sort_arr[k]<<endl;
                 	  k++;
                 	
                 	
							  }	 		
		   }
	 	
		 }	
 	
 	cout<<"\n \n before sort";
 	for(int i=0;i<k;i++)
 	{
 		cout<<sort_arr[i];
 		cout<<endl;
 		
	 }
 	
 
 for(int i=0;i<k;i++)
 {
  for(int j=0;j<k;j++)
  {
  	
  	if(sort_arr[i]<sort_arr[j])
  	   {
  	   	int temp;
  	   	temp=sort_arr[i];
  	   	sort_arr[i]=sort_arr[j];
  	   	sort_arr[j]=temp;
			}   
  	
 	
 }
 }
 
 
 	cout<<"\n \n after sort";
 	for(int i=0;i<k;i++)
 	{
 		cout<<sort_arr[i];
 		cout<<endl;
 		
	 }
 	
 	int m=0;
for(int i=0;i<n_v;i++)
 	{
 		
 		for(int j=0;j<n_v;j++)
 		{
 			
 			if(g[i][j]==sort_arr[m])
                  {
              	if(visited[j]==0)
              	{
              		distance[m]=sort_arr[m];
              		m++;
              		visited[j]=1;
              		cout<<" the distance matrix "<<distance[m]<<endl;
              		
              		
				  }
              	
						   } 			
 			
		 }
 		
 		
 		
 		
	 }
	 cout<<" the distancr"<<endl;
	 for(int i=0;i<k;i++)
 	{
 		cout<<distance[i];
 		
 		
	 }
	 
 	
 	int sum=0;
 	for(int i=0;i<m;i++)
 	{
 		sum=distance[i]+sum;
 		
 		
	}
 	cout<<"the minimum ditance is "<<sum;
 	
 	return 0;
 }
 
 
 
 
 
 
 
 
 	
 	
 	
 	
	

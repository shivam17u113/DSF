#include<iostream>
using namespace std;


class hash
{
private:
	
	int key,value;
	int index;
 int n;
 
public:
	
	int occ[100];
	int data[100];
hash()
   {
   	cout<<"enter the no of elements ";
cin>>n;
	

   	key=0;

	for(int i=0;i<=n;i++)
	{
		occ[i]=0;
		data[i]=-1;
	}
	
	}
	
void insert()
	{
		
		for(int i=0;i<n;i++)
		{
			cout<<"enter the next value";
			cin>>value;
			
			
			
			key=(value)%n;
			
			if(occ[key]==0)
			  {
			  	data[key]=value;
			  	occ[key]=1;
			  	
			  }
			  else if(occ[key]==1)
			  {
			  	
			  	for(int j=1;j<=n;j++)
			  	{
			  			key=(value+j)%n;
			  			
			 	if(occ[key]==0)
			  {
			  	data[key]=value;
			  	occ[key]=1;
			  	break;
			  	
        }
			  		
	 }
			  	
     } 
			
	}
		
		
		
			
		}
		
	void display()
		{
				cout<<"\t\t\tIndex "<<"\t\tKey\n";
	for(int i=0;i<10;i++)
	cout<<"\t\t\t"<<i<<"\t\t"<<data[i]<<"\n";

			
	}	
		
void delete1()
{
	int count=0;
	int del;
	cout<<"enter the key to be deleted";
	cin>>del;
	
  for(int i=0;i<=n;i++)
  {
  	if(data[i]==del)
  	{
  		count++;
  		data[i]=-1;
  		occ[i]=0;
  		cout<<"deleted data"<<del<<endl;
  		break;
  		
	  }
  	
	  }	
	
	if(count==0)
	  cout<<"data ot found";
	
}

void search()
{
	
	int search;
	cout<<"\n\n\tEnter Key to be Searched ";
	cin>>search;
	
	for(int i=0;i<n;i++)
	{
	if(data[i]==search)
	{
		cout<<"\n\t\t"<<search<<" Found at Index "<<i<<"\n";	
	}
	}
	
}
	
};


int main()
{
	
	
	int ch;
		hash h1;
	
	do
	{
		cout<<"1.insert\n 2. delete\n 3. display \n 4. find\n 0.EXIT";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				h1.insert();
				break;
				
				case 2:
				h1.delete1();
				cout<<endl;
				break;	
			case 3:
					h1.display();
	               break;
	               case 4:
	               	h1.search();
	               	break;
	               	default :
	               		cout<<"enter the crrect option";
			
		}
		
		
		
	}while(ch!=0);

	

	
return 0;
	
	
}

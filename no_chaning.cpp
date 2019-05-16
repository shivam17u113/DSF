#include<iostream>
#include<string>
using namespace std;

class node
{
int key ;
string value;
public:
friend class list;
};
class list
{
node* g[100];
int n, k;
string v;

public:
list()
{
cout<<"enter the size of table    ";  cin>>n;

	for(int i=0;i<n;i++)
	{
	g[i]=new node;
        g[i]->key=i;
        g[i]->value="NULL";
	}
}

int count()
{
int count1=0;
int i=0;

while(v[i]!='\0')
{
count1=count1+v[i];
i++;
}
return count1;
}
void accept()
{
cout<<"enter the value  "; cin>>v;
int total=0;

total=count();

k=total%n;


if(g[k]->value=="NULL")
{
g[k]->value=v;
return ;
}
else
 {
for(int i=0;i<n;i++)
   {
       k= (total+i)%n;
		if(g[k]->value=="NULL")
		{
		g[k]->value=v;
		return ;
		}
        }
   }
}

void display()
{
       cout<<"key   "<<"\t "<<"value"<<endl;
	for(int i=0;i<n;i++)
	{
	cout<<g[i]->key<<"\t "<<g[i]->value<<endl;
	}
}

int return_n()
{
return n;
}
void update()
{
cout<<"value to be updated ";
cin>>v;
for(int i=0;i<n;i++)
  {
		if(g[i]->value==v)
		{
		cout<<"new value  ";
		cin>>g[i]->value;
		return ;

		}
   }
cout<<"value not found  ";
return ;
}

void delete_value()
{

cout<<"value to be deleted  "; cin>>v;

for(int i=0;i<n;i++)
    {
		if(g[i]->value==v)
		{
		cout<<"value is deleted successfully   ";
		g[i]->value ="NULL";
                  return ;
		}
   }
cout<<"the value not found  ";
return ;

}

};


int main()
{
int ch,count=0,n;
list l;

n=l.return_n();

do
{
cout<<"\n 1. insert \n 2. display  \n3.update \n 4.delete\n  0.exit";
cin>>ch;

switch(ch)
{
case 1:
if(count==n)
cout<<"\n\n table is full \n\n";
else
{
l.accept();
count++;
}
break;

case 2:
l.display();
break;

case 3:
l.update();
break;

case 4:
l.delete_value();
break;
}



}while(ch!=0);



return 0;
}



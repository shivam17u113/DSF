#include<iostream>
using namespace std;

class node
{
int data;
node *next;

public:
friend class list;
node()
{
next=NULL;
data=-1;

}
};
class list
{
node *g[100];
int key,value,n;
public:
list()
{
cout<<"entr the size of table  ";
cin>>n;

for(int i=0;i<n;i++)
  g[i]=NULL;

}

void accept()
  {
cout<<"enter the value ";
cin>>value;

key=value%n;
node *newnode = new node;
newnode->data=value;
newnode->next=NULL;

		if(g[key]==NULL)
		{
		g[key]=newnode;

		}
	else
	{
	node*move=g[key];
	newnode->next=g[key];
	g[key]=newnode;

	}
   }
void search()
{
cout<<"enter the value to be searched  ";
cin>>value;
key=value%n;

node*move=g[key];

while(move!=NULL)
 {
	if(move->data==value)
	{
	cout<<"value found !!!";
	return ;
	}
  move=move->next;
 }
cout<<"value not found  !!!";
return ;
}
void delete_value()
{
int v,k;
cout<<"enter the data to be deleted  ";
cin>>v;
k=v%n;

if(g[k]->data==v)
{
node *move=g[k];
g[k]=g[k]->next;
delete move;
}
else if(g[k]->data!=v)
{
node *temp,*move;
move=g[key];
while(move!=NULL && move->data!=v)
{
temp=move;
move=move->next;

}
temp->next=move->next;
move->next=NULL;
delete move;

}

}
void display()
{
node *move;
for(int i=0;i<n;i++)
  {
       move=g[i];
		while(move!=NULL)
		{
		cout<<move->data<<"\t";
		move=move->next;
		}
   cout<<endl;
     }
 }

int returnn()
{
return n;
}
};


int main()
{
int ch,n,count=0;
list l;
n=l.returnn();
do{
cout<<"\n 1.insert \n 2.display \n3.delete\n 4.search\n0.exit";
cin>>ch;
switch(ch)
{
case 1:
 if(count!=n)
{
l.accept();
count++;
}
	else
	{
	cout<<"\n\ntable is full\n\n";
	}
break;

case 2:
l.display();
break;

case 3:
l.delete_value();
break;

case 4:
l.search();
break;

}

}while(ch!=0);


return 0;
}

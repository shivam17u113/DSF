#include <iostream>

using namespace std;
void max_heapify(int *arr, int i, int n)
{
    int largest=i;
    int l=2*i;
    int r=l+1;
    
    if(l>n && arr[l]> arr[largest])
        largest=l;
        
        
       
    if(r>n && arr[r]> arr[largest])
        largest=r;  
    
    if(largest!=i)
    {
    	swap(arr[i],arr[largest]);
    	
    	max_heapify(arr,largest,n);
    	
	}
       
       
    
    
    
}


void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
	
	
}
void build_maxheap(int *a,int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a,i,n);
    }
}


void sort( int * a, int n)
{
	int size= n;
	
	for(int i=n;i>=1;i--)
	{
		int last= a[i];
	int	first=a[1];
		a[i]=a[1];
		a[1]=last;
		
		size--;
		max_heapify(a,1,size);
		
	}

	
}
int main()
{
    int n, i, x;
    cout<<"enter no of elements of array\n";
    cin>>n;
    int a[20];
    for (i = 1; i <= n; i++)
    {
        cout<<"enter element"<<(i)<<endl;
        cin>>a[i];
    }
    build_maxheap(a,n);
    cout<<"Max Heap\n";
    
    
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
    
    cout<<"sorted"<<endl;
    
    sort(a,n);
    
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
    

}

#include <iostream>
#include <conio.h>

using namespace std;

int n,m;



struct node
{
    int info;
    struct node *link;
	    
}*top1,*top2,*top3;
 

class stack_list
{
    public:
        node *push(node *, int);
        void traverse(node *,int );
        void traverse2(node *,int );
        void traverse3(node *,int );
                    
} a,b,c;


node *stack_list::push(node *top, int item)
{
    node *tmp;
    tmp = new (struct node);
    tmp->info = item;
    tmp->link = top;
    top = tmp;
    return top;
}
 
 

void stack_list::traverse(node *top, int query)
{   
    
    node *ptr;
    ptr = top;
    int f=0;
    
    if (top == NULL)
        return;
    
	else
    {
    	
        while (ptr != NULL && f==0)
        {
            if (ptr->info >=query) 
				{
					f=1;
					ptr->info-=query;
					if (ptr->info !=0) cout<<ptr->info<<endl;
					ptr=ptr->link;
					break;
				}
				
				
			else
				{
					if (ptr->info !=0) cout<<ptr->info<<endl;
					ptr=ptr->link;
				}
        }
        
        while (ptr!=NULL)
        	{
        		if (ptr->info !=0) cout<<ptr->info<<endl;
        		ptr=ptr->link;
			}
			
		if (f==0) cout<<"Length not available."<<endl;
    }
}

void stack_list::traverse2(node *top, int query)
{   
    
    node *ptr;
    ptr = top;
    int f=0;
    
    int diff=32567;
    
    if (ptr == NULL)
        return;
    
	else
    {
    	
        while (ptr != NULL)
        {
            if (ptr->info >=query) 
				{
					f=1;
					int tmp=(ptr->info)-query;
					if (tmp<diff)
					diff=tmp;
					ptr=ptr->link;
				}
				
			else
				{
					ptr=ptr->link;
				}
        }
        
        ptr=top;
        
        while (ptr!=NULL)
        	{
        		if (ptr->info >=query && (ptr->info)-query==diff)
        			{
        				ptr->info=diff;
        				if (ptr->info !=0) cout<<ptr->info<<endl;
        				ptr=ptr->link;
					}
					
				else
					{
						if (ptr->info !=0) cout<<ptr->info<<endl;
						ptr=ptr->link;
					}
			}
			
		if (f==0) cout<<"Length not available."<<endl;
    }
}

void stack_list::traverse3(node *top, int query)
{   
    
    node *ptr;
    ptr = top;
    int f=0;
    
    int max=ptr->info;
    
    if (ptr == NULL)
        return;
    
	else
    {
    	
        while (ptr != NULL)
        {
            if ((ptr->info)>max)
            max=ptr->info;
            
            ptr=ptr->link;
        }
        
        ptr=top;
        
        while (ptr!=NULL)
        	{
        		if ( (ptr->info) == max && query<max)
        			{
        				f=1;
					ptr->info-=query;
        				if (ptr->info !=0) cout<<ptr->info<<endl;
        				ptr=ptr->link;
					}
					
				else 
					{
						if (ptr->info !=0) cout<<ptr->info<<endl;
						ptr=ptr->link;
					}
					
				
			}
			
		if (f==0) cout<<"Length not available."<<endl;
    }
}



int main ()
{
	top1=NULL; top2=NULL; top3=NULL;
	
	cout<<"Enter no. of cloth pieces available: "; cin>>n;
	cout<<"Enter length of the pieces: ";
	for (int i=0; i<n; i++)
		{
			int temp; cin>>temp;
			top1=a.push(top1,temp);
			top2=b.push(top2,temp);
			top3=c.push(top3,temp);
		}
		
			
	cout<<"\nEnter no. of queries: ";	cin>>m;
	
	int q[m];
	cout<<"Enter the queries: ";
	for (int i=0; i<m; i++)
		cin>>q[i];
		
	int t=0;
	
	
	cout<<"\nDemand first:"<<endl<<endl;
	while (t<m)
	{
		int query=q[t];
		cout<<"Stack from topmost after "<<t+1 <<" query :" <<endl;
		a.traverse(top1,query);
		t++;
	}
	
	
	t=0;
	cout<<"\n\nBest fit:"<<endl<<endl;
	while (t<m)
	{
		int query=q[t];
		cout<<"Stack from topmost after "<<t+1 <<" query :" <<endl;
		b.traverse2(top2,query);
		t++;
		
	}
	
	t=0;
	cout<<"\n\nWorst fit:"<<endl<<endl;
	while (t<m)
	{
		int query=q[t];
		cout<<"Stack from topmost after "<<t+1 <<" query :" <<endl;
		c.traverse3(top3,query);
		t++;
	}
		
	
	return 0;	
}

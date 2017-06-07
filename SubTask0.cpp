#include <iostream>
#include <conio.h>

using namespace std;

int n,m;


													// struct for a node of the stack
struct node
{
    int info;
    struct node *link;
	    
}*top1,*top2,*top3;
 

class stack_list									// class for the stack
{
    public:
        node *push(node *, int);
        void demandfirst(node *,int );
        void bestfit(node *,int );
        void worstfit(node *,int );
                    
} a,b,c;


node *stack_list::push(node *top, int item)			// method to push the elements into the stack
{
    node *tmp;
    tmp = new (struct node);
    tmp->info = item;
    tmp->link = top;
    top = tmp;
    return top;
}
 
 

void stack_list::demandfirst(node *top, int query)	// method to implement demand first
{   
    
    node *ptr;
    ptr = top;
    int f=0;
    
    if (top == NULL)								// if no element present, return
        return;
    
	else
    {
    	
        while (ptr != NULL && f==0)					// run the loop till ptr is empty or demand is not found
        {
            if (ptr->info >=query) 					// if demand is found
				{
					f=1;	
					ptr->info-=query;				// new length after cutting the cloth
					if (ptr->info!=0) cout<<ptr->info<<endl;
					ptr=ptr->link;
					break;
				}
				
				
			else									// just print the element in the stack
				{
					if (ptr->info!=0) cout<<ptr->info<<endl;
					ptr=ptr->link;
				}
        }
        
        while (ptr!=NULL)							// to print the rest of the elements in the stack
        	{										// if required length is found
        		if (ptr->info!=0) cout<<ptr->info<<endl;
        		ptr=ptr->link;
			}
			
		if (f==0) cout<<"Length not available."<<endl;		
    }
}

void stack_list::bestfit(node *top, int query)		// method to implement bestfit
{   
    
    node *ptr;
    ptr = top;
    int f=0;
    
    int diff=2147483647;							// assigning diff with the maximum integer value (4 bytes)
    
    if (ptr == NULL)
        return;
    
	else
    {
    	
        while (ptr != NULL)							// iterating through the entire stack
        {
            if (ptr->info >=query) 
				{
					f=1;
					int tmp=(ptr->info)-query;
					if (tmp<diff)					// if tmp is lesser than diff, diff=tmp
					diff=tmp;
					ptr=ptr->link;
				}
				
			else
				{
					ptr=ptr->link;
				}
        }
        
        ptr=top;									// to print the elements from the top
        
        while (ptr!=NULL)
        	{
        		if ((ptr->info)-query==diff)		// to find the element which best fits the required element
        			{
        				ptr->info=diff;
        				if (ptr->info!=0) cout<<ptr->info<<endl;
        				ptr=ptr->link;
        				break;
					}
					
				else								// to print the element in the stack
					{
						if (ptr->info!=0) cout<<ptr->info<<endl;
						ptr=ptr->link;
					}
			}
		
			while (ptr!=NULL)						// to print the rest of the elements in the stack
        	{										// if required length is found
        		if (ptr->info!=0) cout<<ptr->info<<endl;
        		ptr=ptr->link;
			}
			
		if (f==0) cout<<"Length not available."<<endl;
    }
}

void stack_list::worstfit(node *top, int query)		// method to implement worst fit
{   
    
    node *ptr;
    ptr = top;
    int f=0;
    
    int max=ptr->info;								// arbitrarily asssigning maximum element
    												// as the first element
    if (ptr == NULL)
        return;
    
	else
    {
    	
        while (ptr != NULL)							// iterating through the loop
        {
            if ((ptr->info)>max)					// if current element is greater than the maximum 
            max=ptr->info;							// element found so far
            
            ptr=ptr->link;
        }
        
        ptr=top;									// to iterate from the top of the stack
        
        while (ptr!=NULL)
        	{
        		if ( (ptr->info) == max && query<max)	// if the reqd element is found
        			{									// and also query is lesser than the max. element
        				f=1;
						ptr->info-=query;				// changing the length
        				if (ptr->info!=0) cout<<ptr->info<<endl;
        				ptr=ptr->link;
					}
					
				else 									// print the elements of the stack
					{
						if (ptr->info!=0) cout<<ptr->info<<endl;
						ptr=ptr->link;
					}
					
				
			}
			
		if (f==0) cout<<"Length not available."<<endl;
    }
}



int main ()
{
	top1=NULL; top2=NULL; top3=NULL;					// 3 top values for 3 stacks
	
	cout<<"Enter no. of cloth pieces available: "; cin>>n;
	cout<<"Enter length of the pieces: ";
	for (int i=0; i<n; i++)								// input stack values and push it
		{												// to the 3 stacks
			int temp; cin>>temp;
			top1=a.push(top1,temp);
			top2=b.push(top2,temp);
			top3=c.push(top3,temp);
		}
		
			
	cout<<"\nEnter no. of queries: ";	cin>>m;
	
	int q[m];
	cout<<"Enter the queries: ";
	for (int i=0; i<m; i++)								// input the queries
		cin>>q[i];
		
	int t=0;
	
	
	cout<<"\nDemand first:"<<endl<<endl;				// implementing demand first 
	while (t<m)											// for every query
	{
		int query=q[t];
		cout<<"Stack from topmost after "<<t+1 <<" query :" <<endl;
		a.demandfirst(top1,query);
		t++;
	}
	
	
	t=0;
	cout<<"\n\nBest fit:"<<endl<<endl;					// implementing best fit
	while (t<m)											// for every query
	{
		int query=q[t];
		cout<<"Stack from topmost after "<<t+1 <<" query :" <<endl;
		b.bestfit(top2,query);
		t++;
		
	}
	
	t=0;
	cout<<"\n\nWorst fit:"<<endl<<endl;					// implementing worst fit
	while (t<m)											// for every query
	{
		int query=q[t];
		cout<<"Stack from topmost after "<<t+1 <<" query :" <<endl;
		c.worstfit(top3,query);
		t++;
	}
		
	
	return 0;	
}

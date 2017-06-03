#include <iostream>
#include <conio.h>

using namespace std;

class customer
{
	public:
		int cid;
		int at;
		int dt;
		int tr;
		int pr;
		int ta;
};

int main ()
{
	int n;
	customer c[100];
	int k;
	
	cout<<"Enter no. of customers: "; cin>>n;
	
	cout<<"Enter the customr ids: ";
	for (int i=0; i<n; i++)
		cin>>c[i].cid;
	
	
	cout<<"Enter the arrival times of the customers: ";
	for (int i=0; i<n; i++)
		cin>>c[i].at;
		
	cout<<"Enter the estimated time required for each customer: ";
	for (int i=0; i<n; i++)
		cin>>c[i].tr;
		
	cout<<"Enter the priority for each customer: ";
	for (int i=0; i<n; i++)
		cin>>c[i].pr;
		
	cout<<"Enter the value of k: ";
	cin>>k;
	
	{
   		int i, j;
   
   		for (i = 0; i < n-1; i++)      
		 	for (j = 0; j < n-i-1; j++) 
           		if (c[j].at > c[j+1].at)
            	{
            	customer temp=c[j];
            	c[j]=c[j+1];
            	c[j+1]=temp;
				}
	}
	
	
	
	int t=0;
	
	for (int i=0; i<n; i++)
		{
			t+=c[i].tr;
			c[i].dt=t;
			c[i].ta=c[i].dt-c[i].at;
		}
		
		cout<<"\nTurnaround time:\n";
		for (int i=0; i<n; i++)
			cout<<"Customer "<<c[i].cid<<": "<<c[i].dt<<"-"<<c[i].at<<" = "<<c[i].ta<<endl;
		
		
	
	
	
	
	
}

#include<iostream>
using namespace std;
const int n = 3;		


template<class T>
void swap(T *a,T *b){
	T temp=*a;
	*a=*b;
	*b=temp;
}

class item
{
	public:
		char name;
		int value;
		int weight;	
};

void print_normal_array(item items[n] );		//function declaration
void sortItem(item items[n], int a);

void print_array(item items[n] , float ValuePerWeight[n] )
{
	int i;
	cout<<"ITEM NAME      :   ";
	for(i=0;i<n;i++)
		cout<<items[i].name<<"       ";
	cout<<"\nWEIGHT         :   ";
	for(i=0;i<n;i++)
		cout<<items[i].weight<<"      ";
	cout<<"\nVALUE          :   ";
	for(i=0;i<n;i++)
		cout<<items[i].value<<"     ";
	cout<<"\nValuePerWeight :   "; 
	for(i=0;i<n;i++)
		cout<<ValuePerWeight[i]<<"       ";
		
}

void sortItems(item items[n], float ValuePerWeight[n])		//selection sort
{
	for(int i=0;i<n-1;i++)
	{	int max_index = i;
		for(int j=i;j<n;j++)
		{	if(ValuePerWeight[j] > ValuePerWeight[max_index] )
				max_index = j;
		}
		swap(ValuePerWeight[i], ValuePerWeight[max_index]);
		swap(items[i], items[max_index]);
	}	
}

void start_work(item items[n], float ValuePerWeight[n])
{	int unit,ans=0;
	int W = 30;		//maximum weight bag can handle
	cout<<"\nWe take ";
	for(int i=0;i<n;i++)
	{
//		if(W < items[i].weight)					//*************		if we cant cut item    ****************************
//		{	break;	}
		unit = (W>=items[i].weight) ? items[i].weight : W;
		cout<<unit<<" units of item "<<items[i].name<<"   ";
		ans = ans + ( unit*ValuePerWeight[i] );
		if(unit==W)
			{		break;		}
		else
			{ 	W = W - unit;		}
	}
	cout<<"\n\nOur profit in this case is  :  "<<ans;
}

int main()
{
	int i;
	item items[] = { {'A',1500,10}, {'B',1202,90}, {'C',1900,30} };
	cout<<"-----------     GIVEN ITEMS LIST    -------------------\n";
	print_normal_array(items);
	
	float ValuePerWeight[n] ;

	cout<<"\n\n  PREFFERRING WEIGHT OVER VALUE  \n";
	sortItem(items,1);
		for(i=0;i<n;i++)
	 		ValuePerWeight[i] = items[i].value / items[i].weight ;
	print_normal_array(items);
	start_work(items,ValuePerWeight);
	
	cout<<"\n\n  PREFERRING VALUE OVER WEIGHT \n";
	sortItem(items,2);
		for(i=0;i<n;i++)
	 		ValuePerWeight[i] = items[i].value / items[i].weight ;
	print_normal_array(items);
	start_work(items,ValuePerWeight);

	cout<<"\n\n  TAKING RATIO OF BOTH  \n";
	sortItems(items,ValuePerWeight);
		for(i=0;i<n;i++)
	 		ValuePerWeight[i] = items[i].value / items[i].weight ;
	print_array(items,ValuePerWeight);
	start_work(items,ValuePerWeight);

cout<<"\n\n";	
}

void print_normal_array(item items[n] )
{
	int i;
	cout<<"ITEM NAME      :   ";
	for(i=0;i<n;i++)
		cout<<items[i].name<<"       ";
	cout<<"\nWEIGHT         :   ";
	for(i=0;i<n;i++)
		cout<<items[i].weight<<"      ";
	cout<<"\nVALUE          :   ";
	for(i=0;i<n;i++)
		cout<<items[i].value<<"     ";
}
void sortItem(item items[n], int a)		//selection sort
{
	for(int i=0;i<n-1;i++)
	{	int max_index = i;
		for(int j=i;j<n;j++)
		{	if(a==1)
				{if( items[j].weight < items[max_index].weight )
					max_index = j;
				}
			else
				{if( items[j].value > items[max_index].value )
					max_index = j;
				}
		}
		swap(items[i], items[max_index]);
	}	
}
	


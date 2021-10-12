#include<iostream>    
using namespace std;     
int main()    
{    
    int i, j,temp;     
    int a[100] 
	 
	for(i = 0; i < n; i++)    
    {    
	   cout<<"a["<<i<<"]=";
       cin<<a[i];     
	   
    }     
	for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }
    cout<<"after sorting :\n";
    for(i=0;i<n;i++)
    {
    	cout<<"a["<<i<<"]="<<a[i]<<endl;
	}

}  

#include <iostream>				

using namespace std;

class hash_table			//Class hash_table created
{
  public:

    int table_hash[50];			//Array Creation
    int table_hash_size;		//Create hash value size
    int ctr;
    hash_table(int n)
    {
        table_hash_size =8;
        ctr = 0;
        for(int i=0;i<table_hash_size;i++)		//increment hash table index as elements are inserted
        {
            table_hash[i] = -1;
        }
    }
    void store_value_linear_probin_with_replacemet(int value);					//Function Declaration
	int calculate_hash_value(int value);
	int search_value_in_hash_table_hash_linear_probing(int value);
    void display_hash_table_hash_linear_probing();

    

};

int hash_table::search_value_in_hash_table_hash_linear_probing(int value)			//Search Hash table with Linear Probing Function
{
    int hashvalue = calculate_hash_value(value);				//Variable Declaration
    display_hash_table_hash_linear_probing();
    if(table_hash[hashvalue] == value)				//if else statement
    {
        cout<<endl<<"Given value "<<value<<" is stored at location "<<hashvalue<<" in hash table";
        return hashvalue;
    }
    else
    {
        ctr = 1;
        int flag = 0;
        while(1)
        {
            hashvalue = (hashvalue + 1) % table_hash_size;					//check for next hash location to match with given hash value
            if(ctr == table_hash_size)						//if matches with hash value
            {
                flag = 0;
                break;
            }
            else if(table_hash[hashvalue] == value)
            {
                flag = 1;
                break;
            }
            else if(table_hash[hashvalue] == -1)					//if element not present in hash table
            {
                flag = 2;
                break;
            }
        }
        if(flag == 0)								//if else statement
        {
            cout<<endl<<"Given value "<<value<<" is stored at location "<<hashvalue<<" in hash table";
            return -1;
        }
        else if(flag == 1)
        {
            cout<<"\nGiven value "<<value<<" is stored in hash table at location : "<<hashvalue;
            return hashvalue;
        }
        else if(flag==2)
        {
        	cout<<"\nHash Value Not found";
		}
    }
}

int hash_table::calculate_hash_value(int value)			//Calculate Hash value function
{
    return value%8;
}


void hash_table::store_value_linear_probin_with_replacemet(int value)		//Store Hash value with replacement Function 
{
    int hashvalue = calculate_hash_value(value);			//calcuate hash value
    //if the location is empty
    if(table_hash[hashvalue] == -1)							//if else statement
    {
        table_hash[hashvalue] = value;			//if value to inserted that hash value location is empty,then insert it in hash location
        ctr++;										//increment counter
    }
    else
    {
        int flag = 0;
        // from next location onward search linearly to find the empty location
        int temp_hash_value = calculate_hash_value(table_hash[hashvalue]);				//store that hash value in temp variable
        if(temp_hash_value == hashvalue)								//if else statement
        {
            while(1)										
            {
                hashvalue = (hashvalue + 1) %table_hash_size;						//calcuate immediate next hash value location
                if(table_hash[hashvalue] == -1)								//if that hash value location is empty		
                {
                    flag = 1;							//flag as 1
                    break;
                }
                else if(ctr == table_hash_size)				//if hashtable is full
                {
                    cout<<"\n Hash table is full with 8 Values";
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)						//add that element to next hash location
            {
                table_hash[hashvalue] = value;
                ctr++;
            }
        }
        //replace data
        else					
        						//else replace existing element in that hash location to next immediate location and insert required value at that hash location
        {
            int temp_value = table_hash[hashvalue];
            table_hash[hashvalue] = value;
            while(1)
            {
                hashvalue = (hashvalue + 1) %table_hash_size;					//calcuate immediate next hash value location
                if(table_hash[hashvalue] == -1)								//check if that location is empty
                {	
                    flag = 1;
                    break;
                }
                else if(ctr == table_hash_size)					//if table is full
                {
                    cout<<"\n Hash table is full with 8 Values";
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)							//insert hash value 
            {
                table_hash[hashvalue] = temp_value;
                ctr++;
            }
        }
    }
    display_hash_table_hash_linear_probing();
}


void hash_table::display_hash_table_hash_linear_probing()			//Display Hash table linear probing Function
{
    cout<<endl<<"Hash Table:-";
    for(int i=0;i<table_hash_size;i++)
    {
        cout<<endl<<"     "<<i<<"     "<<table_hash[i];
    }
}


int main()													//Main Function
{

    hash_table h(10);									//Object Created
    int ch,ch1,choice, value;					//Variable Declaration
    cout<<"<---------------Welcome to Balu's Ice-Cream Parlour--------------->";
    do																					//do while statement
    {
    	cout<<"\n\n1.Insert Flavour_ID\n2.Search Flavour\n3.Display Flavour\n4.Exit\n";
	    cout<<"\nEnter your choice:-\n";
	    cin>>ch;
	    cout<<endl;
    	switch(ch)																										//switch case statement
    {
    	case 1:																										//Case 1 
    	{
			if(ch==1)
			{
				
					while(1)
	    			{
	        		cout<<"\n Enter the Flavour_ID : ";
	        		cin>>value;
			        h.store_value_linear_probin_with_replacemet(value);
			        cout<<"\n Do you want to continue (1/0) : ";
			        cin>>choice;
			        if(choice == 0)
			        break;
	    			}
				}
			}
		break;
    	case 2:																				//Case 2
    	{		
    		int ch2,val;
		    	while(1)
				    {
				        cout<<"\n Enter the Flavour_ID to be searched: ";
				        cin>>val;
				        h.search_value_in_hash_table_hash_linear_probing(val);
				        cout<<"\n Do you want to search other value (1/0) : ";
				        cin>>ch2;
				        if(ch2 == 0)
				        break;
				    }
				break;    
		    }
		    
		case 3:																	//Case 3
		{	
			if(ch==3)
				h.display_hash_table_hash_linear_probing();
		}
		break;
		case 4:														//Case 4
			exit(0);		
	}
	}while(ch!=4);
    
return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define Table_size 13
#define Prime 7

class DoubleHash{

    // Pointer to an array containing buckets.
    int* hashTable;
    int curr_size;

public:
    // Function to check if hash table if full
    bool isFull(){
        return(curr_size == Table_size);
    }

    // Function to calculate first hash
    int hash1(int key)
    {
        return key % Table_size;
    } 

    // Function to calculate second hash
    int hash2(int key)
    {
        return Prime - (key % Prime);
    }

    DoubleHash()
    {
        hashTable = new int[Table_size];
        curr_size = 0 ;
        for(int i = 0 ; i < Table_size ; i++)
            hashTable[i] = -1;
    }

    // Function to insert key into hash table
    void insertHash(int key)
    {
        // If Hash table is full
        if ( isFull() )
            return; 

        // get index from first hash
        int index = hash1(key);

        // if collision occurs
        if(hashTable[index] != -1){
            //get index2 from hash2
            int index2 = hash2(key);
            int i = 1;
            while(1){
                //get newIndex
                int newIndex = (index + i * index2) % Table_size;

                //if no collision occurs store the key
                if(hashTable[newIndex] == -1){
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        } 
        else 
            hashTable[index] = key;
        curr_size++;       
    }

    void search(int key)
    {
        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        while(hashTable[(index1 + i * index2) % Table_size] != key ){
            if(hashTable[(index1 + i * index2) % Table_size] == -1){
                cout << key << " does not exist" << endl;
                return;
            }
            i++;
        }
        cout << key << " found" << endl;
    }

    // Function to display the hash table
    void displayHash()
    {
        for(int  i = 0; i < Table_size ; i++ ){
            if(hashTable[i] != -1)
                cout << i << " --> " << hashTable[i] << endl;
            else
                cout << i << endl;        
        }
    }
};

// Driver's code
int main()
{
    int a[] = { 19, 27, 36, 10, 64 };
    int n = sizeof(a) / sizeof(a[0]);

    // Inserting keys into hash table
    DoubleHash h;
    for(int i = 0 ; i < n ; i++){
        h.insertHash( a[i] );
    }

    h.search(36);
    h.search(100);
    h.displayHash();
    return 0;
}
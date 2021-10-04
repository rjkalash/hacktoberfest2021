// Nut and Bolt Matching Problem based on QuickSort Approach - Google Interview
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std ;

class Bolt; //Forward Declaration
class Nut{
    int Size;
public:
        Nut(int Size){
            this->Size = Size;
        }
        int getSize(){
            return this->Size;
        }
        friend int::compare(const Nut*,const Bolt*);
        friend int::compare(const Bolt*,const Nut*);
};

class Bolt{
    int Size;

public:
    Bolt(int Size){
        this->Size = Size;
    }
    int getSize(){
       return this->Size;
    }
        friend int::compare(const Nut*,const Bolt*);
        friend int::compare(const Bolt*,const Nut*);
};

// Return -1 Nut < Bolt , 0 equal , else 1
int compare(const Nut* n,const Bolt*b){
if( n->Size < b->Size)
    return -1;
else if(n->Size==b->Size)
    return 0;
else
    return 1;
}
//Return -1 Bolt < Nut , 0 equal , else 1
int compare(const Bolt*b,const Nut*n){
if( b->Size < n->Size)
    return -1;
else if(n->Size==b->Size)
    return 0;
else
    return 1;
}
//Since we need two types of partition function , hence better to use a template
template<typename X,typename Y>
int partition(X** a,int low,int high,Y*b){
int i,j,k;
i = low - 1;

for(j=low;j<high;j++){
int c = compare(a[j],b);
// a < b
if(c<0){
    i++;
    X* temp = a[i] ; a[i] = a[j] ; a[j] = temp;
}
else if(c==0){
// Move it to the last for future use
    X*temp = a[j] ; a[j] = a[high] ; a[high] = temp;
    j--;
    }
}
//Bring it back to the i+1 th position
X*temp = a[i+1] ; a[i+1] = a[high] ; a[high] = temp;
return (i+1);
}

void matchNutsBolts(Nut **nuts,Bolt **bolts,int low,int high){
//There must be atleast 2 nuts and bolts to sort , hence the condition low<high.
if(low<high){
// Choose a random Nut as pivot in quickSort and Sort the bolts .
int nutIndex =  low + (rand()%(high-low+1));
Nut *chosenNut = nuts[nutIndex];
int matchedBoltIndex = partition(bolts,low,high,chosenNut);
partition(nuts,low,high,bolts[matchedBoltIndex]);
matchNutsBolts(nuts,bolts,low,matchedBoltIndex-1);
matchNutsBolts(nuts,bolts,matchedBoltIndex+1,high);
}
return ;
}

int main(){
int n,i;
cout<<"Enter the Number of Nuts and Bolts : ";
cin>>n;
Nut **nuts;
Bolt **bolts;

cout<<"Enter Nut Sizes ,then Bolt Sizes :"<<endl;
nuts = new Nut*[n];
bolts = new Bolt*[n];

int s;
for(i=0;i<n;i++){
    cin>>s;
    nuts[i] = new Nut(s);
}
for(i=0;i<n;i++){
    cin>>s;
    bolts[i] = new Bolt(s);
}
matchNutsBolts(nuts,bolts,0,n-1);

cout<<"BOLTS : ";
for(i=0;i<n;i++){
      cout<<bolts[i]->getSize()<<" ";
}
cout<<endl<<"NUTS : ";
for(i=0;i<n;i++){
        cout<<nuts[i]->getSize()<<" " ;
}
return 0;
}

#include<iostream>
using namespace std;
#define N 10005
/*
    Segment tree (pointer)
    (with range update)
*/
int arr[N];
struct node{
    int val=0,tag=0;
    node *Left_child=nullptr,*Right_child=nullptr;
    // update current value after recursion
    void pull(){
        val=max(Left_child->val,Right_child->val);
    }
};

node *Build(int L,int R){
    node *T=new node;
    if(L==R){
        T->val= arr[L];
        return T;
    }

    int Mid=(L+R)>>1 ;
    T->Left_child= Build(L,Mid);
    T->Right_child= Build(Mid+1,R);
    T->pull();
    return T;
}

void Push(node *T,int L,int R){
    if(!T->tag) return;// didn't mark
    if(L!=R){// tag is marked
        // push down the tag
        int Mid=(L+R)/2;
        T->Left_child->tag += T->tag;
        T->Right_child->tag+= T->tag;
        T->Left_child->val += T->tag;
        T->Right_child->val+= T->tag;
    }

    T->tag=0;
}
// arr[QL,QR]+=dif 
void Update(node *T,int L,int R,int QL,int QR,int dif){
    if(QL >R || QR<L ) return;
    if( QL<=L && R<=QR ){
        T->tag+= dif;// add tag for the iterior block that may be query later
        T->val+= dif;
        return ;
    }
    // push down the tag
    Push(T,L,R);
    int Mid=(L+R)/2;
    Update(T->Left_child, L,  Mid,QL,QR,dif);
    Update(T->Right_child,Mid+1,R,QL,QR,dif);
    T->pull();
}

int Query(node *T,int L,int R,int QL,int QR){
    if(QL>R || QR<L) return INT32_MIN; // out of range
    if(QL<=L && R<=QR) return T->val; // current block range fit query range
    // Push down tag when query (only push when it is needed)
    Push(T,L,R);
    int Mid=(L+R)/2;
    return max( Query(T->Left_child,L,Mid,QL,QR) , Query(T->Right_child,Mid+1,R,QL,QR) );
}

int main(){

    //sample
    int n=10,L=1,R=10;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    node *T=Build(L,R);
    
    cout<<Query(T,L,R,1,5)<<'\n';
    cout<<Query(T,L,R,3,4)<<'\n';
    Update(T,L,R,1,5,10);
    cout<<Query(T,L,R,1,5)<<'\n';
    cout<<Query(T,L,R,3,4)<<'\n';
    return 0;
}

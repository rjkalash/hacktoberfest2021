#include<iostream> 
using namespace std; //

int main(){
    int n ;
    cin >> n ; 
    int* arr = new int[n]; 
    for(int i=0 ;i<n ;i++){
        cin >> arr[i]; 
    }

    int targetElement; 
    cin >> targetElement; 

    int flag =0; 

    for(int i =0 ; i<n ; i++){
        if(arr[i] == targetElement && !flag){ 
            cout << "Target element is present at position" << i+1 << endl; 
            flag = 1; 
        }
    }
    if(flag == 0){
        cout << "Target element is not present" << endl; 
    }
    return 0;
}
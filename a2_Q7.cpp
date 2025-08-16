#include<iostream>
using namespace std;

int main(){
    int arr[] = {3 , 2, 3 , 8 , 9 , 5};
    int n  = sizeof(arr)/4;
    int invcount = 0;

    for(int i=0 ; i<n ;i++){
        for(int j =i ; j<n ; j++){
            if(i<j && arr[i]>arr[j]){
                invcount++;
            }
        }
    }
    cout<<invcount<<endl;
    return 0;
    
}
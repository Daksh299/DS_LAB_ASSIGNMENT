#include<iostream>
using namespace std;

int main(){
    int arr[] = { 1 , 2 , 3 , 5  , 6};
    int n = sizeof(arr)/4;
    int cd = (arr[n-1] - arr[0])/(n-1);
     for(int i=0 ; i<n-1 ; i++){
        int expno = arr[i]+cd;
        if(expno != arr[i+1]){
            cout<<"missing no. is = "<<expno<<endl;
        }
     }
     return 0;
}
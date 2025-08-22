#include<iostream>
using namespace std;

int main(){
    int arr[50];
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    for(int i=0  ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i == j){
                cout<<arr[i]<<"\t";
            }
            else{
                cout<<"0"<<"\t";
            }
        }
        cout<<endl;
    }
    return 0;
}
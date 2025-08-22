#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n\n";
    cin>>n;
    int arr[n*(n+1)/2];
    for(int i=0 ; i< n*(n+1)/2 ; i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<=j) cout<<arr[j*(j+1)/2+i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}
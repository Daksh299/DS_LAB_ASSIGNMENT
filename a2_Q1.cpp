#include<iostream>
using namespace std;
//BINARY SEARCH ALGO
int main(){
    int arr[] = {1 ,  2 , 3 , 4 , 6};
    int n = sizeof(arr)/4;
    int key;
    cout<<"enter key to search\n";
    cin>>key;
    int st = 0 , end = n-1;
    int mid;
    while(st<=end){
        mid = st + (end-st)/2;
        if(arr[mid] == key){
            cout<<"mid = "<<mid<<endl;
            break;
        }
        else if(arr[mid] < key){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return 0;
}
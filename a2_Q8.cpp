#include<iostream>
using namespace std;

int main(){
    int arr[] = {3 , 4, 4 , 6 , 7 , 7, 8};
    int n = sizeof(arr)/4;
    int count = 0;

    for(int i = 0 ; i<n ; i++){
        bool isdistinct = true;
        for(int j = 0 ; j<i ; j++){
            if(arr[i] == arr[j]){
                isdistinct = false;
                break;
            }
        }
        if(isdistinct){
            count++;
        }
    }
    cout<<"No. of distict elements = "<<count<<endl;
    return 0;

}
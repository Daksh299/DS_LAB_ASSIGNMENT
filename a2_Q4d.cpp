#include<iostream>
using namespace std;

int main(){
    char str[] ={'s' , 'r' , 't' , 'a'  ,'v' , 'p' , '\0'};
    int n  = sizeof(str);

    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(str[j] > str[j+1]){
                int temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        cout<<str[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
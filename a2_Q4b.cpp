#include<iostream>
using namespace std;


int main(){
    char str[] = {'s' , 't' , 'r'  ,'i' , 'n' , 'g' , '\0'};

    int n = sizeof(str);

    for(int i=0 ; i<n/2 ; i++){
        int temp  =  str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }

    for(int i=0 ; i<n ; i++){
        cout<<str[i];

    }
    cout<<endl;
    return 0;
}
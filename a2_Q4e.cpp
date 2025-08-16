#include<iostream>
using namespace std;

int main(){
    char str[] = {'W' , 'S' , 'A' , 'U'  , 'O' , '\0'};
    int n = sizeof(str);

    for(int i=0 ; i<n ; i++){
        if(str[i] >= 'A' && str[i]<= 'Z'){
            str[i] = str[i] + 32;
        }

    }
    for(int i=0 ; i<n ; i++){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}
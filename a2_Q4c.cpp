#include<iostream>
using namespace std;

int main(){
    char str[] =  {'a' , 'e' , 'i' , 'o' , 'u' , '\0'};
     int n = sizeof(str);
    for(int i=0 ; i<n ; i++){
        if(str[i] == 'a' || str[i] == 'e'|| str[i] == 'i'||str[i] == 'o'|| str[i] == 'u' ){
            str[i] = ' ';
        }

    }
    for(int i=0 ; i<n ; i++){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
    
}
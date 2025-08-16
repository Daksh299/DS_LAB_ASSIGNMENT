#include<iostream>
using namespace std;
#include<string>

//CONCATENATE TWO STRINGS

int main(){
    char str1[100] , str2[100] , result[200];

    cout<<"enter str1\n";
    cin>>str1;

    cout<<"enter str2\n";
    cin>>str2;

    int i=0 , j=0;

    while(str1[j] != '\0'){
        result[i] = str1[j];
        i++;
        j++;
    }
    j=0;
    while(str2[j] != '\0'){
        result[i] = str2[j];
        i++;
        j++;
    }

    for(int m = 0 ; m<i ; m++){
        cout<<result[m];
    }
    cout<<endl;
    return 0;

    }
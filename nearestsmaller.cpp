#include<iostream>
#include<stack>
using namespace std;

int main(){
    int arr[5];
    int ans[5];
    stack<int> s;

    cout<<"Input array\n";
    for(int i = 0 ; i<5 ; i++){
        cin>>arr[i];
    }

    for(int i = sizeof(arr)/4 -1 ; i>=0 ; i--){
        if(s.empty()){
            ans[i] = -1;
            s.push(arr[i]);
        }
        else if(arr[i] < s.top()){
            ans[i] = -1;
            s.pop();
            s.push(arr[i]);
        }
        else{
            ans[i] = s.top();
        }
    }

    for(int i = 0 ; i<5 ; i++){
        cout<<ans[i]<<"\t";
    }
    cout<<endl;
   return 0;
}
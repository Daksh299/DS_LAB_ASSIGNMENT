#include<iostream>
using namespace std;
#define n  10
/*
push()
pop()
isempty()
isfull()
display()
peek()*/
    int arr[n];
    int top = -1;


void push_stack(int a){
    if(top == n-1){
        cout<<"stack is full\n";
    }
    else{
        arr[++top] = a;
        cout<<"%d pushed into the stack"<<a<<endl;
    }

}
void pop_stack(){
    if(top == -1){
        cout<<"stack is empty\n";
    }
    else{
         cout<<"%d popped from the stack"<<arr[top--]<<endl;
    }

}
bool isempty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }

}
bool isfull(){
    if(top == n-1){
        return true;
    }
    else{
        return false;
    }

}
void display(){
    if(top == -1){
        cout<<"stack is empty\n";
    }
    else{
        for(int i= top ; i>= 0 ; i--){
            cout<<arr[i]<<endl;
        }
    }
}


int main(){
    int array[10];
    for(int i=0 ; i<10 ; i++){
        cin>>array[i];
        push_stack(array[i]);
    }
    display();
    isfull();
    isempty();
    pop_stack();
    display();
    isfull();
    isempty();
    return 0;


}

#include<iostream>
using namespace std;
void multiply(int* arr1, int* arr2, int m, int n, int o) {
    int result[m][o];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < o; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += arr1[i * n + k] * arr2[k * o + j];
            }
        }
    }
    
    cout << "Resultant matrix after multiplication: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < o; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
int main (){
    int m, n, p, o;
    cout<<"Enter the number of rows and columns: ";
    cin>>m>>n;
    int arr [m][n];

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter the number of rows and columns: ";
    cin>>p>>o;
    int arr1 [p][o];

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<p;i++){
        for(int j=0;j<o;j++){
            cin>>arr1[i][j];
        }
    }
    if(p!= n){
        cout<<"Multiplication not possible"<<endl;
        return 0;
    }else{    multiply(&arr[0][0],&arr1[0][0],m,n,o);}
        return 0;
}
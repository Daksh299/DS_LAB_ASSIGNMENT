#include<iostream>
using namespace std;  
int arr[100], n;  
void duplicate() {
    int i, j, k = 0;
    
    
    for (i = 0; i < n-1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                arr[j]=arr[j+1];
                n--;
                j--;
                
            }
            
        }
    }
    
    cout << "Array after removing duplicates: ";
    for (i = 0; i < n; i++) { cout << arr[i] << " "; }
    cout << endl;
}
int main() {
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    duplicate();
    
    return 0;
}
#include<iostream>
using namespace std;
void rev(int* arr, int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
   
    cout << endl;
}
int main (){
    int arr[]={2,6,5,4,3};
    rev(arr,5);

    cout << "Reversed array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

}
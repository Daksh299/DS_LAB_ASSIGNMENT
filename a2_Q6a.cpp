#include<iostream>
using namespace std;

int main(){
    int m, n, t;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> m >> n >> t;
    int arr[100][3];
    cout << "Enter triplets (row col value):\n";
    arr[0][0] = m; arr[0][1] = n; arr[0][2] = t;
    for(int i=1; i<=t; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    int arr2[100][3];
    arr2[0][0] = n; arr2[0][1] = m; arr2[0][2] = t;

    int k = 1;
    for(int c=0; c<n; c++) {
        for(int i=1; i<=t; i++) {
            if(arr[i][1] == c) {
                arr2[k][0] = arr[i][1];
                arr2[k][1] = arr[i][0];
                arr2[k][2] = arr[i][2];
                k++;
            }
        }
    }

    cout << "\nTranspose (triplet form):\n";
    for(int i=0; i<=t; i++) {
        cout << arr2[i][0] << " " << arr2[i][1] << " " << arr2[i][2] << endl;
    }
    return 0;
}
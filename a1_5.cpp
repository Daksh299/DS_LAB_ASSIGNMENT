#include <iostream>
using namespace std;

void sumrc(int arr[][4], int m, int n) {
    // Sum of each row
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += arr[i][j];
        }
        cout << "Sum of Row " << i + 1 << " = " << rowSum << endl;
    }

for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += arr[i][j];
        }
        cout << "Sum of Column " << j + 1 << " = " << colSum << endl;
    }
}

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    sumrc(arr, 3, 4);
}
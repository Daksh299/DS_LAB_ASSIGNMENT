#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int A[50][50];
    cout << "Enter matrix elements:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    bool found = false;

    // check each row
    for(int i=0; i<m; i++) {
        int rowMin = A[i][0], colIndex = 0;

        // find min in row
        for(int j=1; j<n; j++) {
            if(A[i][j] < rowMin) {
                rowMin = A[i][j];
                colIndex = j;
            }
        }

        // check if it is max in its column
        bool isSaddle = true;
        for(int k=0; k<m; k++) {
            if(A[k][colIndex] > rowMin) {
                isSaddle = false;
                break;
            }
        }

        if(isSaddle) {
            cout << "Saddle Point found: " << rowMin 
                 << " at position (" << i << "," << colIndex << ")\n";
            found = true;
        }
    }

    if(!found) {
        cout << "No saddle point in the matrix.\n";
    }

    return 0;
}
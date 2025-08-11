#include<iostream>
using namespace std;
int arr[100],n=sizeof(arr)/sizeof(arr[0]);
void create (int n) {
    
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout << "Array created with elements: ";
    
    cout << endl;
}
void display() {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insert() {
    int  pos, value;
           n++;
    cout << "Enter the position to insert the new element (0 to " << n-1 << "): ";                                
    cin >> pos;

    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }   
    cout << "Enter the value to insert: ";  
    cin >> value;
    
    for (int i = 0; i < pos; i++) {
        arr[i] = i + 1;
    }
    arr[pos] = value;
    for (int i = pos + 1; i <= n; i++) {
        arr[i] = i;
    }
    // cout << "Array after insertion: ";
    // for (int i = 0; i <= n; i++) {
    //     cout << arr[i] << " ";
    // }
    cout <<"Element Inserted"<<endl;
    
}
void delete1() {
    int pos;
    cout << "Enter the position of element to delete (0 to " << n-1 << "): ";                                
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    n--;
    cout << "Element at position " << pos << " deleted." << endl;
}
void search() {
    int value;
    cout << "Enter the value to search: ";
    cin >> value;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Element found at position: " << i << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}
int main(){
   
    cout << "---MENU---\n";
    cout << "1. CREATE\n";
    cout << "2. DISPLAY\n";
    cout << "3. INSERT\n";
    cout << "4. DELETE\n";
    cout << "5. LINEAR SEARCH\n";
    cout << "6. EXIT\n";
  

    int choice; 
    
    while(1) {
         cout<<"Enter your choice: "<<endl;
       cin >> choice; 
    
    switch(choice) {
        case 1:
         cout << "Enter the number of elements in the array: ";
    cin >> n;
            create(n);
            display();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            display();
            break;
        case 4:
            delete1();display();
            break;
        case 5:
            search();
            break;
        case 6:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
    }
}
    return 0;
}

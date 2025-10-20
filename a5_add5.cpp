#include <iostream>
using namespace std;

struct Node {
    int coeff;   // Coefficient
    int pow;     // Power
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

// Function to add two polynomial linked lists
Node* addPolynomials(Node* poly1, Node* poly2) {
    // Dummy node to build the result
    Node* dummy = new Node(0, 0);
    Node* tail = dummy;

    // Traverse both lists
    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) { // Only add non-zero terms
                tail->next = new Node(sumCoeff, poly1->pow);
                tail = tail->next;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            tail->next = new Node(poly1->coeff, poly1->pow);
            tail = tail->next;
            poly1 = poly1->next;
        }
        else {
            tail->next = new Node(poly2->coeff, poly2->pow);
            tail = tail->next;
            poly2 = poly2->next;
        }
    }

    // Append remaining terms if any
    while (poly1) {
        tail->next = new Node(poly1->coeff, poly1->pow);
        tail = tail->next;
        poly1 = poly1->next;
    }
    while (poly2) {
        tail->next = new Node(poly2->coeff, poly2->pow);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return dummy->next;
}

// Utility function to print polynomial
void printPolynomial(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->pow;
        if (poly->next) cout << " + ";
        poly = poly->next;
    }
    cout << "\n";
}

// Example usage
int main() {
    // First polynomial: 5x^3 + 4x^2 + 2x^0
    Node* poly1 = new Node(5, 3);
    poly1->next = new Node(4, 2);
    poly1->next->next = new Node(2, 0);

    // Second polynomial: 5x^2 + 5x^1 + 5x^0
    Node* poly2 = new Node(5, 2);
    poly2->next = new Node(5, 1);
    poly2->next->next = new Node(5, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "Sum: ";
    printPolynomial(result);

    return 0;
}
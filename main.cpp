#include <iostream>
using namespace std;
#include "CDA1.cpp"

int main() {
    // Test Default Constructor
    CDA<int> A;
    int sizeA = A.Length();
    int capacityA = A.Capacity();
    cout << "The size of A is: " << sizeA << endl;
    cout << "The capacity of A is: " << capacityA << endl;

    // Test Constructor
    CDA<int> B(10);
    int sizeB = B.Length();
    int capacityB = B.Capacity();
    cout << "The size of B is: " << sizeB << endl;
    cout << "The capacity of B is: " << capacityB << endl;
    B.PrintArray();

    // Test AddEnd Function
    cout << "Adding 10 and 12 to back of array B..." << endl;
    B.AddEnd(10);
    B.AddEnd(12);
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;
    B.PrintArray();
    
    // Test AddFront and DelEnd Functions
    cout << "Adding 5 to front..." << endl;
    B.AddFront(5);
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;
    B.PrintArray();
    cout << "Deleting 2 from back of array..." << endl;
    B.DelEnd();
    B.DelEnd();
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;
    B.PrintArray();

    // Test Select Operation
    cout << "The first element of B is: " << B.Select(0) << endl;
    cout << "Printing all of B using Select function..." << endl;
    for(int i=0; i<B.Length(); i++) {
        cout << B.Select(i) << " ";
    }

    // Test Copy Constructor
    cout << "Testing Copy Constructor..." << endl << "C = B <-- Making a copy of B" << endl;
    CDA<int> C = B;
    C.PrintArray();
    for(int i=0; i<C.Length(); i++) {
        cout << C.Select(i) << " ";
    }
    cout << endl << "Done with tests." << endl;

    /*
    // Test Deleting a Class
    // TO DO:
    B.~CDA();
    sizeB = B.Length();
    capacityB = B.Capacity();
    cout << "The size of B is: " << sizeB << endl;
    cout << "The capacity of B is: " << capacityB << endl;
    */
    
}
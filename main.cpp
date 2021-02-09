#include <iostream>
using namespace std;
#include "CDA1.cpp"

void ConstructorTests() {
    cout << "-------------- Beginning Constructor Tests ---------------" << endl << endl;
    
    // Test Default Constructor
    CDA<int> A;
    cout << "Creating new CDA A..." << endl << endl;
    cout << "The size of A is: " << A.Length() << endl;
    cout << "The capacity of A is: " << A.Capacity() << endl;
    A.PrintArray();

    // Test Constructor
    CDA<int> B(10);
    cout << "Creating new CDA B(10)..." << endl << endl;
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;
    B.PrintArray();

    // Test Copy Constructor
    cout << "Testing Copy Constructor..." << endl << "C = B <-- Making a copy of B" << endl;
    CDA<int> C = B;
    cout << "The size of C is: " << C.Length() << endl;
    cout << "The capacity of C is: " << C.Capacity() << endl;
    C.PrintArray();

    cout << endl << "----------- Done with Constructor tests -------------------" << endl << endl;
}

void AddEndTests() {
    cout << "-------------- Beginning AddEnd() Tests ---------------" << endl << endl;

    // SETUP
    cout << "Creating CDA B(10)..." << endl;
    CDA<int> B(10);
    B.PrintArray();
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;

    // Test AddEnd(10)
    cout << endl << "Adding 10 to back of array B..." << endl;
    B.AddEnd(10);
    B.PrintArray();
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;

    // Test AddEnd(12)
    cout << endl << "Adding 12 to back of array B..." << endl;
    B.AddEnd(12);
    B.PrintArray();
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;

    // Test AddEnd(6)
    cout << endl << "Adding 6 to back of array B..." << endl;
    B.AddEnd(6);
    B.PrintArray();
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;

    // End of Tests
    cout << endl << "----- End of AddEnd() tests -----" << endl << endl;
}

int main() {
    ConstructorTests();
    AddEndTests();
    
    // SETUP
    cout << "Creating CDA B(10)..." << endl;
    CDA<int> B(10);
    B.PrintArray();
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;

    // Test Copy Assignment Operator
    cout << "Creating CDA D = B..." << endl;
    CDA<int> D = B;
    D.PrintArray();
    cout << "The size of D is: " << D.Length() << endl;
    cout << "The capacity of D is: " << D.Capacity() << endl;

    // Test Overloaded Operator Brackets
    cout << "Testing Overloaded Bracket Operator..." << endl;
    cout << "Setting all variables in D to 2 and B's variables to intervals of 5..." << endl << endl;
    for (int i=0; i<B.Length(); i++) {
        B[i] = 5*i;
        D[i] = 2;
    }
    B.PrintArray();
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;
    D.PrintArray();
    cout << "The size of D is: " << D.Length() << endl;
    cout << "The capacity of D is: " << D.Capacity() << endl;

    // Test Clear() Function
    cout << "Testing Clear Function..." << endl;
    cout << "D.Clear();" << endl;
    D.Clear();
    D.PrintArray();
    cout << "The size of D is: " << D.Length() << endl;
    cout << "The capacity of D is: " << D.Capacity() << endl;

    // Test Reverse() Function
    cout << "Testing Reverse Function..." << endl;
    CDA<int> E(5);
    for (int i=0; i<E.Length(); i++) {
        E[i] = i*10;
    }
    cout << "Created CDA E(5)..." << endl;
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;
    E.Reverse();
    cout << "E.Reverse()..." << endl;
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;

    // Test Reverse and CopyArray during Resize
    // Also Test AddEnd, AddFront, DelEnd, and DelFront for reversed array
    E.AddEnd(69);
    cout << "E.AddEnd(69)..." << endl;
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;
    E.AddEnd(11);
    cout << "E.AddEnd(11)..." << endl;
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;
    E.AddFront(200);
    cout << "E.AddFront(200)..." << endl;
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;
    E.AddFront(200);
    cout << "E.AddFront(200)..." << endl;
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;
    E.AddFront(200);
    cout << "E.AddFront(200)..." << endl;
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;

    cout << endl << "Deleting 2 from Front and 6 from Back..." << endl;
    E.DelFront();
    E.DelFront();
    E.DelEnd();
    E.DelEnd();
    E.DelEnd();
    E.DelEnd();
    E.DelEnd();
    E.DelEnd();
    E.PrintArray();
    cout << "The size of E is: " << E.Length() << endl;
    cout << "The capacity of E is: " << E.Capacity() << endl;

    // End of Tests
    cout << endl << "----- End of tests -----" << endl << endl;

    /*
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
    //B.PrintArray();
    cout << "Printing all of B using Select function..." << endl;
    for(int i=0; i<B.Length(); i++) {
        cout << B.Select(i) << " ";
    }

    // Test AddEnd Function
    cout << "Adding 10 and 12 to back of array B..." << endl;
    B.AddEnd(10);
    B.AddEnd(12);
    cout << "The size of B is: " << B.Length() << endl;
    cout << "The capacity of B is: " << B.Capacity() << endl;
    //B.PrintArray();
    cout << "Printing all of B using Select function..." << endl;
    for(int i=0; i<B.Length(); i++) {
        cout << B.Select(i) << " ";
    }
    cout << endl << endl;
    
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
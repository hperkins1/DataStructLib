#include <iostream>
using namespace std;
#include "CDA.cpp"

void Print(CDA<int> &v) {
    v.PrintArray();
    cout << "Size: " << v.Length() << endl;
    cout << "Capacity: " << v.Capacity() << endl;
}

void ConstructorTests() {
    cout << "----- 1.0 Constructor Tests -----" << endl;
    
    // Default Constructor
    cout << "1.1 Default Constructors" << endl;
    cout << "Creating CDA A with Default Constructor..." << endl;
    CDA<int> A;
    Print(A);

    // Constructor with Parameter
    cout << endl << "1.2 Constructors with Parameter s" << endl;
    cout << "Creating CDA B with parameter of 4 [B(4)]..." << endl;
    CDA<int> B(4);
    Print(B);

    // Constructor with Parameter of 0
    cout << endl << "1.2.1 Constructor with Parameter 0" << endl;
    cout << "Creating CDA Y with parameter of 0 [Y(0)]..." << endl;
    CDA<int> Y(0);
    Print(Y);

    // Constructor with Negative Parameter
    // Error handling done by PC
    /*cout << endl << "1.2.2 Constructor with Negative Parameter s" << endl;
    cout << "Creating CDA X with parameter of -4 [X(-4)]..." << endl;
    CDA<int> X(-4);
    Print(X);*/ 

    // Copy Constructor
    cout << endl << "1.3 Copy Constructors" << endl;
    cout << "Creating CDA C with parameter of B [C(B)]..." << endl;
    CDA<int> C(B);
    Print(C);

    // Copy Constructor on Empty Array
    cout << endl << "1.3.1 Copy Constructor on an Empty Array" << endl;
    cout << "Creating CDA Z with parameter of A (empty array) [Z(A)]..." << endl;
    CDA<int> Z(A);
    Print(Z);

    // Copy Assignment Operator
    cout << endl << "1.4 Copy Assignment Operator" << endl;
    cout << "Creating CDA D = B..." << endl;
    CDA<int> D = B;
    Print(D);
    
    // Set another already existing CDA = to another CDA
    cout << endl << "1.4.1 Copy Assignment Operator on 2 already existing CDAs (From Larger to Smaller)" << endl;
    cout << "C = A..." << endl;
    C = A;
    Print(C);

    // Set another already existing CDA = to another CDA
    cout << endl << "1.4.2 Copy Assignment Operator on 2 already existing CDAs (From Smaller to Larger)" << endl;
    cout << "C = B..." << endl;
    C = B;
    Print(C);

    // Set another already existing CDA = to another CDA
    cout << endl << "1.4.3 Copy Assignment Operator on 2 already existing CDAs (Same Arrays)" << endl;
    cout << "B = C..." << endl;
    B = C;
    Print(B);

    // Copy Assignment Operator on Empty Array
    cout << endl << "1.4.4 Copy Assignment Operator on Empty Array" << endl;
    cout << "Creating CDA F = A (empty array)..." << endl;
    CDA<int> F = A;
    Print(F);    

    // Constructors on Reversed Arrays
    cout << endl << "1.5 Constructors on Reversed Arrays" << endl;
    cout << "Creating CDA R = { 0, 5, 10, 15 }..." << endl;
    CDA<int> R(4);
    for(int i=0; i<R.Length(); i++) {
        R[i] = i*5;
    }
    Print(R);
    cout << "Reversing R..." << endl;
    R.Reverse();
    Print(R);

    // Copy Constructor on Reversed Array
    cout << endl << "1.5.1 Copy Constructor on Reversed Array" << endl;
    cout << "Creating CDA S(R)..." << endl;
    CDA<int> S(R);
    Print(S);

    // Copy Assignment Constructor on Reversed Array
    cout << endl << "1.5.2 Copy Assignment Operator on Reversed Array" << endl;
    cout << "Creating CDA T = R..." << endl;
    CDA<int> T = R;
    Print(T);

    // Copy Assignment Operator on Reversed Array
    cout << endl << "1.5.3 Copy Assignment Operator on Reversed Array" << endl;
    cout << "Creating CDA U..." << endl;
    CDA<int> U;
    Print(U);
    cout << "U = R..." << endl;
    U = R;
    Print(U);


    // TODO: Constructors on Ordered Arrays

    // End of Constructor Tests
    cout << endl << "----- END OF Constructor Tests -----" << endl;
}

void AddDelTests() {
    cout << "----- 2.0 Add and Delete Tests -----" << endl;
    
    // SETUP
    cout << "SETUP" << endl;
    cout << "Creating CDA B(10) = { 0 2 4 6 8 10 12 14 16 18}..." << endl;
    CDA<int> B(10);
    for(int i=0; i<B.Length(); i++) {
        B[i] = 2*i;
    }
    Print(B);

    // Add and Del to Normal Arrays
    cout << endl << "2.1 AddEnd and AddFront" << endl;

    // Add to Normal Arrays
    cout << endl << "2.1.1 Add to Normal Array" << endl;
    cout << "AddFront(500)" << endl;
    B.AddFront(500);
    Print(B);
    cout << "AddEnd(44)" << endl;
    B.AddEnd(44);
    Print(B);

    // Del to Normal Arrays
    cout << endl << "2.1.2 Delete to Normal Array" << endl;
    cout << "7 DelEnd()'s..." << endl;
    for(int i=0; i<7; i++) {
        B.DelEnd();
    }
    Print(B);
    cout << "3 DelFront()'s..." << endl;
    for(int i=0; i<3; i++) {
        B.DelFront();
    }
    Print(B);

    // Add and Delete to Reverse Arrays
    cout << endl << "2.2 AddEnd and AddFront to Reversed Arrays" << endl;

    // SETUP
    cout << "SETUP" << endl;
    cout << "Creating CDA C(4) = { 0 5 10 15 }..." << endl;
    CDA<int> C(4);
    for(int i=0; i<C.Length(); i++) {
        C[i] = 5*i;
    }
    Print(C);
    cout << "Reversing C..." << endl;
    C.Reverse();
    Print(C);

    // Add to Reverse Arrays
    cout << endl << "2.2.1 Add to Reverse Array" << endl;
    cout << "AddFront(66)..." << endl;
    C.AddFront(66);
    Print(C);
    cout << "AddEnd(22)..." << endl;
    C.AddEnd(22);
    Print(C);
    cout << "AddEnd(22)..." << endl;
    C.AddEnd(22);
    Print(C);
    cout << "AddEnd(11)..." << endl;
    C.AddEnd(11);
    Print(C);
    cout << "AddEnd(1)..." << endl;
    C.AddEnd(1);
    Print(C);

    // Del to Reverse Arrays
    cout << endl << "2.2.2 Delete to Reverse Array" << endl;
    cout << "DelFront()... " << endl;
    C.DelFront();
    Print(C);
    cout << "DelEnd() 4 times..." << endl;
    for(int i=0; i<4; i++) {
        C.DelEnd();
    }
    Print(C);

    // Reverse an already Reversed Array
    cout << endl << "2.3 Reverse an Already Reversed Array" << endl;
    cout << "Reversing C..." << endl;
    C.Reverse();
    Print(C);
    cout << "CDA B:" << endl;
    Print(B);
    cout << "Reversing B..." << endl;
    B.Reverse();
    Print(B);

    // AddEnd to an array of size and length 0
    cout << endl << "2.4 Add End to an Empty Array" << endl;
    cout << "Initializing D with Default Constructor..." << endl;
    CDA<int> D;
    Print(D);

    // AddEnd to Empty Array
    cout << "AddEnd(10)..." << endl;
    D.AddEnd(10);
    Print(D);   
    cout << "AddFront(500)..." << endl;
    D.AddFront(500);
    Print(D);

    // Return to Empty Array
    cout << "Making CDA D empty again..." << endl;
    D.DelEnd();
    D.DelEnd();
    Print(D);

    // AddFront to Empty Array
    cout << "AddFront(10)..." << endl;
    D.AddFront(10);
    Print(D);   
    cout << "AddEnd(500)..." << endl;
    D.AddEnd(500);
    Print(D);

    cout << endl << "----- END OF Add & Delete Tests -----" << endl;
}

void BracketTests() {
    cout << "----- 3.0 Bracket Operator Tests -----" << endl;

    // SETUP
    cout << "SETUP" << endl;
    cout << "Creating CDA B(10) = { 0 2 4 6 8 10 12 14 16 18}..." << endl;
    CDA<int> B(10);
    for(int i=0; i<B.Length(); i++) {
        B[i] = 2*i;
    }
    Print(B);

    // Bracket Operator Test
    cout << endl << "3.1 Bracket Operator Test on Normal CDA" << endl;
    cout << "Accessing all values of B..." << endl;
    for(int i=0; i<B.Length(); i++) {
        cout << "B[" << i << "]: " << B[i] << endl;
    }
    Print(B);

    // Bracket Operator on Reversed CDA
    cout << endl << "3.2 Bracket Operator Test on Reversed CDA" << endl;
    cout << "Reversing B..." << endl;
    B.Reverse();
    cout << "Accessing all values of B..." << endl;
    for(int i=0; i<B.Length(); i++) {
        cout << "B[" << i << "]: " << B[i] << endl;
    }
    Print(B);

    // Bracket Operator Test
    cout << endl << "3.3 Bracket Operator Test on Semi-Full CDA" << endl;
    cout << "Deleting 3 from Front..." << endl;
    for(int i=0; i<3; i++) {
        B.DelFront();
    }
    Print(B);
    cout << "Accessing all values of B..." << endl;
    for(int i=0; i<B.Length(); i++) {
        cout << "B[" << i << "]: " << B[i] << endl;
    }
    Print(B);

    // Bracket Operator on Reversed CDA
    cout << endl << "3.4 Bracket Operator Test on Reversed  Semi-Full CDA" << endl;
    cout << "Reversing B..." << endl;
    B.Reverse();
    cout << "Accessing all values of B..." << endl;
    for(int i=0; i<B.Length(); i++) {
        cout << "B[" << i << "]: " << B[i] << endl;
    }
    Print(B);

    cout << endl << "----- END OF Bracket Operator Tests -----" << endl;
}

int main() {
    cout << "----- Beginning Unit Tests -----" << endl << endl;
    ConstructorTests();
    AddDelTests();
    BracketTests();



    cout << endl << "----- End of Unit Tests -----" << endl;
}


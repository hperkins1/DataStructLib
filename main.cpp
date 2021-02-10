#include <iostream>
using namespace std;
#include "CDA1.cpp"

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



    // Constructors on Empty Arrays
    // Constructors on Reversed Arrays
    // COnstructors on Ordered Arrays

    // AddEnd to an array of size and length 0?

    // End of Constructor Tests
    cout << endl << "----- END OF Constructor Tests -----" << endl;
}

int main() {
    cout << "----- Beginning Unit Tests -----" << endl << endl;
    ConstructorTests();


    cout << endl << "----- End of Unit Tests -----" << endl;
}


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

    // Copy Constructor
    cout << endl << "1.3 Copy Constructors" << endl;
    cout << "Creating CDA C with parameter of B [C(B)]..." << endl;
    CDA<int> C(B);
    Print(C);

    // Copy Assignment Operator
    cout << endl << "1.4 Copy Assignment Operator" << endl;
    cout << "Creating CDA D = B..." << endl;
    CDA<int> D = B;
    Print(D);

    /*
    // Set another already existing CDA = to another CDA
    cout << endl << "1.4.1 Copy Assignment Operator on 2 already existing CDAs (From Larger to Smaller)" << endl;
    cout << "C = A..." << endl;
    C = A;
    Print(C);

    // Set another already existing CDA = to another CDA
    cout << endl << "1.4.2 Copy Assignment Operator on 2 already existing CDAs (From Smaller to Larger)" << endl;
    cout << "C = B..." << endl;
    C = B;
    Print(C);*/

    // End of Constructor Tests
    cout << endl << "----- END OF Constructor Tests -----" << endl;
}

int main() {
    cout << "----- Beginning Unit Tests -----" << endl << endl;
    ConstructorTests();


    cout << endl << "----- End of Unit Tests -----" << endl;
}


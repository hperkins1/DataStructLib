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

void LinearSearchTests() {
    cout << endl << "----- 4.0 BEGINNNING OF Linear Search Tests -----" << endl;

    // SETUP
    cout << "SETUP" << endl;
    cout << "Creating CDA B(10) = { 0 2 4 6 8 10 12 14 16 18}..." << endl;
    CDA<int> B(10);
    for(int i=0; i<B.Length(); i++) {
        B[i] = 2*i;
    }
    Print(B);

    // Search Test on Regular Array (Found element)
    cout << endl << "4.1 Search Test to Find Element on Regular Array where element exists" << endl;
    cout << "B.Search(6)..." << endl;
    cout << "Element found at B[" << B.Search(6) << "]" << endl;

    // Search Test on Regular Array (no element found)
    cout << endl << "4.2 Search Test to Find Element on Regular Array where element doesn't exists" << endl;
    cout << "B.Search(20)..." << endl;
    cout << "Element found at B[" << B.Search(20) << "]" << endl;

    // Search on Reversed Array (Found element)
    cout << endl << "4.3 Linear Search on Reversed Array (element exists)" << endl;
    cout << "Reversing B..." << endl;
    B.Reverse();
    Print(B);
    cout << "B.Search(6)..." << endl;
    cout << "Element found at B[" << B.Search(6) << "]" << endl;

    // Search on Reversed Array (no element found)
    cout << endl << "4.4 Linear Search on Reversed Array (element does not exist)" << endl;
    cout << "B.Search(20)..." << endl;
    cout << "Element found at B[" << B.Search(20) << "]" << endl;

    // Search on Empty Array
    cout << endl << "4.5 Linear Search on Empty Array" << endl;
    cout << "Creating Default CDA A..." << endl;
    CDA<int> A;
    Print(A);
    cout << "A.Search(3)" << endl;
    cout << "Element found at A[" << A.Search(3) << "]" << endl;

    // Search on Semi-full Array with Moved Elements
    cout << endl << "4.6 Linear Search on Semi-Full Array with moved elements (element exists)" << endl;
    cout << "B.AddFront(500)" << endl;
    B.AddFront(500);
    Print(B);
    cout << "B.AddEnd(44)" << endl;
    B.AddEnd(44);
    Print(B);
    cout << "B.Search(44)" << endl;
    cout << "Element found at B[" << B.Search(44) << "]" << endl;
    cout << "B.Search(500)" << endl;
    cout << "Element found at B[" << B.Search(500) << "]" << endl;
    cout << "B.Search(4)" << endl;
    cout << "Element found at B[" << B.Search(4) << "]" << endl;
    Print(B);


    // Search on Semi-full Array with Moved Elements
    cout << endl << "4.7 Linear Search on Semi-Full Array with moved elements (element does not exist)" << endl;
    cout << "B.Search(400)" << endl;
    cout << "Element found at B[" << B.Search(400) << "]" << endl;
    
    cout << endl << "----- END OF Linear Search Tests -----" << endl;
}

void BinarySearchTests() {
    cout << endl << "----- 5.0 BEGINNNING OF Binary Search Tests -----" << endl;

    // SETUP
    cout << "SETUP" << endl;
    cout << "Creating ordered CDA B(10) = { 0 2 4 6 8 10 12 14 16 18}..." << endl;
    CDA<int> B(10);
    for(int i=0; i<B.Length(); i++) {
        B[i] = 2*i;
    }
    Print(B);

    // Binary Search on Array where element exists
    cout << endl << "5.1 Binary Search on Array (Element exists)" << endl;
    cout << "B.BinSearch(4)" << endl;
    cout << "Element found at B[" << B.BinSearch(4) << "]" << endl;
    Print(B);

    // Binary Search on Array where element does not exist
    cout << endl << "5.2 Binary Search on Array (Element does not exist)" << endl;
    cout << "B.BinSearch(1)" << endl;
    cout << "Element found at B[" << B.BinSearch(1) << "]" << endl;
    Print(B);

    // SETUP
    cout << endl << "SETUP" << endl;
    cout << "Creating ordered CDA R(10) = { 18 16 14 12 10 8 6 4 2 0}..." << endl;
    CDA<int> R(10);
    for (int i=0; i<R.Length(); i++) {
        R[i] = (2*(R.Length()-i) - 2);
    }
    Print(R);
    R.Reverse();
    cout << "Reversing R..." << endl;
    Print(R);

    // Test on Reversed Arrays (element exists)
    cout << endl << "5.3 Binary Search on Reversed Array (Element exists)" << endl;
    cout << "R.BinSearch(4)" << endl;
    cout << "Element found at B[" << R.BinSearch(4) << "]" << endl;
    Print(R);
    cout << "R.BinSearch(18)" << endl;
    cout << "Element found at B[" << R.BinSearch(18) << "]" << endl;
    cout << "AddEnd(50)" << endl;
    R.AddEnd(50);
    for(int i=0; i<R.Length(); i++) {
        cout << R[i] << " ";
    }
    Print(R);
    cout << "DelFront()" << endl;
    R.DelFront();
    for(int i=0; i<R.Length(); i++) {
        cout << R[i] << " ";
    }
    Print(R);
    cout << "R.BinSearch(2)" << endl;
    cout << "Element found at R[" << R.BinSearch(2) << "]" << endl;
    cout << "Was expecting element at R[0]: " << R[0] << endl;
    cout << "R.BinSearch(50)" << endl;
    cout << "Element found at R[" << R.BinSearch(50) << "]" << endl;
    cout << "Was expecting element at R[9]: " << R[9] << endl;
    Print(R);

    // Test on Reversed Arrays (Element not there)
    cout << endl << "5.4 Binary Search on Reversed Array (Element does not exist)" << endl;
    cout << "R.BinSearch(1)" << endl;
    cout << "Element found at B[" << R.BinSearch(1) << "]" << endl;
    Print(R);
    cout << "Was expecting element at B[-1]: because element does not exist" << endl; 

    // Test on Empty Arrays
    // Test on Arrays that are Semi-full and have been moved around in memory

    cout << endl << "----- END OF Binary Search Tests -----" << endl;
}

// SORTING TESTS
void SortTests() {
    cout << endl << "----- 6.0 BEGINNNING OF Sorting Tests -----" << endl;

    // SETUP
    cout << "SETUP" << endl;
    cout << "Creating CDA B(10) = { 0 2 4 6 8 10 12 14 16 18}..." << endl;
    CDA<int> B(10);
    for(int i=0; i<B.Length(); i++) {
        B[i] = 2*i;
    }
    Print(B);
    cout << "AddFront(500)..." << endl;
    B.AddFront(500);
    cout << "AddFront(49)..." << endl;
    B.AddFront(49);
    Print(B);

    // Sort a given array
    cout << endl << "6.1 Sort Test on Array" << endl;
    cout << "Sorting B..." << endl;
    B.Sort();
    Print(B);

    // Sort a reversed array
    cout << endl << "6.2 Sort Test on Reversed Array" << endl;
    cout << "Reversing B..." << endl;
    B.Reverse();
    Print(B);
    cout << "Sorting B..." << endl;
    B.Sort();
    Print(B);

    // Add elements to array and sort again
    cout << endl << "6.3 Sort Test on Array after adding elements to array" << endl;
    cout << "AddEnd(10)" << endl;
    B.AddEnd(10);
    Print(B);
    cout << "AddFront(77)" << endl;
    B.AddFront(77);
    Print(B);
    cout << "AddFront(33)" << endl;
    B.AddFront(33);
    Print(B);
    cout << "Sorting B..." << endl;
    B.Sort();
    Print(B);

    // Reverse Array and sort again
    cout << endl << "6.3.1 Reverse and Sort this array again" << endl;
    cout << "Reversing array..." << endl;
    B.Reverse();
    Print(B);
    cout << "Sorting Array..." << endl;
    B.Sort();
    Print(B);

    // Test Select on Ordered Arrays
    cout << endl << "6.4 Select on Ordered Arrays" << endl;
    cout << "Select 2nd smallest element: " << B.Select(2) << endl;
    cout << "Select 5th smallest element: " << B.Select(5) << endl;

    // Test Select on UnOrdered Arrays
    cout << endl << "6.4.1 Select on Unordered Arrays (reversed)" << endl;
    cout << "Reversing B..." << endl;
    B.Reverse();
    Print(B);
    cout << "Select 2nd smallest element: " << B.Select(2) << endl;
    cout << "Select 5th smallest element: " << B.Select(5) << endl;

    // Test Select on UnOrdered Arrays 
    cout << endl << "6.4.2 Select on Unordered Array (not Reversed)" << endl;
    cout << "Reversing B..." << endl;
    B.Reverse();
    Print(B);
    cout << "Select 2nd smallest element: " << B.Select(2) << endl;
    cout << "Select 5th smallest element: " << B.Select(5) << endl;

    cout << endl << "----- END OF Sorting Tests -----" << endl;
}

int main() {
    cout << "----- Beginning Unit Tests -----" << endl << endl;
    ConstructorTests();
    AddDelTests();
    BracketTests();
    LinearSearchTests();
    BinarySearchTests();
    SortTests();



    cout << endl << "----- End of Unit Tests -----" << endl;
}


/*  
 *  Data Structures Library
 *  Phase 1
 * 
 *  Author: Hannah Perkins
 *  Date: 7 February 2021
 *  Course: CS 201
 * 
 *  Function: 
 * 
 *  Description: 
 * 
 *  
 * 
 * 
*/

using namespace std;
#include <iostream>

// elmtype represents template parameter for unknown parameter types
// template <class elmtype>

// CDA (Circular Dynamic Array) Class 
template <class elmtype> class CDA {
    public:
        CDA();                      // Default Constructor
        CDA(int s);                 // Constructor
        CDA(CDA<elmtype>&);   // Copy Constructor     // TO DO:
        ~CDA();                     // Destructor           // TO DO:
        
        CDA& operator=(const CDA& v);   // Copy Assignment Operator // TO DO:
        //elmtype& operator[](int i);

        // Add and Delete Operations for CDA
        void AddEnd(elmtype v);
        void AddFront(elmtype v);
        void DelEnd();
        void DelFront();

        int Length();       // returns size
        int Capacity();     // returns capacity

        //void Clear();
        //void Reverse();
        elmtype Select(int k);
        //void Sort();
        //int Search(elmtype e);
        //int BinSearch(elmtype e);

        bool GetOrdered();
        int GetFront();
        int GetEnd();
        void PrintArray();
    private:
        int size;
        int capacity;
        bool ordered;
        int front = 0;      // Index of front element of array (element is not available)
        int back;           // Index of next available space at the back of array
        elmtype array[];
        void CapacityCheck();
        void ResizeUp();
        void ResizeDown();
};

// Default Constructor 
template <class elmtype> CDA<elmtype>::CDA(): size(0), capacity(1), ordered(false), back(0) {}

// Constructor for specified Size/Capacity
template <class elmtype> CDA<elmtype>::CDA(int s): size(s), capacity(s), ordered(false), back(s) {}

// Copy Constructor
// TO DO: Write a working Select function before testing this. 
template <class elmtype> CDA<elmtype>::CDA(CDA<elmtype>& v): size(v.Length()), capacity(v.Capacity()), ordered(v.GetOrdered()) {
    back = size;
    front = 0;

    elmtype * array = new elmtype[capacity];

    // elmtype array[capacity];

    //PrintArray();

    // Copy old array to new one
    for (int i=0; i<size; i++) {
        array[i] = v.Select((i+v.GetFront())%capacity);
        cout << array[i] << endl;
        //cout << v.Select((i+v.GetFront())%capacity) << endl;
    }

    PrintArray();

    //cout << "Printing array..." << endl;
    //for(int i=0; i<size; i++) {
    //    cout << array[i] << endl;
    //}
}

// Destructor for CDA Class
// TO DO: not deleting correctly. Failing main.cpp tests. ------------------------------------------
template <class elmtype> CDA<elmtype>::~CDA() { 
    // cout << "Deleting class..." << endl;
    delete[] &size;
    delete[] &capacity;
    delete[] &front;
    delete[] &back;
}

// Copy Assignment Constructor
// TO DO: ----------------------------------------------------------------------------------------


// AddEnd Function adds new element to end of array
template <class elmtype> void CDA<elmtype>::AddEnd(elmtype v) {
    CapacityCheck();
    array[back] = v;    
    back = (back+1)%capacity;   // Update back
    size++;                     // Update size
    CapacityCheck();
}

// AddFront Function adds new element to front of array
template <class elmtype> void CDA<elmtype>::AddFront(elmtype v) {
    CapacityCheck();
    front = (front-1+capacity)%capacity; // Update front
    array[front] = v;
    size++;                              // Update size
    CapacityCheck();
}

// DelEnd Function deletes the element at the end of array
template <class elmtype> void CDA<elmtype>::DelEnd() {
    back = (back-1+capacity)%capacity;  // Update back
    size--;                             // Update size
    CapacityCheck();
}

// DelFront Function deletes the element at the front of array
template <class elmtype> void CDA<elmtype>::DelFront() {
    front = (front+1)%capacity;     // Update front
    size--;                         // Update size
    CapacityCheck();
}


// Length Function
template <class elmtype> int CDA<elmtype>::Length() { return size; }

// Capacity Function
template <class elmtype> int CDA<elmtype>::Capacity() { return capacity; }

// Select Function, returns the element at index k
template <class elmtype> elmtype CDA<elmtype>::Select(int k) { return array[(k+front)%capacity]; }

// Capacity Check 
template <class elmtype> void CDA<elmtype>::CapacityCheck() {
    if(size==capacity) { ResizeUp(); }
    if(size <= (capacity/4)) { ResizeDown(); }
}

// Resize Array Up (Double capacity when size == capacity)
// TO DO: Figure out how to assign same variables to a new array ------------------------------------
template <class elmtype> void CDA<elmtype>::ResizeUp() {
    // Double new array capacity
    /*capacity = capacity*2;
    elmtype newarray[capacity];
    // Populate new array with old data
    for(int i=0; i++; i<capacity) {
        newarray[i] = array[(front+i)%capacity];
    }
    delete[] array;
    array = newarray;*/
}

// Resize Array Down (Decrease capacity by half when size is 25% of capacity)
// TO DO: ------------------------------------------------------------------------------------
template <class elmtype> void CDA<elmtype>::ResizeDown() {}

// Get the bool for if array is ordered or not (TRUE = Ordered)
template <class elmtype> bool CDA<elmtype>::GetOrdered() {
    return ordered;
}

// Returns the index of the front element (element is occupied)
template <class elmtype> int CDA<elmtype>::GetFront() {
    return front;
}

// Returns the index of the empty cell at the end of the array 
// (array is full if index of front == index of back)
template <class elmtype> int CDA<elmtype>::GetEnd() {
    return back;
}

// Prints the Dynamic Array the way the User should see it (front to back of used elements)
template <class elmtype> void CDA<elmtype>::PrintArray() {
    cout << "Printing array..." << endl;
    for(int i=0; i<size; i++) {
        cout << i << ":" << array[(front+i)%capacity] << " "; // front is index of first element
    }
    cout << "Done Printing." << endl;
}


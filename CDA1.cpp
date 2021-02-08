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
        CDA(CDA<elmtype>&);         // Copy Constructor    
        ~CDA();                     // Destructor
        
        CDA& operator=(const CDA& v);   // Copy Assignment Operator // TO DO:
        //elmtype& operator[](int i);       // TO DO:

        // Add and Delete Operations for CDA
        void AddEnd(elmtype v);
        void AddFront(elmtype v);
        void DelEnd();
        void DelFront();

        int Length();       // returns size
        int Capacity();     // returns capacity

        //void Clear();                 // TO DO:
        //void Reverse();               // TO DO:
        elmtype Select(int k);          // TO DO:
        //void Sort();                  // TO DO:
        //int Search(elmtype e);        // TO DO:
        //int BinSearch(elmtype e);     // TO DO:

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
        elmtype *array;     // Pointer to array data

        void CapacityCheck();       // Triggers ResizeUp() or ResizeDown()
        void ResizeUp();            // Double CDA capacity when CDA is full
        void ResizeDown();          // Halve CDA capacity when size is 25% of capacity  // TO DO:
        void Copy(const CDA<elmtype>& v);    
        void CopyArray(elmtype array1[], elmtype array2[], int front, int capacity);
};

// Default Constructor 
template <class elmtype> CDA<elmtype>::CDA(): size(0), capacity(1), ordered(false), back(0) {
    array = new elmtype[capacity];
}

// Constructor for specified Size/Capacity
template <class elmtype> CDA<elmtype>::CDA(int s): size(s), capacity(s), ordered(false), back(s) {
    array = new elmtype[capacity];
}

// Copy Constructor
// TO DO: Figure out why this works. Also why do i need 2 loops?????
template <class elmtype> CDA<elmtype>::CDA(CDA<elmtype>& v): size(v.Length()), capacity(v.Capacity()), ordered(v.GetOrdered()) {
    back = size;
    front = 0;

    array = new elmtype[capacity];

    Copy(v);        // Copy elements from CDA v's array to current array
}

// Destructor for CDA Class
template <class elmtype> CDA<elmtype>::~CDA() { 
    cout << "Deleting class..." << endl;
    delete[] array;     // Free the memory space
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
    if(size==capacity) { ResizeUp(); }              // Double array capacity 
    if(size <= (capacity/4)) { ResizeDown(); }      // Halve array capacity 
}

// Resize Array Up (Double capacity when size == capacity)
template <class elmtype> void CDA<elmtype>::ResizeUp() {
    elmtype *temp;  // New pointer for storing array data
    temp = array;   // Store current array in temp before resizing capacity
    capacity = capacity*2;      // Double new array capacity
    
    array = new elmtype[capacity];      // Declare new array with new capacity

    CopyArray(array, temp, front, (capacity/2));        // Copy elements from temp into array

    delete[] temp;  // Free up memory
}

// Resize Array Down (Decrease capacity by half when size is 25% of capacity)
// TO DO: ------------------------------------------------------------------------------------
template <class elmtype> void CDA<elmtype>::ResizeDown() {}

// Copy Function - copies elements from referenced CDA v to current CDA array
template <class elmtype> void CDA<elmtype>::Copy(const CDA<elmtype>& v) {
    for (int i=0; i<size; i++) {
        array[i]=v.array[(i+front)%capacity]; 
    }
}

// Copy Array Function - copies elements from array2 into array1
template <class elmtype> void CDA<elmtype>::CopyArray(elmtype array1[], elmtype array2[], int front, int capacity) {
    for (int i=0; i<size; i++) {
        array1[i]=array2[(i+front)%capacity]; 
    }
}

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
        cout << array[(front+i)%capacity] << " "; // front is index of first element
    }
    cout << "Done Printing." << endl;
}



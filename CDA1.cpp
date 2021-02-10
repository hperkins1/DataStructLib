/******************************************************************************************
 *  Data Structures Library
 *  Phase 1
 * 
 *  Author: Hannah Perkins
 *  Date: 7 February 2021
 *  Course: CS 201
 * 
 *  Function: Implement a Circular Dynamic Array Class using C++ Templates.
 * 
 *  Description: The Circular Dynamic Array is implemented as a C++ Template
 *          that can take in unknown parameter types represented by "elmtype."
 *          The class name is CDA and consists of a default constructor, constructor 
 *          with one parameter s, copy constructor, destructor, and copy 
 *          assignment constructor. The CDA class is programmed such that it 
 *          includes proper memory management.
 * 
 *          The CDA has an overloaded operator for the open and closed brackets []
 *          so that the user can manipulate data at the specified index inside the 
 *          brackets. 
 * 
 *          The User can add elements to the CDA with AddEnd() and AddFront() functions.
 *          The User can also delete elements from the back and front of the CDA with
 *          DelEnd() and DelFront(), respectively.
 *          
 *          There are also functions for returning the size and capacity of the CDA.
 *          Length() returns the current size (used elements) of the CDA and 
 *          Capacity() returns the capacity (allotted space for elements).
 * 
 *          The Clear() function frees any space currently used and starts over 
 *          with an array of size 0 and capacity 4.
 *          
 *          The Reverse() function changes the logical direction of the array in O(1)
 *          time by changing the boolean flag status of reversed when function is called.
 * 
 *          TODO: FINISH DESCRIPTION.............. 
 *          
 *          Select, Sort, Search, BinSearch
 *  
 * 
 * 
 ********************************************************************************************/

using namespace std;
#include <iostream>     // DELETE BEFORE SUBMITTING

// TODO: Test Reverse with Bracket operator 
// TODO: Add Select, Sort, Search, and BinSearch functions

/******************************************************************************************
 * Class Name:  CDA<elmtype>
 * Description: Imitates a Circular Dynamic Array using templates so that any element 
 *              type can be stored in the array
 *******************************************************************************************/
template <class elmtype> class CDA {
    public:
        CDA();                      // Default Constructor
        CDA(int s);                 // Constructor
        CDA(CDA<elmtype>&);         // Copy Constructor    
        ~CDA();                     // Destructor
        
        CDA<elmtype>& operator=(const CDA<elmtype>& v);     // Copy Assignment Operator 
        elmtype& operator[](int i);                         // Overloaded Brackets Operator

        // Add and Delete Operations for CDA
        void AddEnd(elmtype v);
        void AddFront(elmtype v); 
        void DelEnd();  
        void DelFront();

        // Other User Functions
        int Length();               // returns size
        int Capacity();             // returns capacity
        void Clear();               // Set size to 0 and capacity to 4
        void Reverse();             // changes logical direction of array

        // Sort, Search, and Select User Functions
        //elmtype Select(int k);        // TO DO:
        //void Sort();                  // TO DO:
        //int Search(elmtype e);        // TO DO:
        //int BinSearch(elmtype e);     // TO DO:

        // Prints CDA as User sees it
        void PrintArray();

    private:
        // Private Variables
        int size;                   // Number of elements used so far in CDA
        int capacity;               // Number of total elements allocated in memory for CDA
        bool ordered;               // TRUE = Ordered, FALSE = Unordered
        bool reversed;              // TRUE = User sees array in reverse order
        int front = 0;              // Index of front element of array
        int back;                   // Index of next available space at the back of array
        elmtype *array;             // Pointer to array data

        // Helper Functions
        void CapacityCheck();       // Triggers ResizeUp() or ResizeDown()
        void ResizeUp();            // Double CDA capacity when CDA is full
        void ResizeDown();          // Halve CDA capacity when size is 25% of capacity

        // Copy Functions
        void Copy(const CDA<elmtype>& v);
        void CopyArray(elmtype* array1, const elmtype* array2, int front, int capacity, bool reversed);

        // Getter Functions
        bool GetOrdered();
        bool GetReversed();
        int GetFront();
        int GetEnd();
};

// Default Constructor 
template <class elmtype> CDA<elmtype>::CDA(): size(0), capacity(1), ordered(false), reversed(false), back(0) {
    array = new elmtype[1];
}

// Constructor for specified Size/Capacity
template <class elmtype> CDA<elmtype>::CDA(int s): size(s), capacity(s), ordered(false), reversed(false), back(0) {
    if(s==0) { capacity=1; }            // Prevents creating an array with capacity 0
    array = new elmtype[capacity];
}

// Copy Constructor
template <class elmtype> CDA<elmtype>::CDA(CDA<elmtype>& v): size(v.Length()), capacity(v.Capacity()), ordered(v.GetOrdered()), reversed(v.GetReversed()) {
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

// Copy Assignment Operator
template <class elmtype> CDA<elmtype>& CDA<elmtype>::operator=(const CDA& v) {
    // If array pointers point to same data, then skip the if statement because they are already equal
    if(array != v.array) {
        // Free old memory space first
        delete[] array; 

        // Copy variables
        back = v.back;
        front = v.front;
        capacity = v.capacity;
        size = v.size;
        ordered = v.ordered;
        reversed = v.reversed;

        // Allocate space for new array
        array = new elmtype[capacity];

        // Copy v's array into array
        Copy(v);
    }
    return *this;
}

// Overloaded Brackets Operator [] 
template <class elmtype> elmtype& CDA<elmtype>::operator[](int i) {
    if(reversed) {
        return array[(back-1-i+capacity)%capacity];
    }
    else {
        return array[(i+front)%capacity];
    }
}

/******************************************************************************************
 * Function Name:       AddEnd
 * Input Parameters:    elmtype v -  Represents unknown element type to add to end of array
 * Return Value:        void
 * Purpose:             Add an element of any type to the end of the CDA
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::AddEnd(elmtype v) {
    CapacityCheck();

    // Check if reverse flag is true: Call AddFront instead
    if (reversed) {
        reversed = false;   // Turn off Flag so AddFront() will execute
        AddFront(v);
        reversed = true;    // Reset flag to on
        return;             // Exit AddEnd()
    }

    // Add v to back of array
    array[back] = v; 

    // Update Back and size
    if(Capacity()!=1) { back = (back+1)%capacity; }
    size++;
}

/******************************************************************************************
 * Function Name:       AddFront
 * Input Parameters:    elmtype v - Represents unknown element type to add to front of array
 * Return Value:        void
 * Purpose:             Add an element of any type to the front of the CDA
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::AddFront(elmtype v) {
    CapacityCheck();

    // Check if reverse flag is true: Call AddEnd instead
    if (reversed) {
        reversed = false;   // Turn off Flag so AddEnd() will execute
        AddEnd(v);
        reversed = true;    // Reset Flag to on
        return;             // Exit AddFront()
    }

    front = (front-1+capacity)%capacity; // Update front
    array[front] = v;
    size++;                              // Update size
}

/******************************************************************************************
 * Function Name:       DelEnd
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Remove the element at the back of the array
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::DelEnd() {
    // Check if reverse flag is true: Call DelFront instead
    if (reversed) {
        reversed = false;   // Turn off flag so DelFront will execute
        DelFront();
        reversed = true;    // Reset Flag to on
        return;             // Exit DelEnd
    }
    
    back = (back-1+capacity)%capacity;  // Update back
    size--;                             // Update size
    CapacityCheck();
}

/******************************************************************************************
 * Function Name:       DelFront
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Remove the element at the front of the array
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::DelFront() {
    // Check if reverse flag is true: Call DelEnd instead
    if (reversed) {
        reversed = false;   // Turn off flag so DelEnd will execute
        DelEnd();
        reversed = true;    // Reset Flag to on
        return;             // Exit DelFront
    }

    front = (front+1)%capacity;     // Update front
    size--;                         // Update size
    CapacityCheck();
}

/******************************************************************************************
 * Function Name:       Length
 * Input Parameters:    void
 * Return Value:        int
 * Purpose:             Returns the current size of the used portion of the array
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::Length() { return size; }

/******************************************************************************************
 * Function Name:       Capacity
 * Input Parameters:    void
 * Return Value:        int
 * Purpose:             Returns the capacity of the total alloted space for the array
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::Capacity() { return capacity; }

/******************************************************************************************
 * Function Name:       Clear
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Frees any memory/space currently used and starts over with an array
 *                      of size 0 and capacity 4
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::Clear() {
    delete[] array;     // Free up memory

    // Set new Variables 
    size = 0;
    capacity = 4;
    ordered = false;
    reversed = false;
    back = 0;
    front = 0;
    array = new elmtype[capacity];
}

/******************************************************************************************
 * Function Name:       Reverse
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Changes logical direction of the array in O(1) time by changing 
 *                      status of Reversed bool
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::Reverse() { reversed = !GetReversed(); }

/******************************************************************************************
 * Function Name:       Select
 * Input Parameters:    
 * Return Value:        
 * Purpose:             
 * 
 * 
 *******************************************************************************************/
// Select Function, returns the element at index k
// TO DO: Redo so that it performs a quickselect to get smallest element k. (Not meant to access the kth element.)
//template <class elmtype> elmtype CDA<elmtype>::Select(int k) { return array[(k+front)%capacity]; }

/******************************************************************************************
 * Function Name:       Sort
 * Input Parameters:    
 * Return Value:        
 * Purpose:             
 * 
 * 
 *******************************************************************************************/

/******************************************************************************************
 * Function Name:       Search
 * Input Parameters:    
 * Return Value:        
 * Purpose:             
 * 
 * 
 *******************************************************************************************/
/******************************************************************************************
 * Function Name:       BinSearch
 * Input Parameters:    
 * Return Value:        
 * Purpose:             
 * 
 * 
 *******************************************************************************************/


/******************************************************************************************
 * Function Name:       PrintArray
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Prints the CDA as the user should see it (front to back)
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::PrintArray() {
    cout << "Printing array..." << endl;

    // Check if Reversed, then start from back
    if(GetReversed()) {
        for(int i=size; i>0; i--) {
            cout << array[(front+i-1)%capacity] << " "; // back is first index of first element
        }
    }

    // If Array isn't reversed, start from front
    else {
        for(int i=0; i<size; i++) {
            cout << array[(front+i)%capacity] << " "; // front is index of first element
        }
    }

    cout << endl << "Done Printing." << endl;
}

/******************************************************************************************
 * Function Name:       CapacityCheck
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Checks the current capacity and triggers the ResizeUp function if 
 *                      array is full or ResizeDown function if array is 1/4 or less full
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::CapacityCheck() {
    if(size==capacity) { ResizeUp(); }                          // Double array capacity 
    if(size <= (capacity/4) && size > 0) { ResizeDown(); }      // Halve array capacity 
}

/******************************************************************************************
 * Function Name:       ResizeUp
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Doubles array capacity and copies old array data into new array
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::ResizeUp() {
    // Create temp to store old array ptr
    elmtype *temp;              
    temp = array;               
    
    // Update to new capacity and declare new array with new capacity
    capacity = capacity*2;    
    array = new elmtype[capacity];

    // Copy elements from temp into array
    CopyArray(array, temp, front, (capacity/2), reversed);       

    // Free up memory by deleting old array
    delete[] temp;

    // Set Variables since new front is 0 and copies of reversed arrays are no longer reversed
    front = 0;
    back = size;
    reversed = false;
}

/******************************************************************************************
 * Function Name:       ResizeDown
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Halves array capacity and copies old array data into new array
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::ResizeDown() {
    // Create temp to store old array ptr
    elmtype *temp;              
    temp = array;               
    
    // Update to new capacity and declare new array with new capacity
    capacity = capacity/2;    
    array = new elmtype[capacity];

    // Copy elements from temp into array
    CopyArray(array, temp, front, (capacity*2), reversed);       

    // Free up memory by deleting old array
    delete[] temp;

    // Set Variables since new front is 0 and copies of reversed arrays are no longer reversed
    front = 0;
    back = size;
    reversed = false;
}

/******************************************************************************************
 * Function Name:       Copy
 * Input Parameters:    const CDA& v - reference to CDA object to make a copy from
 * Return Value:        void
 * Purpose:             Copies elements from referenced CDA v to current CDA array
 * NOTE:                Different than CopyArray since it copies another reference CDA's array 
 *                      rather than making a copy of it's own CDA array within the current object
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::Copy(const CDA<elmtype>& v) {
    // Copy v's elements into current CDA
    
    // Check for v's Reverse Flag and copy array in reverse order if true
    if(reversed) {
        for (int i=size; i>0; i--) {
            array[i-1]=v.array[(v.back-1+i)%v.capacity];
        }
    }
    
    // Array isn't reversed, do a normal copy from front to back
    else {
        for (int i=0; i<size; i++) {
            array[i]=v.array[(i+v.front)%v.capacity]; 
        }
    }

    // Update front and back variables since copied array starts at index 0
    front = 0; 
    back = size;
}

/******************************************************************************************
 * Function Name:       CopyArray
 * Input Parameters:    elmtype* array1 - ptr to array to copy to location
 *                      const elmtype* array2 - ptr to array to copy from location
 *                      int front - array2's front element
 *                      int capacity - capacity of array2
 *                      bool reversed - flag for whether user should see reverse of array
 * Return Value:        void
 * Purpose:             Copies the elements from array2 to array1. Works on differently sized
 *                      arrays. Triggered by ResizeUp and ResizeDown functions
 * NOTE:                Different from Copy in that it copies the array already used in the
 *                      current object into a new array of the same current CDA object
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::CopyArray(elmtype* array1, const elmtype* array2, int front, int capacity, bool reversed) {
    // Check for array2's reverse flag and copy array in reverse order if true
    if(reversed) {
        for (int i=size; i>0; i--) {
            array1[size-i] = array2[(front+i-1)%capacity];
        }
    }

    // If reverse is false, then just a regular array copy 
    else {
        for (int i=0; i<size; i++) {
            array1[i]=array2[(i+front)%capacity]; 
        }
    }
}

/******************************************************************************************
 * Function Name:       GetOrdered
 * Input Parameters:    void
 * Return Value:        bool
 * Purpose:             Returns the status of the Ordered bool flag (TRUE = ordered)
 *                      (FALSE = unordered)
 *******************************************************************************************/
template <class elmtype> bool CDA<elmtype>::GetOrdered() {
    return ordered;
}

/******************************************************************************************
 * Function Name:       GetReversed
 * Input Parameters:    void
 * Return Value:        bool
 * Purpose:             Returns the status of the Reversed bool flag (TRUE = Reverse order)
 *                      (FALSE = normal order)
 *******************************************************************************************/
template <class elmtype> bool CDA<elmtype>::GetReversed() {
    return reversed;
}

/******************************************************************************************
 * Function Name:       GetFront
 * Input Parameters:    void
 * Return Value:        int
 * Purpose:             Returns the index of the front element 
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::GetFront() {
    return front;
}

/******************************************************************************************
 * Function Name:       GetEnd
 * Input Parameters:    void
 * Return Value:        int
 * Purpose:             Returns the index of the back element (if array is full, front = back)
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::GetEnd() {
    return back;
}





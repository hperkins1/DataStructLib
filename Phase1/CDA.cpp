/******************************************************************************************
 *  Data Structures Library
 *  Phase 1
 * 
 *  Author:     Hannah Perkins
 *  Date:       7 February 2021
 *  Course:     CS 201
 * 
 *  Function:   Implement a Circular Dynamic Array Class using C++ Templates.
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
 *          The Select() function performs a QuickSelect algorithm to return the kth 
 *          smallest element of the array.
 * 
 *          The Sort() function sorts the array in O(nlgn) time by using MergeSort
 *          
 *          There are 2 search functions: Search() and BinSearch(). Search() does a 
 *          linear search for the desired element whereas BinSearch() performs a 
 *          binary search on a sorted array. If the element isn't found, it returns -1.
 *  
 ********************************************************************************************/

using namespace std;
#include <iostream>
#include <cstdlib>


/******************************************************************************************
 * Class Name:  CDA<elmtype>
 * Description: Imitates a Circular Dynamic Array using templates so that any element 
 *              type can be stored in the array
 *******************************************************************************************/
template <class elmtype> class CDA {
    public:
        CDA();                      // Default Constructor
        CDA(int s);                 // Constructor
        CDA(const CDA<elmtype>&);   // Copy Constructor    
        ~CDA();                     // Destructor

        void operator()(const CDA<elmtype>& v);             // Copy () Operator
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
        elmtype Select(int k);        // QuickSelect function returns kth smallest value
        void Sort();                  // Sorts array in ascending order (smallest at front)
        int Search(elmtype e);        // Linear Search for elmtype e
        int BinSearch(elmtype e);     // Binary Search on ordered array for elmtype e

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
        elmtype *dummy;              // Dummy Variable for out of bounds calls for [] operator

        // Helper Functions
        void CapacityCheck();       // Triggers ResizeUp() or ResizeDown()
        void ResizeUp();            // Double CDA capacity when CDA is full
        void ResizeDown();          // Halve CDA capacity when size is 25% of capacity

        // Copy Functions
        void Copy(const CDA<elmtype>& v);
        void CopyArray(elmtype* array1, const elmtype* array2, int front, int capacity, bool reversed);

        // Select Helper Functions
        int Partition(int left, int right);
        void Swap(elmtype* array, int index1, int index2);
        int QuickSelect(int left, int right, int k);

        // Sort Helper Functions
        void Merge(elmtype* array, int left, int middle, int right);
        void MergeSort(elmtype* array, int left, int right);

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
template <class elmtype> CDA<elmtype>::CDA(const CDA<elmtype>& v) {
    // Copy Variables
    size = v.size;
    capacity = v.capacity;
    ordered = v.ordered;
    reversed = v.reversed;
    back = size;
    front = 0;

    array = new elmtype[capacity];

    // Copy elements from CDA v's array to current array
    Copy(v);        
}

// Destructor for CDA Class
template <class elmtype> CDA<elmtype>::~CDA() { 
    delete[] array;     // Free the memory space
}

// Copy () Operator
template <class elmtype> void CDA<elmtype>::operator()(const CDA<elmtype>& v) {
    // Free up memory
    delete[] array;

    // Copy variables
    size = v.size;
    capacity = v.capacity;
    ordered = v.ordered;
    reversed = v.reversed;
    back = size;
    front = 0;

    // Copy Array    
    array = new elmtype[capacity];

    Copy(v);
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
    if(i > size) {
        cout << "ERROR: Out of bounds reference (0..." << (size-1) << ")" << endl;
        return array[-1];
    }
    
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
    ordered = false;
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
    ordered = false;
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
    ordered = false;
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
    ordered = false;
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
template <class elmtype> void CDA<elmtype>::Reverse() { 
    reversed = !GetReversed(); 
    if(reversed) { ordered = false; }
}

/******************************************************************************************
 * Function Name:       Select
 * Input Parameters:    int k - kth smallest element to find
 * Return Value:        elmtype - represents the kth smallest element in the array
 * Purpose:             Performs a Quickselect algorithm to return the kth smallest element 
 *                      in the array. Chooses a random partition element for Quickselect.
 * NOTE:                This function rearranges the values in the array.
 *******************************************************************************************/
template <class elmtype> elmtype CDA<elmtype>::Select(int k) { 
    // Check if k is in bounds
    if((k > size) || (k < 1)) { 
        cout << "ERROR: out of bounds reference (1..." << size << ")" << endl;
        return array[-1]; 
    }

    // Check if ordered
    // NOTE: All ordered arrays are reversed=false due to sort function
    if(GetOrdered()) { return array[(front+k-1)%capacity]; }    

    // Create left and right variables to how user sees array
    int left = 0;
    int right = size-1;

    // Call QuickSelect function to calculate index
    // Note: Need to call k-1 since kth element is at k-1 index
    int index = QuickSelect(left, right, k-1);

    // Return item from where it is stored in array memory
    return array[(index+front)%capacity];
}

/******************************************************************************************
 * Function Name:       Partition
 * Input Parameters:    int left - front index of partition set
 *                      int right - last index of partition set
 * Return Value:        int - represents a potential index for kth smallest element
 * Purpose:             Creates a random pivotIndex and partitions the array with the 
 *                      values smaller than the pivot to the left of the partitionIndex
 *                      and elements larger than the pivot are stored to the right of the 
 *                      partitionIndex
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::Partition(int left, int right) {
    // Partition Index starts at front of the array and keeps track of tail of smallest elements
    int partitionIndex = left;

    // Select a random pivot index from available indices between left and right
    int pivotIndex = rand() % (right - left + 1) + left;

    // Start Pivot at the random pivotIndex
    elmtype pivot = array[(pivotIndex+front)%capacity];

    // Swap the pivot with the element at Right so pivot will be at end of subarray
    Swap(array, (pivotIndex+front)%capacity, (right+front)%capacity); 

    // Starting at left side of subarray, check if each element is less than pivot
    for(int i=left; i<right; i++) {
        if(array[(front+i)%capacity] <= pivot) {
            // Move elements less than pivot to left of the array with swap function
            Swap(array, (front+i)%capacity, (partitionIndex+front)%capacity);
            partitionIndex++;
        }
    }

    // Swap the pivot back into the subarray at partitionIndex;
    Swap(array, (partitionIndex+front)%capacity, (right+front)%capacity);

    // Found PartitionIndex
    return partitionIndex;
}

/******************************************************************************************
 * Function Name:       Swap
 * Input Parameters:    elmtype* array - pointer to array in memory
 *                      int index1 - index of 1st element to swap
 *                      int index2 - index of element to swap with 
 * Return Value:        void 
 * Purpose:             Swaps 2 elements with eachother in the array memory
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::Swap(elmtype* array, int index1, int index2) {
    // Declare temp variable to hold old array index 1
    elmtype temp = array[index1];

    // Swap elements
    array[index1] = array[index2];
    array[index2] = temp;
}

/******************************************************************************************
 * Function Name:       QuickSelect
 * Input Parameters:    int left - front index to select from
 *                      int right - last index to select from
 *                      int k - the kth smallest element
 * Return Value:        int - Represents a potential index of kth smallest element of array
 * Purpose:             Performs a Quickselect algorithm to return the kth smallest element 
 *                      in the array. Calls the Partition function to get a potential index
 *                      for kth smallest element
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::QuickSelect(int left, int right, int k) {
    // only run while array is size 1 and larger
    if (left <= right) {
        // Call PartitionIndex to calculate new partition
        int partitionIndex = Partition(left, right);

        // If partitionIndex is k then the kth smallest element has been found
        if (k == partitionIndex) { return k; }

        // If k is less than partitionIndex then try QuickSelect function again at the left side of array
        if (k < partitionIndex) {
            return QuickSelect(left, (partitionIndex - 1), k);
        }
        
        // If k is greater than partitionIndex, then try QuickSelect function again at right side of array
        else {
            return QuickSelect((partitionIndex + 1), right, k);
        }
    }

    // Element not found --> Out of Bounds error
    else { 
        cout << "ERROR: Element not found" << endl;
        return -1; 
    }
}

/******************************************************************************************
 * Function Name:       Sort
 * Input Parameters:    void
 * Return Value:        void
 * Purpose:             Sorts the array in O(nlgn) time in ascending order (smallest at front
 *                      and largest elements at back). Sort method chosen is MergeSort.
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::Sort() { 
    // Check if reversed array, and update flag
    if (GetReversed()) { reversed = false; }

    // Declare indices for sorted array
    int left = 0;
    int right = size-1;

    // Call MergeSort function
    MergeSort(array, left, right);

    // Set Ordered flag to true
    ordered = true;
}

/******************************************************************************************
 * Function Name:       MergeSort
 * Input Parameters:    elmtype* array - pointer to CDA array data in memory
 *                      int left - left index of partitioned array
 *                      int right - right index of partitioned array
 * Return Value:        void
 * Purpose:             Recursively partitions and calls Merge function on the CDA to sort
 *                      array in smaller partitions until ultimately merging entire array.
 *                      This function also calculates the middle index and stops partitioning
 *                      once array is size 1 or 2.
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::MergeSort(elmtype* array, int left, int right) { 
    // Check that array partitions aren't smaller than 1 element
    if (left >= right) { return; }

    // Calculate middle
    int middle = (left + right)/2;

    // Continue Splittle arrays into smaller partitions recursively
    MergeSort(array, left, middle);
    MergeSort(array, (middle+1), right);

    // Call Merge to sort and merge all divided arrays into 1 sorted array
    Merge(array, left, middle, right);
}

/******************************************************************************************
 * Function Name:       Merge
 * Input Parameters:    elmtype* array - pointer to CDA array data in memory
 *                      int left - left index of partitioned array
 *                      int middle - middle index of partitioned array
 *                      int right - right index of partitioned array
 * Return Value:        void
 * Purpose:             Sorts the partitioned array in ascending order by creating 2 temp 
 *                      arrays to store data during comparison of element values.
 *******************************************************************************************/
template <class elmtype> void CDA<elmtype>::Merge(elmtype* array, int left, int middle, int right) { 
    // Create temp arrays
    elmtype* temp1;
    elmtype* temp2;
    int temp1Size = (middle-left+1);
    int temp2Size = (right-middle);
    temp1 = new elmtype[temp1Size];
    temp2 = new elmtype[temp2Size];

    // Copy data to temp arrays
    for (int i=0; i<temp1Size; i++) {
        // front-left+capacity is the offset from the the array's storage in memory
        temp1[i]=array[(i+front+left+capacity)%capacity];
    }
    for (int i=0; i<temp2Size; i++) {
        temp2[i]=array[(middle+1+i+front+capacity)%capacity];
    }

    // Declare new indices i and j to compare elements
    int i=0;
    int j=0;
    int index = left;

    // Merge temp1 and temp2 into sorted array
    // Compare values between temp1 and temp2
    while((i<temp1Size) && (j<temp2Size)) {
        // Take and place smaller element 
        if (temp1[i] <= temp2[j]) {
            array[(index+front)%capacity] = temp1[i];
            i++;
        }
        else {
            array[((index+front)%capacity)] = temp2[j];
            j++;
        }
        index++;
    }

    // Copy remaining elements of temp1 once temp2 is empty
    while(i<temp1Size) {
        array[(index+front)%capacity] = temp1[i];
        i++;
        index++;
    }

    // Copy remaining elements of temp2 once temp1 is empty
    while(j<temp2Size) {
        array[(index+front)%capacity] = temp2[j];
        j++;
        index++;
    }

    // Free up memory
    delete[] temp1;
    delete[] temp2;
}

/******************************************************************************************
 * Function Name:       Search
 * Input Parameters:    elmtype e - element that user is searching for
 * Return Value:        int - represents the index of where the element is in the array
 * Purpose:             Performs a linear search on the circular array to find the element
 *                      e and returns the index of where e is at. Index is the index of
 *                      how the user sees the array, not the actual index of how the 
 *                      array is stored in memory. 
 * Note:                Used for unsorted arrays
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::Search(elmtype e) { 
    // Loop through array starting at front
    // Check if Reversed, then start from back
    if(GetReversed()) {
        for(int i=size; i>0; i--) {
            if(array[(front+i-1)%capacity] == e) { return (size-i); }
        }
    }

    // If Array isn't reversed, start from front
    else {
        for(int i=0; i<size; i++) {
            if(array[(front+i)%capacity] == e) { return i; }
        }
    }

    // If element isn't found, return -1
    return -1;
}

/******************************************************************************************
 * Function Name:       BinSearch
 * Input Parameters:    elmtype e - element that user is searching for
 * Return Value:        int - represents the index of where the element is in the array
 * Purpose:             Performs a binary search on the CDA to find the element e and returns
 *                      the index of where e is at. Index is from where the user sees the 
 *                      element at in the array, not the actual index of how the array's 
 *                      elements are stored in memory.
 * Note:                Used for sorted arrays
 *******************************************************************************************/
template <class elmtype> int CDA<elmtype>::BinSearch(elmtype e) { 
    // Array should be sorted
    // Declare variables for index partitions as user sees it
    // How it's actually stored:
    // int left = front;
    // int right = (front + size) % capacity;

    int left = 0;
    int right = size - 1;

    while (right >= left) { 
        // int middle = (front + (size / 2)) % capacity;
        int middle = (left + right) / 2;

        // REVERSED Arrays TODO: Make this work for Reversed Arrays 
        // These are seen as smallest to largest to user but actually stored as largest to smallest
        if(GetReversed()){
            // Check Middle Element
            if(array[(front+capacity-middle)%capacity] == e) {
                // Need to reverse it again by "size - 1" - actual index to reflect what user sees
                int index = size - 1 - ((front+capacity-middle)%capacity);
                return (index);
            }

            // If Middle Element is smaller than e, then move to left half of partition and update right
            if(array[(front-middle+capacity)%capacity] > e) {
                right = middle - 1;
            }

            // Else if Middle Element is larger than e, then move to right half of partition and update left
            else {
                left = middle + 1;
            }
        }

        // NORMAL Non-Reversed Arrays
        // User and memory store these from smallest to largest
        else {
            // Check Middle Element
            if(array[(middle+front)%capacity] == e) { 
                return ((middle)%capacity); 
            }

            // If Middle Element is larger than e, then move to left half of partition and update right
            if(array[(middle+front)%capacity] > e) {
                right = middle - 1;
            }

            // Else if Middle Element is smaller than e, then move to right half of partition and update left
            else {
                left = middle + 1;
            }
        }
    }
    
    // If element isn't found, return -1
    return -1;
}

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

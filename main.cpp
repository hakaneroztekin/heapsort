// In this project, we'll report employee's best/worst performance based on their max/min # of calls.
// Use dataset given (day1-10)
// Performance formula: PS = 2 * (number of calls) + (number of positive feedback) – (number of negative feedback)
// numbers.csv will be used for another purpose later.
//
// Implementation Details
// Implement the following;
//  max/min-heapify()
//	build - max / min - heap()
//	heapsort()
//	insert()
//	extract - max / min()
//	increase - key()
//
//  Step by Step (According to the pdf file)
// 1- Construct heaps using data in day1.csv
// 2- Then update heap using the consecutive files (First read, then update)
//	  > If employee ID already present; you're going to use increase-key() (check pdf for details)
//	  > Else, use insert()
// * Since the employee ID is in ascending order, if an ID is larger than the ones previously encountered, 
//	 this ID should be considered as a new ID(not in the heaps).
// 3- Report the details as detailed in the pdf file.
//
// Implementation Step (Interpreted by me)
// 1- Read the csv file (implement necessary methods)
// 2- Create proper heaps after the reading.
//	  > For that, implement necessary heap methods (decide which one's needed at this step)
// 3- Read consecutive files and update heaps
//	  > For that, implement necessary heap methods (decide which one's needed at this step)
// 4- Implement print operation (reporting).
// Then, prepare the analysis.


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include "IOActions.h"
using namespace std;

/*
>> Heap metodlarını (v1) implement ettim.
>> Metotlarda düzeltmeler elbet gerekicek. Özellikle A'yı sürekli yollamakla ilgili (arrPtr kullanmak daha iyi olabilir.) sorun çıkabilir..
>> Step 1'den dvm;
Step 1 - Main ve IOActions'u bu proje için özelleştir.
		 So that you can read csv files.
		 (you'll implement reading them consecutively later on, not now.)
*/

int main(){
	/*int size;
	size = atoi(argv[6]); // convert the char* to integer pointer, size is N.
	string** arrayToBeSortedPtr = new string*[size]; // initialize the 2D array
	for (int i = 0; i < size; ++i)
		arrayToBeSortedPtr[i] = new string[42];

	// cout << "Arguments: " << argv[2] << " " << argv[4] << " " << argv[6] << endl;
	IOActions ioAction;
	// ifstream & dataFile = ioAction.getDataFile();
	ioAction.openFile();*/
	ioAction.readFile(size); // read first N lines 

	Sorting *sortingRequest = new Sorting(*argv[2], *argv[4], size, arrayToBeSortedPtr);
	if (!sortingRequest->sortTheRequest(arrayToBeSortedPtr))
		cout << "Sorting Request is successful!" << endl;
	else
		cout << "Sorting Request failed!" << endl;




	ioAction.closeFile();


	return 0;
}



/*
Heap Algoritmaları

MAX-HEAPIFY(A, i)
BUILD-MAX-HEAP(A)
HEAPSORT(A)
HEAP-MAXIMUM(A)
HEAP-EXTRACT-MAX(A)
HEAP-INCREASE-KEY(A, i, key)
MAX-HEAP-INSERT(A,key)

MAX-HEAPIFY(A, i)
1 l ← LEFT(i)
2 r ← RIGHT(i) ; largest ← i
3 if l ≤ heap-size[A] and A[l] > A[i]
4 then largest ← l
5 else largest ← i
6 if r ≤ heap-size[A] and A[r] > A[largest]
7 then largest ← r
8 if largest ≠ i
9 then exchange A[i] ↔ A[largest]
10 MAX-HEAPIFY(A, largest)


BUILD-MAX-HEAP(A)
1 heap-size[A] ← length[A]
2 for i ← floor(length[A]/2) downto 1
3 do MAX-HEAPIFY(A, i)


HEAPSORT(A)
1 BUILD-MAX-HEAP(A)
2 for i ← length[A] downto 2 do
3 exchange A[1] ↔ A[i]
4 heap-size[A] ← heap-size[A] – 1
5 MAX-HEAPIFY(A, 1)


HEAP-MAXIMUM(A)
1 return A[1]

HEAP-EXTRACT-MAX(A)
1 if heap-size[A] < 1
2 then error “heap underflow”
3 max ← A[1]
4 A[1] ← A[heap-size[A]]
5 heap-size[A] ← heap-size[A] - 1
6 MAX-HEAPIFY(A,1)
7 return max

HEAP-INCREASE-KEY(A, i, key)
1 if key < A[i]
2 then error “new key is smaller than
current key”
3 A[i] ← key
4 while i > 1 and A[PARENT(i)] < A[i] do
5 exchange A[i] ↔ A[PARENT(i)]
6 i ← PARENT(i)

MAX-HEAP-INSERT(A,key)
1 heap-size[A] ← heap-size[A] + 1
2 A[heap-size] ← -∞
3 HEAP-INCREASE-KEY(A, heap-size[A], key)

*/
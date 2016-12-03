#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

void print(int array[], unsigned int size) {
  const char* delimiter = "";
  printf("[");
  for (unsigned int i = 0; i < size; ++i) {
    printf("%s", delimiter);
    printf("%i", array[i]);
    delimiter = " ";
  }
  printf("]\n");
}


void generate(int array[], unsigned int size) {
  for (unsigned int i = 0; i < size; ++i) {
    array[i] = rand();
  }
}


void copyArray(int array[], int copy[], unsigned int size) {
  for (unsigned int i = 0; i < size; ++i) {
    copy[i] = array[i];
  }
}


bool compare(int A[], int B[], unsigned int size) {
  for (unsigned int i = 0; i < size; ++i) {
    if (A[i] != B[i]) {
      return false;
    }
  }
  return true;
}


void insertionSort(int array[], unsigned int size) {
  for (unsigned int i = 1; i < size; ++i) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      int temp = array[j];
      array[j] = key;
      array[j + 1] = temp;
      --j;
    }
  }
}


void merge(
  int left[],
  int right[],
  size_t left_size,
  size_t right_size,
  int output[]) {	
    size_t l = 0, r = 0, k = 0;
	while (l < left_size && r < right_size) {
      if (left[l] < right[r]) {
        output[k] = left[l];
        ++l;
      } else {
          output[k] = right[r];
          ++r;
		}
      ++k;
	}	
    if (l == left_size) {
      while (r < right_size) {
        output[k] = right[r];
        ++r;
        ++k;
      }
	}	
	if (r == right_size) {
      while (l < left_size) {
        output[k] = left[l];
        ++l;
        ++k;
      }
	}
} 


void mergeSortM(int array[], size_t size) {
  if (size < 16) {
    insertionSort(array,size);
	return;
  }	
  size_t left_size = size / 2;
  size_t right_size = size - left_size;	
  int left[left_size];
  int right[right_size];	
  for (size_t i = 0; i < left_size; ++i) {
    left[i] = array[i];
  }	
  for (size_t i = 0; i < right_size; ++i) {
    right[i] = array[i + left_size];
  }	
  mergeSortM(left, left_size);
  mergeSortM(right, right_size);
  merge(left, right, left_size, right_size, array);
}


void mergeSort(int array[], size_t size) {
  if (size < 2) {	
    return;
  }	
  size_t left_size = size / 2;
  size_t right_size = size - left_size;	
  int left[left_size];
  int right[right_size];	
  for (size_t i = 0; i < left_size; ++i) {
    left[i] = array[i];
  }	
  for (size_t i = 0; i < right_size; ++i) {
    right[i] = array[i + left_size];
  }
	
  mergeSort(left, left_size);
  mergeSort(right, right_size);
  merge(left, right, left_size, right_size, array);
}


bool moreCriteria(int a, int b) {
  return ( a < b );
}

//////////////////////////////////////////////

int main(int argc, char** argv) {
	
  clock_t start, start1, start2, start3, start4, elapsed, elapsed1, elapsed2, elapsed3, elapsed4;
  double seconds,seconds1,seconds2, seconds3, seconds4;    
  printf ("\t SIZE\tInsertion    Merge      Merge*    std::sort\n ");    
	
  while (seconds < 5) {
  	start = clock();	
    size_t size = 10000 + rand() % 50000;    
    int A[size], Sort[size], MergeM[size], Insert[size];
	srand(time(NULL)); 
    generate(A, size);  
    copyArray(A, Sort, size);
	copyArray(A, MergeM, size);
	copyArray(A, Insert, size);	

	{ 
	  start1 = clock();
      insertionSort(Insert, size);
      elapsed1 = clock() - start1;
	  seconds1 = (double) elapsed1 / CLOCKS_PER_SEC;
	}
   
    {  
	   start2 = clock();
       mergeSort(A, size);
       elapsed2 = clock() - start2;
	   seconds2 = (double) elapsed2 / CLOCKS_PER_SEC;
    } 
	
    { 
	  start3 = clock();
      mergeSortM(MergeM, size);
      elapsed3 = clock() - start3;
	  seconds3 = (double) elapsed3 / CLOCKS_PER_SEC;
	}
  
    { 
	  start4 = clock(); 
      std::sort(Sort, Sort + size, moreCriteria);
      elapsed4 = clock() - start4;
  	  seconds4 = (double) elapsed4 / CLOCKS_PER_SEC;
    }
     
	elapsed = clock() - start;
    seconds = (double) elapsed / CLOCKS_PER_SEC;	
    printf ("\t%5.0i    %.5f    %.5f    %.5f    %.5f \n", size, seconds1, seconds2, seconds3, seconds4); 
    ++seconds;	
  }
   
  printf ("\n\n\t\t\tT I M E   I S   O U T\n\n");
  return 0;
}

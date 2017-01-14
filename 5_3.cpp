#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cmath>

///std sort ascending
///merge ascending


struct Point {
	
  float x;
  float y;
	
};


Point generate(Point &points) {
  
  points.x = 0.01 * (rand()%100);
  points.y = 0.01 * (rand()%100);   

}

Point generate(Point points[], unsigned int size) {
  for (unsigned int i = 0; i < size; ++i) {		
    generate(points[i]) ;
  }	
  return points[size];
}


float distance(Point A, Point B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}


bool operator < (Point A, Point B) {
  Point ZERO = {0.0, 0.0};
  return distance(A, ZERO) < distance(B, ZERO);
}
 
 
bool operator > (Point A, Point B) {
  Point ZERO = {0.0, 0.0};
  return distance(A, ZERO) > distance(B, ZERO);
}

bool operator == (Point A, Point B) {
  Point ZERO = {0.0, 0.0};
  return distance(A, ZERO) == distance(B, ZERO);
}


void merge(	Point left[], Point right[], size_t left_size, size_t right_size, Point output[]) {
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

void mergeSort(Point array[], size_t size) {
  if (size < 2) {
    return;
  }	
  size_t left_size = size / 2;
  size_t right_size = size - left_size;	
  Point left[left_size];
  Point right[right_size];
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


void print(Point point) {
  printf("(%.2f, %.2f)", point.x, point.y);
}

void print(Point points[], size_t size) {
  printf("[");
  const char* delimiter = "";
  for (size_t i = 0; i < size; ++i) {
    printf("%s", delimiter);
    print(points[i]);
    delimiter = " ";
  }
  printf("]\n");
}


bool moreCriteria(Point A, Point B) {
  return  A < B;
}


Point copyPoints(Point points[], Point copyPoint[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    copyPoint[i] = points[i];
  }
  return copyPoint[size];
}


bool compare(Point A[], Point B[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    if (A[i] == B[i]) {
      return true;
    }
  }
  return false;
}


///////////////////////////////////////////////////


int main(int argc, char** argv) {
  while(true) {
  size_t size = 5;
  Point points[size];
  Point A[size];
  
  srand(time(NULL));
  generate(points, size);  

  copyPoints(points, A, size);
  mergeSort(A, size);
   
  std::sort(points, points + size, moreCriteria);	
  
  if (compare(A, points, size)) {
    printf("OK\n");
  } else {
    printf("Error! %i\n", size);
    print(A, size);
    print(points, size);
    break;
  }
  
  }
  return 0;
}

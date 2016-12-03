#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cmath>

//std sort по убыванию
///merge по убыванию


struct Point {
	float x;
	float y;
};


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


void mergeDECR(	Point left[], Point right[], size_t left_size, size_t right_size, Point output[]) {
  size_t l = 0, r = 0, k = 0;
  while (l < left_size && r < right_size) {
    if (left[l] > right[r]) {
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
  mergeDECR(left, right, left_size, right_size, array);
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
  return  A > B;
}

///////////////////////////////////////////////////

int main(int argc, char** argv) {
  Point points[] = {{3.14, 2.71}, {1.05, -0.05}, {0.05, 0.00}, {1.1, -0.2}, {0.07, -1.7}, {0.8, 2.1}};
  size_t sizep = sizeof(points) / sizeof(points[0]);
  print(points, sizep);
  mergeSort(points, sizep);
  print(points, sizep);
  std::sort(points, points + sizep, moreCriteria);	
  print(points, sizep);	
  return 0;
}

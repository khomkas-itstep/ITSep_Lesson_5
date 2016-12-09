#include <cmath>
#include <iostream>
#include <cstdio> 


struct Point {
  float x;
  float y;
  float z;
};

float Euclidean_distance(Point A, Point B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) + (A.z - B.z) * (A.z - B.z));
}

void print(Point point) {
  printf("(%.2f, %.2f, %.2f)", point.x, point.y, point.z);
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

/////////////////////////////////////

int main(int argc, char** argv) {	
	
  Point A;
  Point B;
	
  std::cout << "Enter Point A" << std::endl;	
  std::cin >> A.x >> A.y >> A.z ; 
  std::cout << std::endl;
  print(A);
  std::cout << std::endl << std::endl;
  std::cout << "Enter Point B" << std::endl;	
  std::cin >> B.x >> B.y >> B.z ; 
  std::cout << std::endl;
  print(B);
  std::cout << std::endl << std::endl;
  std::cout << "Euclidean distance = " << Euclidean_distance(A, B);	
  
  return 0;
}

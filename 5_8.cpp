#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>

///////////////OnOneStraight3D


struct Point {
	
  float x;
  float y;
  float z;
  
};


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


bool OnOneStraight3D(Point A, Point B, Point C) {
  if ((((B.x - A.x) / (C.x - A.x)) == ((B.y - A.y) / (C.y - A.y))) 
      && (((B.z - A.z) / (C.z - A.z)) == ((B.x - A.x) / (C.x - A.x)))) {
    return true;
  }
  return false;
}


///////////////////////////////////////////////////

int main(int argc, char** argv) {	
  Point A;
  Point B;
  Point C;

  while(true) {
    std::cout << "Enter Point A" << std::endl;
	std::cin >> A.x >> A.y >> A.z;
	std::cout << std::endl << "Enter Point B" << std::endl;
	std::cin >> B.x >> B.y >> B.z;
	std::cout << std::endl << "Enter Point C" << std::endl;
    std::cin >> C.x >> C.y >> C.z;
    std::cout << std::endl;
    print(A);
    print(B);
    print(C);
		  
  if (OnOneStraight3D(A, B, C)) {     
    printf("OK\n");
    print(A);
    print(B);
    print(C);
    printf("\n\n");
    continue;	      
    } else {
    printf("Error!\n\n" );
	}
  }
  
  return 0;
}

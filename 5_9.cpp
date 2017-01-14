#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>

///////////Points on circle
//////////the center of the circle (ZERO, ZERO)


struct Point {
    float x;
	float y;
};


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


bool OnOneCircle(Point A,Point B,Point C) {
  if ((((A.x * A.x) + (A.y * A.y)) == ((B.x * B.x) + (B.y * B.y))) && (((C.x * C.x) + (C.y * C.y)) == ((A.x * A.x) + (A.y * A.y)))) {
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
	std::cin >> A.x >> A.y ;
	std::cout << std::endl << "Enter Point B" << std::endl;
	std::cin >> B.x >> B.y ;
	std::cout << std::endl << "Enter Point C" << std::endl;
    std::cin >> C.x >> C.y ;
    std::cout << std::endl;
    print(A);
    print(B);
    print(C);
   
    if (OnOneCircle(A, B, C)) {
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

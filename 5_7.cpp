#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>

/////////////////////OnOneStraight


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


bool OnOneStraight(Point A, Point B, Point C) {
  if (( 0.5 * (((A.x - C.x) * (B.y - C.y)) == ((B.x - C.x) * (A.y - C.y))))) {
    return true;
  }
  return false;
}


///////////////////////////////////////////////////


int main(int argc, char** argv) {	

  while(true) {
  	
    Point A;
    Point B;
    Point C;
       
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
     	  
    if (OnOneStraight(A, B, C)) {
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

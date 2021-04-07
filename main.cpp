#include <iostream>
#include "Vector.h"
#include "Object.h"

int main(int argc, char** argv){
	{
		std::cout << "\n --- Scope Start --- \n";	
		Vector<Obj> vec;
		vec.push_back("Hello");
		vec.push_back("World");
		std::cout << "\n --- Scope End --- \n";
	}
	return 0;
}
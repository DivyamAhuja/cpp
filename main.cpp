#include <iostream>
#include "Vector.h"
#include "Object.h"
#include "BinarySearchTree.h"

int main(int argc, char **argv)
{
	{
		std::cout << "\n --- Scope Start Vector--- \n";
		Vector<Obj> vec;
		vec.push_back("Hello");
		vec.push_back("World");
		std::cout << "\n ---  --- \n";
	}
	std::cout << "\n --- Scope End --- \n";

	std::cout << "\n\n\n";

	std::cout << "\n --- Scope Start BST--- \n";
	{

		BinarySearchTree<Obj> BST;
		BST.addNode(Obj("Hello"));
		BST.addNode(Obj("A"));
		BST.addNode(Obj("EF"));
		BST.addNode(Obj("G"));
		BST.addNode(Obj("NICE"));
		BST.addNode(Obj("guesss"));
		BST.addNode(Obj("I"));
		BST.addNode(Obj("so"));

		BST.inOrder();
		std::cout << "\n ---  --- \n";
	}
	std::cout << "\n --- Scope End --- \n";
	return 0;
}
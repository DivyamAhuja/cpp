#ifndef _MY_OBJ_H_
#define _MY_OBJ_H_ 1
#include <bits/stdc++.h>
static int _id = 0;

class Obj{

public:
	char* memBlock = nullptr;
	size_t size = 0;
	int id = 0;
public:
	Obj(){
		id = _id++;
		std::cout << "Object Created Default. " << id <<"\n";
	};
	
	Obj(const char* str){
		id = _id++;
		size = strlen(str);
		memBlock = new char[size + 1];
		memcpy(memBlock, str, size + 1);
		std::cout << "Object Created String. " << id << " " << (memBlock != nullptr ? memBlock : "nullptr") << "\n";
	}

	
	Obj(const Obj& obj){
		id = _id++;
		
		this->size = obj.size;
		if(obj.memBlock != nullptr){
			char* temp = new char[size];
			memcpy(temp, obj.memBlock, size + 1);
			this->memBlock = temp;
		}else{
			this->memBlock = nullptr;
		}
		std::cout << "Object Copied. " << id << " " << (memBlock != nullptr ? memBlock : "nullptr") << "\n";
	}

	Obj(Obj&& obj){
		id = _id++;

		this->size = obj.size;
		obj.size = 0;
		this->memBlock = obj.memBlock;
		obj.memBlock = nullptr;
		std::cout << "Object Moved. " << id << " " << (memBlock != nullptr ? memBlock : "nullptr") << "\n";
	}

	Obj& operator=(const Obj& obj){
		id = _id++;
		
		delete this->memBlock;
		
		this->size = obj.size;
		if(obj.memBlock != nullptr){
			char* temp = new char[size];
			memcpy(temp, obj.memBlock, size + 1);
			this->memBlock = temp;
		}else{
			this->memBlock = nullptr;
		}
		std::cout << "Object Copy Assigned. " << id << " " << (memBlock != nullptr ? memBlock : "nullptr") << "\n";
		return *this;
	}

	Obj& operator=(Obj&& obj){
		id = _id++;
		
		delete this->memBlock;
		
		this->size = obj.size;
		if(obj.memBlock != nullptr){
			this->memBlock = obj.memBlock;
			obj.memBlock = nullptr;
		}else{
			this->memBlock = nullptr;
		}
		std::cout << "Object Move Assigned. " << id << " " << (memBlock != nullptr ? memBlock : "nullptr") << "\n";
		return *this;
	}

	~Obj(){
		std::cout << "Object Destroyed. " << id << " " << (memBlock != nullptr ? memBlock : "nullptr") << "\n";
		delete memBlock;
	}

	char& operator[] (unsigned long int i){return memBlock[i];}
    const char& operator[] (unsigned long int i) const {return memBlock[i];} 
};

std::ostream& operator<<(std::ostream& stream, const Obj& obj){
	return stream << obj.memBlock;
}

#endif
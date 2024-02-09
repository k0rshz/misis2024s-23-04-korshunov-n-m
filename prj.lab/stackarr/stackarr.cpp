#include "complex/complex.hpp"
#include <iostream>

class StackArr {
public:
	StackArr() = default;
	~StackArr() {};
	StackArr& operator=(const StackArr&) {};
	void Pop() {

	};
	void Push() {

	};
	void IsEmpty() {

	};
private:
	Complex* data_ = nullptr;
};

int main() {
	Complex a{ 1.0, 2.5 };
	std::cout << a;
	return 0;
}
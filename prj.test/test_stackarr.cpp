#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "stackarr/stackarr.hpp"
#include "doctest.h" 

TEST_CASE("all") {
	Complex a{ 1.5, 2.0 }, b{ 3.1, 4.9 };
	StackArr s;
	CHECK(s.IsEmpty() == 1);
	s.Push(a);
	CHECK(s.Top() == a);
	CHECK(s.IsEmpty() == 0);
	s.Push(b);
	CHECK(s.Top() == b);
	s.Pop();
	CHECK(s.Top() == a);
}
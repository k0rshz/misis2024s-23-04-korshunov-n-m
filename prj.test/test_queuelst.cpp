#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queuelst/queuelst.hpp"
#include "doctest.h" 

TEST_CASE("all") {
	QueueLst s, g;
	Complex a{ 1.0, 2.1 }, b{ 4.5, 10.9 };
	CHECK(s.IsEmpty() == 1);
	s.Push(a);
	CHECK(s.Top() == a);
	CHECK(s.IsEmpty() == 0);
	s.Push(b);
	CHECK(s.Top() == a);
	s.Pop();
	CHECK(s.Top() == b);
	//g = s;
	//g.Pop();
	//CHECK(s.Top() == a);
	//g.Push(a);
	//CHECK(s.Top() == g.Top());
}
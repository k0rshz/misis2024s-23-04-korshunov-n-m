#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queuelst/queuelst.hpp"
#include "doctest.h" 

TEST_CASE("all") {
	QueueLst s;
	Complex a{ 1.0, 2.1 }, b{ 4.5, 10.9 };
	CHECK(s.IsEmpty() == 1);
	s.Push(a);
	CHECK(s.Top() == a);
	CHECK(s.IsEmpty() == 0);
	s.Push(b);
	CHECK(s.Top() == a);
	s.Pop();
	CHECK(s.Top() == b);
	s.Push(a);
	QueueLst g(s);
	g.Pop();
	CHECK(g.Top() == a);
	g = s;
	CHECK(g.Top() == b);
	g.Pop();
	CHECK(g.Top() == a);
}
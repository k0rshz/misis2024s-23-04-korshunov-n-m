#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queuelstpr/queuelstpr.hpp"
#include "doctest.h"

TEST_CASE("all") {
	QueueLstPr s;
	float a = 2.5, b = 2.48, c = 2.49;
	CHECK(s.IsEmpty() == 1);
	s.Push(a);
	CHECK(s.Top() == a);
	s.Push(b);
	CHECK(s.Top() == b);
	QueueLstPr g(s);
	g.Pop();
	CHECK(g.Top() == a);
	s.Pop();
	g = s;
	CHECK(s.Top() == a);
	s.Push(b);
	s.Push(c);
	CHECK(s.Top() == b);
	s.Pop();
	CHECK(s.Top() == c);
	s.Pop();
	CHECK(s.Top() == a);
	s.Clear();
	CHECK(s.IsEmpty() == 1);
	s.Pop();
	CHECK_THROWS(s.Top());
}
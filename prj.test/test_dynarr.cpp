#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dynarr/dynarr.hpp"

TEST_CASE("dynarr ctor") {
    DynArr arr_def;
    CHECK_EQ(arr_def.Size(), 0);
    const int size = 5;
    DynArr arr_s(size);
    CHECK_EQ(arr_s.Size(), size);
    //CHECK_THROWS(void(DynArr(0)));
    CHECK_THROWS(void(DynArr(-size)));
}

TEST_CASE("dynarr op[]") {
    const int size = 5;
    DynArr arr(size);
    DynArr arr2(10);
    CHECK_EQ(arr[0], 0);
    CHECK_EQ(arr[arr.Size() - 1], 0);
    CHECK_EQ(arr[0], arr[1]);
    CHECK_THROWS(arr2[-1]);
    CHECK_EQ(arr2[0], arr[arr.Size()-1]);
    CHECK_THROWS(arr[arr.Size()]);
}

TEST_CASE("a") {
    DynArr a(3);
    CHECK(a[1] == 0);
    CHECK_THROWS(DynArr(-1));
}

TEST_CASE("methods") {
    DynArr a(5);
    a[0] = 100;
    a[1] = 1;
    a[3] = 3;
    a[4] = 4;
    CHECK(a[0] == 100);
    CHECK(a.Size() == 5);

    a.Resize(7);
    CHECK(a.Size() == 7);
    CHECK(a[5] == 0);
    CHECK(a[4] == 4);

    a.Insert(1, 3);
    CHECK(a[1] == 3);
    CHECK(a[2] == 1);
    CHECK(a[4] == 3);
    CHECK(a.Size() == 8);
}

TEST_CASE("basic operations") {
    DynArr a(5);
    for (int i = 0; i < a.Size(); ++i) {
        a[i] = i + 0.5;
    }
    for(int i = 0; i < 3; ++i) {
         CHECK(a[i] == i + 0.5);
    }
    CHECK(a[1] == 1.5);
    CHECK(a[a.Size()-1] == 4.5);
    CHECK_THROWS(a[5]);
    CHECK_THROWS(a[-1]);
}

TEST_CASE("def") {
    const int s = 100;
    DynArr a(s);
    for (int i = 0; i < a.Size(); ++i) {
        a[i] = i;
    }
    for (int i = 0; i < s; ++i) {
        CHECK(a[i] == i);
    }
}
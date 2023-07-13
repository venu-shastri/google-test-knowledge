
#include "gtest/gtest.h"
using namespace std;

class BubbleSort{

public:
	int sort(int source) {
		return source;
	}
};
class QuickSort {

public:
	   int sort(int source) {
		return source;
	}
};
class HeapSort {

public:
	int sort(int source) {
		return source;
	}
};

class BubbleSortFixture :public testing::Test {
protected:
	BubbleSort codeUnderTest;
};

TEST_F(BubbleSortFixture, TestSort) {
	int source{ 1 };
   int actualValue=	codeUnderTest.sort(source);
   ASSERT_EQ(actualValue, 1);
}


class QuickSortFixture :public testing::Test {
protected:
	QuickSort codeUnderTest;
};

TEST_F(QuickSortFixture, TestSort) {
	int source{ 1 };
	int actualValue = codeUnderTest.sort(source);
	ASSERT_EQ(actualValue, 1);
}



class HeapSortFixture :public testing::Test {
protected:
	HeapSort codeUnderTest;
};

TEST_F(HeapSortFixture, TestSort) {
	int source{ 1 };
	int actualValue = codeUnderTest.sort(source);
	ASSERT_EQ(actualValue, 1);
}


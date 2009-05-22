/*
 *   CrissCross
 *   A multi-purpose cross-platform library.
 *
 *   A product of IO.IN Research.
 *
 *   (c) 2006-2008 Steven Noonan.
 *   Licensed under the New BSD License.
 *
 */

#include "header.h"
#include "testutils.h"
#include "quicksort.h"

#ifdef ENABLE_SORTS

#include <crisscross/universal_include.h>
#include <crisscross/darray.h>
#include <crisscross/quicksort.h>

using namespace CrissCross::Data;

int TestQuickSort_IntArray()
{
	int int_array [] = {0, 4, 3, 6, 2, 1, 5, 7, 9, 8 };
	QuickSort<int> *qs = new QuickSort<int>();
	qs->Sort(int_array, 10);
	for (int i = 0; i < 10; i++) {
		TEST_ASSERT(int_array[i] == i);
	}

	delete qs;
	return 0;
}

int TestQuickSort_DArray()
{
	DArray<int>    *darray = new DArray<int>();

	darray->insert(4);
	darray->insert(2);
	darray->insert(0);
	darray->insert(3);
	darray->insert(1);

	QuickSort<int> *qs = new QuickSort<int>();
	darray->sort(qs);
	delete qs;

	for (int i = 0; i < 5; i++) {
		TEST_ASSERT(darray->get(i) == i);
	}

	delete darray;
	return 0;
}

int TestQuickSort_LList()
{
	LList<int>     *llist = new LList<int>();

	llist->insert(4);
	llist->insert(2);
	llist->insert(0);
	llist->insert(3);
	llist->insert(1);

	QuickSort<int> *qs = new QuickSort<int>();
	llist->sort(qs);
	delete qs;

	for (int i = 0; i < 5; i++) {
		TEST_ASSERT(llist->get(i) == i);
	}

	delete llist;
	return 0;
}

#endif

#include <iostream>

#ifndef NODE //IF this header is NOT defined
#define NODE // define this header as 'EXERCISE'

using namespace std;

template <class T>
struct Node{
	T data;
	Node *prev, *next;
};

#endif
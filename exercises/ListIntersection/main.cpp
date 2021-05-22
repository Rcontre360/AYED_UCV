#include <iostream>
#include <fstream>
#include "../../utils/exercise.h"
#include "../../utils/node.h"

#define forList(a,list) for(Node<int> *a=list.getFront();a!=NULL;a = a->next)

const string LIST_INTERSECTION_TEST_CASES = "./exercises/ListIntersection/testCases.txt";

class SimpleIntegerList{
private:
	int list_size=0;
	Node<int> *front,	*back;

public:
	int size(){return list_size;}
	Node<int>* getFront(){return front;}
	Node<int>* getBack(){return back;}

	void push(int val){
		Node<int> *nxt = new Node<int>;
		if (list_size==0){
			*nxt = {val,NULL,NULL};
			front = nxt;
			back = nxt;
		}else{
			*nxt = {val,back,NULL};
			back->next = nxt;
			back = nxt;
		}
		list_size++;
	}
};

class ListIntersection:public Exercise{
private:
	int testCases;
	SimpleIntegerList *first, *second;

	void readInput(){
		ifstream reader(LIST_INTERSECTION_TEST_CASES);
		reader>>testCases; 
		cout<<"Number of cases: "<<testCases<<'\n';

		first = new SimpleIntegerList[testCases];
		second = new SimpleIntegerList[testCases];

		for (int i=0;i<testCases;i++){
			int listSize1,listSize2;
			reader>>listSize1>>listSize2;
			for (int j=0;j<listSize1;j++){
				int aux;
				reader>>aux;
				first[i].push(aux);
			}
			for (int j=0;j<listSize2;j++){
				int aux;
				reader>>aux;
				second[i].push(aux);
			}
		}
	}

	void printOutput(){
		for (int i=0;i<testCases;i++){
			cout<<"\nTest case "<<i<<": \n";
			cout<<"Standar O(n*m) solution: ";
			standarSolution(first[i],second[i]);
			cout<<"Standar O(n+m) solution: ";
			greedySolution(first[i],second[i]);
			cout<<'\n';
		}
	}

	//Time complexity O(n*m)
	void standarSolution(SimpleIntegerList first,SimpleIntegerList second){ 
		SimpleIntegerList result;
		forList(i,first)
			forList(j,second)
				if (i->data==j->data)
					result.push(i->data);
		forList(i,result)
			cout<<i->data<<' ';
		cout<<'\n';
	}

	//Time complexity O(n+m)
	void greedySolution(SimpleIntegerList first, SimpleIntegerList second){
		SimpleIntegerList result;
		Node<int> *i = first.getBack(), *j = second.getFront();

		while(i!=NULL && j!=NULL){
			int iData = i->data, jData = j->data;
			if (iData==jData)
				result.push(iData);

			if (iData>=jData)
				i = i->prev;
			else
				j = j->next;
		}

		forList(i,result)
			cout<<i->data<<' ';
	}

public:
	void init(){
		readInput();
		printOutput();
	}
};

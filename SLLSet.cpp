/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

using namespace std;

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	size = arrSize; // create the array size here
	SLLNode * nodes = new SLLNode[size];  //assign a set of nodes

	int i;
	//create a first variable link list
	nodes[0] = SLLNode(sortedArray[0], NULL);

	for(i = 1; i < arrSize; i++){

		nodes[i - 1].next = nodes + i;

	}
	head = nodes; //assign head


}
int SLLSet::getSize()
{
	
	//fixME
	return size;
}
SLLSet SLLSet::copy()
{
	int newSortedArray[size], i = 0; SLLNode*c = head;
	while(c != NULL){ //when c is not NULL then run the loop

		newSortedArray[i] = c->value;
		c = c->next;

		i++;
	}
	

	return *(new SLLSet(newSortedArray, size));

}
bool SLLSet::isIn(int v)
{
	SLLNode*c = head;

	while(c!=NULL);{

		if(c->value == v){ // run the if-for loop to check values
			return true;

		}

		c = c->next;
	}

	return false;
}

void SLLSet::add(int v)
{
	SLLNode *x = new SLLNode;
	x[0] = SLLNode(v,NULL);
	SLLNode *addc = head;

	if(addc == NULL){ //if the set is empty the set x as head
		head = x;
		size ++;
		return;

	}

	if(v < head->value){
		SLLNode *tempura = head;
		x->next = tempura;
		head = x;
		size ++; //change size here
		return;

	}
// run while loop here to check through each variable and above
	while(addc->next != NULL){
		if(addc->value == v){
			return;
		}

		if(addc->next->value > v){
			x->next = addc->next;
			addc->next = x;

			size++;
			return;

		}

		addc = addc->next;

	}

	if(addc->value == v){
		return;
	}

	addc->next = x;
	size ++;
	return;
    
}
void SLLSet::remove(int v)
{

	SLLNode *c = head;
	if(head == NULL){return;}

	if(c->value == v){
		head = c->next;
		size --;
		return;
	}
	while(c != NULL && c->next != NULL){

		if(c->next->value == v){
			SLLNode*tempura = c->next->next;
			c->next = tempura;
			size --;
			return;
		}
		if(c->next->value > v){
			return;

		}

		c = c->next;

	}
   
}
SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLNode *x = head, *y = s.head;
	int newArrayList[size + s.size];
	int i = 0;

	while(1){

		if(x == NULL){
			while(y != NULL){
				newArrayList[i] = y->value;
				i ++; y = y->next;
			}
			break;

		}else if(y == NULL){
			while(x != NULL){
				newArrayList[i] = x->value;
				i ++; x = x->next;
			}
			break;
		}

//if both of the lists contain elements, then copy the lowest value present
//if both are the same then only copy once and apply both
		if(x->value == y->value){
			newArrayList[i] = x->value;
			i ++;
			x = x->next; y = y->next;
		}else if(x->value < y->value){
			newArrayList[i] = x->value;
			i++;
			x = x->next;
		}else if(y->value < x->value){
			newArrayList[i] = y->value;
			i++;
			y = y->next;
		}
	}


    	//fixME
	 return *(new SLLSet(newArrayList,i));

}
SLLSet SLLSet::intersection(SLLSet s)
{

	SLLNode *x = head, *y = s.head;
	int i = 0;
	int newArrayList[(size> s.size ? size : s.size)]; //define new array


	while(x != NULL && y !=NULL){
		if(x->value < y->value){
			x = x->next;
		}else if(x->value > y->value){
			y = y->next;
		}else if (x->value == y->value){
			newArrayList[i] = x->value;
			i ++;
			x = x->next; y = y->next;

		}
	}
    	//fixME
	return *(new SLLSet(newArrayList,i));
}
SLLSet SLLSet::difference(SLLSet s)
{
	SLLNode *x = head, *y = s.head;
		int i = 0;
		int newArrayList[size];

		while(1){
			if(y == NULL){
				while(x != NULL){
					newArrayList[i] = x->value;
					x = x->next;
					i++;
				}
				break;
			}else if(x == NULL){
				break;
			}
			if(x->value > y->value){
				y = y->next;
			}else if(x->value < y->value){
				newArrayList[i] = x->value;
				x = x->next;
			}else if (x->value == y->value){
				x = x->next;
				y = y->next;
		    }
        }

    	//fixME
		return *(new SLLSet(newArrayList,i));
}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	int i;
	SLLSet copyVar = sArray[0];

	for(i = 1; i < size; i++){
		copyVar = copyVar.setUnion(sArray[i]);
	}
    	//fixME
	 return copyVar;
}
string SLLSet::toString()
{
	string returnString = "";

	SLLNode *c = head;

	int i;
	for(i = 0; i < size - 1; i++){
		returnString = returnString + to_string(c->value)+",";
		c = c->next;

	}
	if(i != 0){
		returnString = returnString + to_string(c->value);
	}
   //fixME
   return returnString;
}


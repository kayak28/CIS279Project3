/*
 * Application.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: kaya
 */

//#include "Application.h"
#include "Node.h"
#include <stdio.h>
#include <cstdlib> 
using namespace std;

int main()
{
	 Node* head = new Node(0.11, (Node*) NULL);
	 printf("%f\n",head->data());
	 head->list_insert(head, 4.22);
	 printf("%f\n",head->data());





	 return 0;
}

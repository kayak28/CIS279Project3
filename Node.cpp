/*
 * Node.cpp
 *
 *
 *      Author: kaya
 */
#include <stdio.h>
#include <cstdlib> //provide NULL and size_t
#include "Node.h"
#include<string>
#include<cassert>
using namespace std;

size_t Node::list_length(const Node* head_ptr)
{
	const Node* cursor;
	size_t answer;
	answer = 0;
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		answer++;
	}
	return answer;
}
void list_head_insert(Node*& head_ptr, const Node::value_type& entry)
{
	head_ptr = new Node(entry, head_ptr);
}
void list_insert(Node* previous_ptr, const Node::value_type& entry)
{
	Node *insert_ptr;
	insert_ptr = new Node(entry, previous_ptr->link());
	previous_ptr->setLink(insert_ptr);
}
Node* list_search(Node* head_ptr,const Node::value_type& target)
{
	Node* cursor;
	for(cursor = head_ptr; cursor != NULL; cursor=cursor->link())
	{
		if(target == cursor->data())
		{
			return cursor;
		}
	}
	return NULL;
}
const Node* list_search(const Node* head_ptr, const Node::value_type& target)
{
	const Node *cursor;
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		if(target == cursor->data())
		{
			return cursor;
		}
	}
	return NULL;
}
Node* Node::list_locate(Node* head_ptr, size_t position)
{
	Node *cursor;
	size_t i;
	assert(0<position);
	cursor = head_ptr;
	for(i = 1; (i < position)&&(cursor != NULL);i++)
	{
		cursor = cursor->link();
	}
	return cursor;
}
const Node* list_locate(const Node* head_ptr, size_t position)
{
	const Node * cursor;
	size_t i;
	assert(0<position);
	cursor = head_ptr;
	for(i = 1; (i < position)&&(cursor != NULL);i++)
	{
		cursor = cursor->link();
	}
	return cursor;
}
void list_head_remove(Node*& head_ptr)
{
	Node *remove_ptr;
	remove_ptr = head_ptr;
	head_ptr = head_ptr->link();
	delete remove_ptr;
}
void list_remove(Node* previous_ptr)
{
	Node *remove_ptr;
	remove_ptr = previous_ptr->link();
	previous_ptr->setLink(remove_ptr->link());
	delete remove_ptr;
}
void list_clear(Node*& head_ptr)
{
	while(head_ptr != NULL)
	{
		list_head_remove(head_ptr);
	}
}
void list_copy(const Node* source_ptr, Node*& head_ptr, Node*& tail_ptr)
{
	head_ptr = NULL;
	tail_ptr = NULL;
	//case (empty)
	if(source_ptr == NULL)
	{
		return;
	}
	//case(newly created)
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	//copy the rest of the nodes
	source_ptr = source_ptr->link();
	while(source_ptr != NULL)
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->link();
		source_ptr = source_ptr->link();
	}
}
void list_tail_insert(Node*& head_ptr, const Node::value_type& entry)
{
	Node* cursor;
	Node* previous;
	if(head_ptr == NULL)
	{
			return;
	}
	previous = head_ptr;

	for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		previous = cursor;
	}
	previous->setLink(new Node(entry,NULL));
	
	printf("added successfully");
	//return head_ptr;

}
void item_remove(Node*& head_ptr, const Node::value_type& entry)
{
	Node* cursor;
	Node* previous;
		for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			if(entry == cursor->data())
			{
				previous->setLink(cursor->link());
			}
			previous = cursor;
		}

}
bool isThere(Node* head_ptr,const Node::value_type& entry)
{
	Node* cursor;
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		if(entry == cursor->data())
		{
			return true;
		}
	}
	return false;

}

/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include<iostream>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // get values into in. divy those into odds and evens

  //case 1: in is empty so odds and even are also empty
  if(in == nullptr){
    odds = nullptr;
    evens = nullptr;
    return;
  }

  Node* next = in->next; //
  //case 2: in is not empty
  if(in->value % 2 ==0){ // if the value is even
    evens = in; // value is now in evens list
    split(next, odds, evens->next); // evens list built recursively. evens->next is next node in evens list
  }
  else{
    odds = in; //create new node in odds list with that value
    split(next, odds->next, evens); //recursively use split on next node from in. oods->next becomes the next node in odds list
  }

  in = nullptr; // prevent dangling pointers
  return;

}

/* If you needed a helper function, write it here */

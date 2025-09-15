#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
// Note to self: the prefix ULListStr:: tells the compiler that this function/member belongs to the ULListStr class.
// It must be used when member is defined outside class body.
{
  head_ = NULL; // head_ and tail_ are pointers to Item object
  tail_ = NULL;
  size_ = 0;
}


ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{

  // Case 1: list is empty.
  if(empty())
  {
    Item* newItem = new Item(); // newItem is a pointer to an Item object. It holds the address of the newly allocated Item object.
    newItem->next = nullptr;
    newItem->prev = nullptr;
    newItem->first = 0;
    newItem->last = 1; // this tracks the number of elements in the array. Since we're adding one, last = 1.
    newItem->val[0] = val; // add an element to the array at index 0
    head_ = newItem; // head and tail are pointers so we're setting them both to the same object (only one node in list)
    tail_= newItem;
    size_++;
    return;
  }
  //note to self: newItem is a pointer to an Item object. So to access members of Item, use ->.
  // first and last are integers stored inside the Item object. -> sets the value of those integers.

  // Case 2: List is not empty and there's room in tail to add a value
  if(!empty() && (tail_->last < ARRSIZE))
  {
    tail_->val[tail_->last] = val; //value is added to end of array (tail_->last)
    tail_->last++; // since we added a value, increment last to show that.
    size_++;
    return;
  }

  // Case 3: List is not empty and there's no room to add to tail
  if(!empty() && (tail_->last == ARRSIZE))
  {
    Item* newItem = new Item();
    newItem->prev = tail_;
    newItem->next = nullptr;
    tail_->next = newItem; // link old tail to new tail
    newItem->val[0] = val; // add value to start of new array
    newItem-> first = 0;
    newItem->last = 1; // since added one value
    tail_ = newItem; // tail is updated to point at new item
    size_++;
    return;
  }

  else
  {
    cout << "Error in push_back" << endl;
    return;
  }
}

void ULListStr::pop_back()
{
  // Case 1: list is empty
  if(empty())
  {
    return; // nothing to pop so just return
  }

  // Case 2: list is not empty and there's more than one element in the tail
  if(!empty() && (tail_->last > 1))
  {
    tail_->last--; // since we're removing one element
    size_--;
    tail_->val[tail_->last] = ""; // remove the last element
    return;
  }

  // Case 3: list is not empty and there's only one element
  if(!empty() && (tail_->last == 1))
  {
    Item* temp = new Item();
    temp = tail_; // temp points to same object as tail
    tail_ = tail_->prev;
    if(tail_ != nullptr) // if there's a previous node then set the next pointer to null to indicate it's the end of the list
    {
      tail_->next = nullptr; // new tail is now the end of the list
    }
    else
    {
      head_ = nullptr; // list is now empty
    }
    delete temp; //free memory of the old tail
    size_--;
    return;
  }

  else{
    cout << "Error in pop_back" << endl;
    return;
  }
}
void ULListStr::push_front(const std::string& val)
{
  // Case 1: list is empty
  if(empty())
  {
    Item* newItem = new Item();
    newItem->next = nullptr;
    newItem->prev = nullptr;
    newItem->first = 0;
    newItem->last = 1; // bc we're going to be adding one value just like push_back
    newItem->val[0] = val; // add the value
    head_ = newItem;
    tail_ = newItem;
    size_++;
    return;
  }

  //Case 2: List is not empty and there's room in the head to add a value
  if(!empty() && head_->first > 0)
  {
    head_->first--;
    head_->val[head_->first] = val; // adds value to front of array
    size_++;
    return;

  }

  //Case 3: List is not empty and there's no room at the head
  if(!empty() && head_->last <= ARRSIZE && head_->first == 0)
  {
    Item* newItem = new Item();
    newItem->next = nullptr;
    newItem->prev = nullptr;
    newItem->val[ARRSIZE - 1] = val; // add value to start of new array
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    size_++;
    return;
  }

  else
  {
    cout << "Error in push_front" << endl;
    return;
  }
}

//Note for self: Both push_back and push_front need to allocate space for the new node.
void ULListStr::pop_front()
{
  //Case 1: list is empty
  if(empty())
  {
    return;
  }

  // Case 2: list is not empty and theres more than one element in head
  else if(head_->first + 1 < head_->last)
  {
    head_->first++;
    size_--;
    return;
  }

  //Case 3: list is not empty and there's only one element in head
  else if(head_->first + 1 == head_-> last)
  {
    Item* temp = head_;
    head_ = head_->next;
    if(head_ != nullptr)
    {
      head_->prev = nullptr;
    }
    else
    {
      tail_= nullptr;
    }
    delete temp;
    size_--;
  }

  else
  {
    cout << "Error in pop_front" << endl;
    return;
  }
}

const std::string& ULListStr::back() const
{
  if(empty())
  {
    cout << "Error: list is empty" << endl;
    static const std::string emptyString = "";
    return emptyString;
  }
  return tail_->val[tail_->last - 1];
}

const std::string& ULListStr::front() const
{
  if(empty()){
    cout << "Error: list is empty" << endl;
    static const std::string emptyString = "";
    return emptyString;
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* curr = head_;
  size_t tempLoc = 0;
  while(curr != nullptr) //go through the nodes if there are some
  {
    for(size_t i = curr->first; i < curr->last; i++) //loop through the elements of the node
    {
      if(tempLoc == loc) 
      {
        return &(curr->val[i]); // returns address of string at that location
      }
      tempLoc++;
    }
    curr = curr->next;
  }
  return NULL;
}




void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

//make sure it created a new node:
int ULListStr::nodeCount() const
{
  Item* curr = head_;
  int count = 0;
  while(curr != nullptr)
  {
    count++;
    curr = curr->next;
  }
  return count;
}
  

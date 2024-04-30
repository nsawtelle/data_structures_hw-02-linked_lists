//  Linked Lists
//      Linked Lists are a linear data struture comprised of a series of connected nodes.
//
//  Author: Nicole Sawtelle
//  CU ID: nisa1697
//  GitHub Username: nsawtelle
//  Hours to complete lab: ~11 hours
//
//  Resources used to assist in writing:
//  https://www.w3schools.in/data-structures/linked-list
//  https://www.w3schools.com/cpp/cpp_exceptions.asp
//  https://en.cppreference.com/w/cpp/language/throw
//  https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/
//  


#include "LinkedList.h"

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList() {
  top_ptr_ = NULL;
}

// deconstructor,
LinkedList::~LinkedList() {}

node* LinkedList::init_node(int data) {
  node* ret(new node);
  ret->data = data;
  ret->next = nullptr;
  return ret;
}

string LinkedList::report() {
  string ret;
  node* cursor = top_ptr_;
  while (cursor != NULL) {
    ret += to_string(cursor->data) + " ";
    cursor = cursor->next;
  }
  return ret;
}

void LinkedList::append_data(int data) {
  auto new_node = init_node(data);
  append(new_node);
}

void LinkedList::append(node* new_node) {
  node* cursor = top_ptr_;
  if (cursor == NULL) {
    top_ptr_ = new_node;
    return;
  }
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }
  cursor->next = new_node;
}

void LinkedList::insert_data(int offset, int data) {
  auto new_node = init_node(data);
  insert(offset, new_node);
}

void LinkedList::insert(int offset, node* new_node) {
  if (offset == 0) {
    new_node->next = top_ptr_;
    top_ptr_ = new_node;
    return;
  }
  node* cursor = top_ptr_;
  for (int i = 0; i < offset - 1; i++) {
    if (cursor == NULL) {
      throw "Offset out of bounds:";
    }
    cursor = cursor->next;
  }
  new_node->next = cursor->next;
  cursor->next = new_node;
}

void LinkedList::remove(int offset) {
  if (top_ptr_ == NULL) {
    throw "List is empty";
  }
  if (offset == 0) {
    node* temp = top_ptr_;
    top_ptr_ = top_ptr_->next;
    delete temp;
    return;
  }
  node* cursor = top_ptr_;
  for (int i = 0; i < offset - 1; i++) {
    if (cursor == NULL) {
      throw "Offset out of bounds";
    }
    cursor = cursor->next;
  }
  if (cursor->next == NULL) {
    throw "Offset out of bounds";
  }
  node* temp = cursor->next;
  cursor->next = cursor->next->next;
  temp->next = nullptr;
  delete temp;
}

int LinkedList::size() {
  int ret = 0;
  node* cursor = top_ptr_;
  while (cursor != NULL) {
    ret++;
    cursor = cursor->next;
  }
  return ret;
}

bool LinkedList::contains(int data) {
  bool ret = false;
  node* cursor = top_ptr_;
  while (cursor !=NULL) {
    if (cursor->data ==data) {
      ret = true;
      break;
    }
    cursor = cursor->next;
  }
  return ret;
}

// This function is implemented for you
// It returns the top pointer
node* LinkedList::get_top() { return top_ptr_; }

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::set_top(node* top_ptr) { top_ptr_ = top_ptr; }

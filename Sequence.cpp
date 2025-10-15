// Created by Zander R. Little

#include <iostream>
#include "Sequence.h"
#include "SequenceNode.h"
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

/**
* Creates an empty sequence (numElts == 0) or a sequence of numElts items
* indexed from 0 ... (numElts - 1).
*/
Sequence::Sequence(size_t sz) : head(nullptr), tail(nullptr), sz(0) {
    for (size_t i = 0; i < sz; ++i)
        push_back(""); // initialize empty nodes
}

// creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s) : head(nullptr), tail(nullptr), sz(0) {
    auto current = s.head;
    while (current) {
        push_back(current->item);
        current = current->next;
    }
}

/**
 * Destroys all items in the sequence and release
 * the memory associated with the sequence
 */
Sequence::~Sequence() {
  clear ();
}

/**
 * The current sequence is released and replaced by a (deep) copy of sequence
 * s. A reference to the copied sequence is returned.
 *
 * @param s The sequence being copied
 * @return a reference to the copied sequence (
 */
Sequence& Sequence::operator=(const Sequence& s) {
  if (this != &s) { // prevent self assignment
    // clear data, then begin adding items from s iteratively while there is still a next item
    clear();
    auto current = s.head;
    while (current) {
      push_back(current->item);
      current = current->next;
    }
  }
  return *this;
}

/**
 * returns a pointer to a SequenceNode at a given position in the sequence.
 *
 * @param position position of the node being returned
 * @return a pointer to a SequenceNode
 */
std::shared_ptr<Sequence::SequenceNode> Sequence::getNodeAt(size_t position) const {
  if (position >= sz) {
    throw std::out_of_range("Index out of range in Sequence::getNodeAt");}

  // current = head, then iterate through until you find the node at size_t position
  auto current = head;
  for (size_t i = 0; i < position; ++i)
    current = current->next;
  return current;
}

/**
 * The position satisfies ( position >= 0 && position <= last_index() ).
 * The return value is a reference to the item at index position in the
 * sequence. Throws an exception if the position is outside the bounds
 * of the sequence.
 *
 * @param position the position of the data being returned.
 * @return a reference to the item at index position in the sequence.
 */
std::string& Sequence::operator[](size_t position) {
  // if position is outside the bounds of the sequence, throw out_of_range error.
  if (position >= sz) {
    throw out_of_range("Index out of range in Sequence::operator[]");}

  return data[position];
}

/**
 *
 * @param item the string being appended to the sequence
 */
void Sequence::push_back(std::string item) {
  auto newNode = std::make_shared<SequenceNode>(item);

  // if not head, newNode is head and tail, otherwise, newNode is new tail
  if (!head) {
    head = tail = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
  ++sz;
}

/**
 * The item at the end of the sequence is deleted and size of the sequence is reudced by one.
 * If the sequence was empty, throws an exception.
 */
void Sequence::pop_back() {
  if (!tail) {
    throw out_of_range("Index out of range in Sequence::pop_back");}

  // reset head and tail if they're the same, otherwise, prev is tail.
  if (head == tail) {
    head.reset();
    tail.reset();
  } else {
    tail = tail->prev.lock();
    tail->next.reset();
  }
  sz -= 1; //decrement sz
}


/**
 * The position satisfies ( position >= 0 && position <= last_index() ). The
 * value of item is inserted at position and the size of sequence is increased
 * by one. Throws an exception if the position is outside the bounds of the
 * sequence
 *
 * @param position the position the item is being inserted into.
 * @param item The item being inserted into the sequence
 */
void Sequence::insert(size_t position, std::string item) {
  // throw error if position is not in the Sequence
  if (position > sz) {
    throw out_of_range("Index out of range in Sequence::insert");
  }

  // create variable to replace data, then add all values to newData
  std::string* newData = new std::string[sz + 1];
  for (size_t i = 0, j = 0; i < sz + 1; i++) {
    if (i == position) {
      newData[i] = item;
    } else {
      newData[i] = data[j++];
    }
  }
  // delete data, replace with newData
  delete[] data;
  data = newData;
  sz += 1;
}

/**
 * Return the first element in the sequence.
 * If the sequence is empty, prints "Sequence is emtpy" to the console.
 * @return returns the element at the front of the sequence. Returns "" if sequence is empty.
 */
std::string Sequence::front() const {
  // if there's no head, throw error, otherwise return head
  if (!head) {
    throw out_of_range("Index out of range in Sequence::front");}
  return head->item;
}

/**
 * Return the last element in the sequence.
 * If the sequence is empty, prints "Sequence is emtpy" to the console.
 * @return returns the element at the back of the sequence or "" if the sequence is empty.
 */
std::string Sequence::back() const {
  // if there's no tail, throw error, otherwise return tail
  if (!tail) {
    throw out_of_range("Index out of range in Sequence::back");}
  return tail->item;
}

// Return true if the sequence has no elements, otherwise false.
bool Sequence::empty() const {
  return sz == 0;
}

// Return the number of elements in the sequence.
size_t Sequence::size() const {
  return sz;
}

/**
 * All items in the sequence are deleted and the memory associated with the
 * sequence is released, resetting the sequence to an empty state that can have
 * items re-inserted.
 */
void Sequence::clear() {
  std::string* newData = nullptr;
  delete[] data;
  data = newData;
}

/**
 * The item at position is removed from the sequence, and the memory
 * is released. If called with an invalid position throws an exception.
 * @param position the position of the value being erased
 */
void Sequence::erase(size_t position) {
  // throw error if position is out of range
  if (position >= sz) {
    throw out_of_range("Index out of range in Sequence::erase");
  }

  // if only one element, clear sequence
  if (sz == 1) {
    delete[] data;
    data = nullptr;
    sz = 0;
    return;
  }

  std::string* newData = nullptr; // var will replace data
  newData = new std::string[sz - 1];

  // for all items in sequence, if item is not at position, add it to newData
  for (size_t i = 0, j = 0; i < sz; i++) {
    if (i != position) {
      newData[j++] = data[i];
    }
  }
  // replace data with newData
  delete[] data;
  data = newData;
  sz -= 1;
}

/**
 * The items in the sequence at ( position ... (position + count - 1) ) are
 * deleted and their memory released. If called with invalid position and/or
 * count throws an exception.
 *
 * @param position the position of the value being erased
 * @param count the number of items being erased.
 */
void Sequence::erase(size_t position, size_t count) {
  // throw error if position is out of range, or if position + count is out of range
  if (position >= sz || position + count > sz) {
    throw out_of_range("Index out of range in Sequence::erase");
  }
  std::string* newData = nullptr;
  size_t newSize = sz - count;

  // for all values in sequence, if value is not within the range of
  // ( position ... (position + count - 1), add it to newData
  if (newSize > 0) {
    newData = new std::string[newSize];
    for (size_t i = 0, j = 0; i < sz; i++) {
      if (i < position || i >= position + count) {
        newData[j++] = data[i];
      }
    }
  }
  // replace data with newData
  delete[] data;
  data = newData;
  sz = newSize;
}

/**
* Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
* stream. This is not a method of the Sequence class.
* @param os
* @param s The sequence being printed
* @return returns os
*/
std::ostream& operator<<(std::ostream& os, const Sequence& s) {
  os << "<";

  // loop through all values, printing them to the console.
  for (size_t i = 0; i < s.sz; i++) {
    os << s.data[i];
    if (i != s.sz - 1) {  //print comma if not on last element
      os << ", ";
    }
  }
  os << ">";
  return os;
}

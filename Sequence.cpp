// Created by Zander R. Little

#include <iostream>
#include "Sequence.h"
#include <string>

using namespace std;

/**
* Creates an empty sequence (numElts == 0) or a sequence of numElts items
* indexed from 0 ... (numElts - 1).
*/
Sequence::Sequence(size_t sz)
{
  this->sz = sz;
  if (sz == 0) {
    data = nullptr;
  } else {
    data = new std::string[sz];
  }
}

// creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s) {
  sz = s.sz;
  if (sz == 0) {
    data = nullptr;
  } else {
    data = new std::string[sz];
    for (size_t i = 0; i < sz; i++) {
      data[i] = s.data[i];
    }
  }
}

/**
 * Destroys all items in the sequence and release
 * the memory associated with the sequence
 */
Sequence::~Sequence() {
  delete[] data;
  data = nullptr;
}

// The current sequence is released and replaced by a (deep) copy of sequence
// s. A reference to the copied sequence is returned (return *this;).
/**
 * The current sequence is released and replaced by a (deep) copy of sequence
 * s. A reference to the copied sequence is returned.
 *
 * @param s The sequence being copied
 * @return a reference to the copied sequence (
 */
Sequence& Sequence::operator=(const Sequence& s) {
  if (this != &s) { // prevent self assignment
    delete[] data;  // clean up old memory.
    sz = s.sz;
    if (sz == 0) {
      data = nullptr;
    } else {
      data = new std::string[sz];
      for (size_t i = 0; i < sz; i++) {
        data[i] = s.data[i];
      }
    }
  }
  return *this;
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
    throw out_of_range("Index out of range in Sequence::operator[]");
  }
  return data[position];
}

/**
 * The value of item is appended to the sequence.
 * @param item the string being appended to the sequence
 */
void Sequence::push_back(std::string item) {
  std::string* newData = new std::string[sz + 1];
  for (size_t i = 0; i < sz; i++) {
    newData[i] = data[i];
  }
  newData[sz] = item;
  delete[] data;
  data = newData;
  sz += 1;
}


/**
 * The item at the end of the sequence is deleted and size of the sequence is reudced by one.
 * If the sequence was empty, throws an exception.
 */
void Sequence::pop_back() {
  // if sequence sz is 0, throw underflow_error
  if (sz == 0) {
    throw underflow_error("Can't pop_back from empty sequence");
  }

  // reduce sz, then create a nullptr to store new data
  sz = sz - 1;
  std::string* newData = nullptr;

  // if sz > 0 then copy all data to newData, except for the last value
  if (sz > 0) {
    newData = new std::string[sz];
    for (size_t i = 0; i < sz; i++) {
      newData[i] = data[i];
    }
  }
  // delete data and replace it with newData
  delete[] data;
  data = newData;
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
void Sequence::insert(size_t position, std::string item) {}

/**
 * Return the first element in the sequence.
 * If the sequence is empty, prints "Sequence is emtpy" to the console.
 * @return returns the element at the front of the sequence. Returns "" if sequence is empty.
 */
std::string Sequence::front() const {
  //try to return data[0] (the front) + catch the out_of_range error if sequence is emtpy
  try {
    return data[0];
  } catch (const std::out_of_range& e) {
      std::cout << "Sequence is empty" << endl;
      return "";
  }
}

/**
 * Return the last element in the sequence.
 * If the sequence is empty, prints "Sequence is emtpy" to the console.
 * @return returns the element at the back of the sequence or "" if the sequence is empty.
 */
std::string Sequence::back() const {
  try {
    return data[sz - 1];
  } catch (const std::out_of_range& e) {
    std::cout << "Sequence is empty" << endl;
  }
  return data[sz - 1];
}

// Return true if the sequence has no elements, otherwise false.
bool Sequence::empty() const {
  return sz == 0;
}

// Return the number of elements in the sequence.
size_t Sequence::size() const {
  return sz;
}

// All items in the sequence are deleted and the memory associated with the
// sequence is released, resetting the sequence to an empty state that can have
// items re-inserted.
void Sequence::clear() {

}

// The item at position is removed from the sequence, and the memory
// is released. If called with an invalid position throws an exception.
void Sequence::erase(size_t position) {

}

// The items in the sequence at ( position ... (position + count - 1) ) are
// deleted and their memory released. If called with invalid position and/or
// count throws an exception.
void Sequence::erase(size_t position, size_t count) {

}

// Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
// stream. This is not a method of the Sequence class.

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
    os << ">";
  }
  return os;
}

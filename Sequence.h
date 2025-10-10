#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <iostream>
#include <vector>

class Sequence {
public:
    // Constructors & destructor
    Sequence(size_t sz = 0);
    Sequence(const Sequence& s);
    ~Sequence();

    // Operators
    Sequence& operator=(const Sequence& s);
    std::string& operator[](size_t position);

    // Modifiers
    void push_back(std::string item);
    void pop_back();
    void insert(size_t position, std::string item);
    void clear();
    void erase(size_t position);
    void erase(size_t position, size_t count);

    // Accessors
    std::string front() const;
    std::string back() const;
    bool empty() const;
    size_t size() const;

    // Friend function
    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);

private:
    size_t sz; // size of the sequence
    // std::vector<std::string> data; // or use raw pointers if required by your assignment
    std::string* data;
};

#endif
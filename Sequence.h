#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>

class Sequence {
public:
    // Nested node class
    struct SequenceNode {
        std::string item;
        std::shared_ptr<SequenceNode> next;
        std::weak_ptr<SequenceNode> prev;

        SequenceNode(std::string value = "") : item(value), next(nullptr), prev() {}
    };

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

    // Special function
    std::weak_ptr<SequenceNode> sortByMemoryLocation(bool ascending = true);

    // Friend function
    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);

private:
    std::shared_ptr<SequenceNode> head;
    std::shared_ptr<SequenceNode> tail;
    size_t sz;

    std::shared_ptr<SequenceNode> getNodeAt(size_t position) const;
};

#endif
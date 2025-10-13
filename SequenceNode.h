//
// Created by zande on 10/13/2025.
//

#include <string>
#include <memory>

#ifndef SEQUENCENODE_H
#define SEQUENCENODE_H

/**
* A node in the doubly linked Sequence.
* Stores a string item and links to the next and previous nodes.
*/
namespace std {
class SequenceNode {
  public:
    std::string item;                    // element stored in *this* node
    std::shared_ptr<SequenceNode> next;  // ptr to next/prev. node
    std::shared_ptr<SequenceNode> prev;

    // constructors
    SequenceNode();
    explicit SequenceNode(const std::string& value);
};
} // std

#endif //SEQUENCENODE_H

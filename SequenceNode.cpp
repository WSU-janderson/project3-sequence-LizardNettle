//
// Created by zande on 10/13/2025.
// well hopefully this is done by midnight lmao
//

#include "SequenceNode.h"
#include <string>
#include <memory>

namespace std {
SequenceNode::SequenceNode() : item(""), next(nullptr), prev() {}

SequenceNode::SequenceNode(const std::string& value)
        : item(value), next(nullptr), prev() {}
}
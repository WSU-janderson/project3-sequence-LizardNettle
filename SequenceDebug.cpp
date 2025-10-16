/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include <string>
#include "Sequence.h"

using namespace std;

int main() {
    try {
        std::cout << "=== Sequence Project 3 Driver ===\n";
        Sequence mySequence(5);
        mySequence[0] = "function"; mySequence[1] = "parameter"; mySequence[4] = "pointer";
        std::cout << "Initial sequence: " << mySequence << std::endl;

        // push_back
        mySequence.push_back("const");
        std::cout << "After push_back(\"const\"): " << mySequence << std::endl;

        // insert
        mySequence.insert(1, "constructor");
        std::cout << "After insert(1, \"constructor\"): " << mySequence << std::endl;

        // erase a range
        mySequence.erase(3, 2);
        std::cout << "After erase(3, 2): " << mySequence << std::endl;

        // front() and back()
        std::cout << "Front element: " << mySequence.front() << std::endl;
        std::cout << "Back element:  " << mySequence.back() << std::endl;

        // pop_back()
        mySequence.pop_back();
        std::cout << "After pop_back(): " << mySequence << std::endl;

        // size() and empty()
        std::cout << "Current size: " << mySequence.size() << std::endl;
        std::cout << "Is empty? " << (mySequence.empty() ? "Yes" : "No") << std::endl;

        // Test deep copy constructor
        Sequence copySequence(mySequence);
        std::cout << "Copy constructed sequence: " << copySequence << std::endl;
        // Assignment operator
        Sequence assignedSequence;
        assignedSequence = mySequence;
        std::cout << "Assigned sequence: " << assignedSequence << std::endl;

        // Test sortByMemoryLocation
        std::cout << "\nSorting nodes by memory location (ascending):" << std::endl;
        mySequence.sortByMemoryLocation(true);
        std::cout << mySequence << std::endl;

        std::cout << "Sorting nodes by memory location (descending):" << std::endl;
        mySequence.sortByMemoryLocation(false);
        std::cout << mySequence << std::endl;

        // clear()
        mySequence.clear();
        std::cout << "After clear(): " << mySequence << std::endl;
        std::cout << "Is empty? " << (mySequence.empty() ? "Yes" : "No") << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of Test ===" << std::endl;
    return 0;
}
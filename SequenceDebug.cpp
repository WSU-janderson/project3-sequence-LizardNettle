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
    cout << "Sequence Class Tester" << endl;

    // Test empty constructor
    Sequence s1(0);
    cout << "Created empty Sequence s1" << endl;
    cout << "s1.empty() = " << boolalpha << s1.empty() << endl;

    Sequence s2(3);
    s2[0] = "apple";
    s2[1] = "banana";
    s2[2] = "cherry";
    cout << "\nCreated sequence s2 with 3 elements: " << s2 << endl;

    // Test copy constructor
    Sequence s3 = s2;
    cout << "Copied s2 into s3: " << s3 << endl;

    // Test assignment operator
    Sequence s4(2);
    s4[0] = "x";
    s4[1] = "y";
    cout << "\nBefore assignment, s4 = " << s4 << endl;
    s4 = s2;
    cout << "After assignment (s4 = s2), s4 = " << s4 << endl;

    // Test push_back
    cout << "\nTesting push_back..." << endl;
    s4.push_back("date");
    cout << "After push_back('date'): " << s4 << endl;

    // Test pop_back
    cout << "\nTesting pop_back..." << endl;
    s4.pop_back();
    cout << "After pop_back(): " << s4 << endl;

    // Test front() and back()
    cout << "\nTesting front() and back():" << endl;
    cout << "Front of s4: " << s4.front() << endl;
    cout << "Back of s4: " << s4.back() << endl;

    // Test insert()
    cout << "\nTesting insert() at position 1 (insert 'blueberry')..." << endl;
    try {
        s4.insert(1, "blueberry");  // you still need to implement insert()
        cout << "After insert: " << s4 << endl;
    } catch (const out_of_range &e) {
        cout << "Insert failed: " << e.what() << endl;
    }

    // Test erase(position)
    cout << "\nTesting erase(position = 1)..." << endl;
    try {
        s4.erase(1);
        cout << "After erase(1): " << s4 << endl;
    } catch (const out_of_range &e) {
        cout << "Erase failed: " << e.what() << endl;
    }

    // Test erase(position, count)
    cout << "\nTesting erase(position = 0, count = 1)..." << endl;
    try {
        s4.erase(0, 1);
        cout << "After erase(0, 1): " << s4 << endl;
    } catch (const out_of_range &e) {
        cout << "Erase failed: " << e.what() << endl;
    }

    // Test clear()
    cout << "\nTesting clear()..." << endl;
    s4.clear();
    cout << "After clear(), s4.empty() = " << s4.empty() << endl;

    // Test exception handling
    cout << "\nTesting out_of_range access..." << endl;
    try {
        cout << s2[10] << endl; // invalid access
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "\n===== Testing Complete =====" << endl;
    return 0;
}
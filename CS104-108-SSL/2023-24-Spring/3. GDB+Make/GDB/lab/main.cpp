#include <fstream>
#include <iostream>
#include <stdexcept>
#include "MyString.cpp"

// You should modify this file to check your own testcases
// You are encouraged to test your own testcases as well as 
// the gives ones are incomplete
// compile with `g++ main.cpp` and run with `./a.out`

bool allTestsPassed = true;  // Global flag to track failures

void check(bool condition) {
    if (!condition) allTestsPassed = false;
}

void testMyString() {
    MyString empty;
    check(empty.size() == 0);
    check(empty.c_str()[0] == '\0');  

    MyString str1("Hello");
    check(str1.size() == 5);
    check(str1.c_str()[0] == 'H');

    MyString str2(str1);
    check(str2 == str1);

    MyString str3;
    str3 = str1;
    check(str3 == str1);

    MyString str4 = str1 + MyString(" World");
    check(str4 == MyString("Hello World"));

    str3 += MyString("!");
    check(str3 == MyString("Hello!"));

    check(str1[0] == 'H');
    check(str1[4] == 'o');
    str3[3] = 't';
    check(str3[3] == 't');

    try {
        char x = empty[0];  
        (void)x;
        allTestsPassed = false;
    } catch (const std::out_of_range&) {}


    check(MyString("abc") == MyString("abc"));

    MyString substr1 = str1.substr(1, 3);
    check(substr1 == MyString("ell"));

    MyString longStr("This is a very long string to test memory handling and correctness.");
    check(longStr.size() == 67);

    std::fstream fin("test_input.txt");
    MyString testInput;
    fin >> testInput;
    check(testInput == MyString("Hello"));
}

int main() {
    testMyString();
    
    if (allTestsPassed)
        std::cout << "All tests passed!\n";
    else
        std::cout << "Testcases Failed\n";

    return 0;
}

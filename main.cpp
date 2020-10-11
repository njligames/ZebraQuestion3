#include <iostream>
#include "PaperStrip.h"

static const std::string ERROR_STRING("Error: The values in the arrays are incorrect.");

static int test1() {
    std::vector<int> original = { 1, 4, 3, 2 };
    std::vector<int> desired =  { 1, 2, 4, 3 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
    
}

static int test2() {
    // NOTE: These datasets do work with minPieces, but they do not satisfy
    // the requirements according to the specifications. (non sequential)
    std::vector<int> original = { 1, 4, 3, 2, 7, 8, 9 };
    std::vector<int> desired =  { 1, 2, 4, 3, 9, 7, 8 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

static int test3() {
    // NOTE: These datasets do work with minPieces, but they do not satisfy
    // the requirements according to the specifications. (non sequential)
    std::vector<int> original = { 1, 4, 3, 2, 7, 8, 9 };
    std::vector<int> desired =  { 1, 2, 4, 3, 7, 8, 9 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

static int test4() {
    std::vector<int> original = { 1 };
    std::vector<int> desired =  { 1 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

static int test5() {
    std::vector<int> original = { 1, 2 };
    std::vector<int> desired =  { 2, 1 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

static int test6() {
    std::vector<int> original = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    std::vector<int> desired =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

static int test7() {
    std::vector<int> original = { };
    std::vector<int> desired =  { };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

static int test8() {
    // Invalid data set (array of different sizes)
    std::vector<int> original = { };
    std::vector<int> desired =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

static int test9() {
    // Invalid data set (array does not have sequential values)
    std::vector<int> original = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16 };
    std::vector<int> desired =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16 };
    
    if(!PaperStrip::canPerformMinPieces(original, desired))
        throw ERROR_STRING.c_str();
    
    return (PaperStrip::minPieces(original, desired));
}

#ifndef RunTests
int main()
{
    int val(0);
    
    try {
        val = test1();
        assert(3 == val && "Test 1 failed");
        std::cout << val << " - (1), (4, 3), and (2)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test2();
        assert(5 == val && "Test 2 failed");
        std::cout << val << " - (1), (2), (4, 3), (9), and (7, 8)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test3();
        assert(4 == val && "Test 3 failed");
        std::cout << val << " - (1), (2), (4, 3), and (7, 8, 9)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test4();
        assert(1 == val && "Test 4 failed");
        std::cout << val << " - (1)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test5();
        assert(2 == val && "Test 5 failed");
        std::cout << val << " - (1), and (2)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test6();
        assert(1 == val && "Test 6 failed");
        std::cout << val << " - (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)" << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test7();
        assert(0 == val && "Test 7 failed");
        std::cout << val << " - " << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test8();
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    try {
        val = test9();
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
    
    return 0;
}
#endif

// CSCI 2530
// Assignment: 3
// Author:     Brandon Gachuz
// File:       testequiv.cpp
// Tab stops:  4

#include "equiv.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    
    ER relation = newER(7);
    
    printf("The leader of %i is: %i\n", 1, leader(relation, 1));
    
    merge(relation, 3, 5);
    merge(relation, 5, 1);
    
    cout << "The equivalence of 1 and 3 is: " << equivalent(relation, 1, 3) << endl;
    
    merge(relation, 2, 1);
    merge(relation, 6, 7);
    merge(relation, 1, 6); // Tests are correct
    
    showER(relation, 7);
    
    destroyER(relation);
    
    putchar('\n');
    
    // NEW TEST
    
    cout << "\t\tNew Test:\n" << endl;
    
    ER hello = newER(10);
    
    cout << "The leader of 7 is: " << leader(hello, 7) << endl;
    cout << "The leader of 1 is: " << leader(hello, 1) << endl;
    
    merge(hello, 1, 2);
    merge(hello, 3, 4);
    merge(hello, 5, 4);
    merge(hello, 2, 4);
    
    showER(hello, 10);
    
    cout << "\nThe leader of 5 is: " << leader(hello, 5) << endl;
    cout << "\nThe leader of 4 is: " << leader(hello, 4) << endl;
    cout << "Number of consitituents of 1: "
    << hello[leader(hello, 0)].numConstituents << endl;
    
    destroyER(hello);
    
    putchar('\n');
    return 0;
}

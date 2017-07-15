// Author:     Brandon Gachuz
// File:       equiv.cpp
// Tab stops:  4

/*
 This program is an equivalence relations tool which has the ability to:
 - Create a new equivalence relation object and store it in the heap.
 - Display the leader of a particular number in the relation.
 - Display true or false if two numbers have the same leader in the relation.
 - Merge two numbers in the relation.
 - Destroy the equivalence relation memory in the heap.
 - Display the entire equivalence relation (index, leader, and constituents).
 */

#include "equiv.h"
#include <iostream>
using namespace std;

// newER(n) uses 'n' to accomodate the size of the array needed to create
// a new equivalence relation.

ER newER(int n)
{
    ER p = new equivRel[n + 1];
    
    for (int i = 1; i < n + 1; i++)
    {
        p[i].leader = 0;
        p[i].numConstituents = 1;
    }
    return p;
}

// leader(e, x) searches for the leader of integer 'x' in the equivalence relation 'e'
// and returns the leader.

int leader(ER e, int x)
{
    if (e[x].leader == 0)
    {
        return x;
    }
    else
    {
        e[x].leader = leader(e, e[x].leader);
        return e[x].leader;
    }
}

// Returns true if 'x' and 'y' have the same leader in equivalence relation 'e'.
// False otherwise.

bool equivalent(ER e, int x, int y)
{
    return (leader(e, x) == leader(e, y) ? true : false);
}

// Merges integers 'x' and 'y' in the relation 'rel' if they are not already
// members of the same leader and is also based on the number of their constituents.

void merge(ER rel, int x, int y)
{
    int bossX = leader(rel, x);
    int bossY = leader(rel, y);
    int cnstX = rel[bossX].numConstituents;
    int cnstY = rel[bossY].numConstituents;
    
    if (bossX != bossY)
    {
        if (cnstY > cnstX || cnstY == cnstX)
        {
            rel[bossY].numConstituents += cnstX;
            rel[bossX].leader = bossY;
            rel[bossX].numConstituents = 0;
        }
        else
        {
            rel[bossX].numConstituents += cnstY;
            rel[bossY].leader = bossX;
            rel[bossY].numConstituents = 0;
        }
    }
    
}

// destroyER deletes the pointer 'e' in the heap to the array created.

void destroyER(ER e)
{
    delete [] e;
}

// Displays equivalence relation 'e' to the console.
// This function is for debugging purposes only.

void showER(ER e, int n)
{
    cout << "Index\tLeader\tConstituents" << endl;
    for (int i = 1; i < n+1; i++)
    {
        cout << " " << i << "\t\t " << leader(e, i) << "\t\t "
        << e[i].numConstituents << endl;
    }
}

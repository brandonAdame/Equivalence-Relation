// CSCI 2530
// Assignment: 3
// Author:     Brandon Gachuz
// File:       equiv.h
// Tab stops:  4

// These #ifndef and #define lines make it so that, if this file is
// read more than once by the compiler, its body is skipped on all
// but the first time it is read.

#ifndef EQUIV_H
#define EQUIV_H

// An equivalence relation is an array of integers.
// So ER abbreviates equivRel*.

struct equivRel {
    int leader;
    int numConstituents;
};

typedef equivRel* ER;

// Public functions

ER   newER      (int n);
void destroyER  (ER e);
bool equivalent (ER e, int x, int y);
void merge      (ER e, int x, int y);

// The following is advertised here solely for debugging.  These must
// only be used for debugging.

void showER(ER e, int n);
int  leader(ER e, int x);

#endif

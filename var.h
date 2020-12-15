
#ifndef var_h
#define var_h

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <thread>
#include <sys/time.h>


struct Node {
    int data;
    int prior;
    Node* next;
};

struct pqueue {
    Node *head;
    pqueue(void) :head(NULL) {}
};

Node* top(pqueue& que);
void push(pqueue& que, int value, int priority);
void pop(pqueue&, int&);
void show(pqueue&);
void getPriority(pqueue&, int&);
int size(pqueue&);
void Swap(pqueue& que);
void orders(pqueue &que, int size, int from, int to, int Pfrom, int Pto, int _time);

#endif /* var_h */

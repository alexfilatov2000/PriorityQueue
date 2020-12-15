
#include "var.h"

using namespace std;

void push(pqueue& que, int value, int priority) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->prior = priority;
    if (!que.head) {
        que.head = temp;
        return;
    }
    Node *cursor = que.head,
    *prev = NULL;
    while (cursor && (temp->prior > cursor->prior)) {
        prev = cursor;
        cursor = cursor->next;
    }
    if (cursor == que.head) {
        temp->next = que.head;
        que.head = temp;
        return;
    }
    prev->next = temp;
    if (!cursor)
        return;
    temp->next = cursor;
}

void pop(pqueue& que, int& get){
    if (!que.head)
        return;
    if (!que.head->next) {
        get = que.head->data;
        delete que.head;
        que.head = NULL;
        return;
    }
    Node *end, *prev;
    end = prev = que.head;
    while (end->next) {
        prev = end;
        end = end->next;
    }
    get = end->data;
    prev->next = NULL;
    delete end;
}

Node* top(pqueue& que){
    Node *last;
    for (Node* i = que.head; i != 0; i = i->next){
        last = i;
    }
    return last;
}

void show(pqueue& que) {
    Node *cursor = que.head;
    while (cursor) {
        cout << cursor->data <<"(" << cursor->prior <<") ";
        cursor = cursor->next;
    }
    cout<<endl;
}

void getPriority(pqueue& que, int& get) {
    Node *cursor = que.head;
    while (cursor->next)
        cursor = cursor->next;
    get = cursor->prior;
}

int size(pqueue& que) {
    int size = 0;
    Node *cursor = que.head;
    for (; cursor; size++, cursor = cursor->next);
    return size;
}

void Swap(pqueue& que) {
    pqueue temp;
    int max = 0,
    min = 0,
    current = 0,
    get,
    n = size(que);
    getPriority(que, max);
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            getPriority(que, min);
        getPriority(que, current);
        pop(que, get);
        push(temp, get, current);
        
    }
    for (int i = 0; i < n; i++) {
        getPriority(temp, current);
        if (current == min) {
            pop(temp, get);
            push(que, get, max);
        }
        else if(current == max){
            pop(temp, get);
            push(que, get, min);
        }
        else {
            pop(temp, get);
            push(que, get, current);
        }
    }
}

void orders(pqueue &que, int size, int from, int to, int Pfrom, int Pto, int _time){
    srand(time(NULL));
    int weight = 0;
    int prior = 0;
    int avg = 0;
    
    for (int i = 0; i < size; i++){
        timeval s_time;
        gettimeofday(&s_time, NULL);
        long start = (s_time.tv_sec * 1000) + (s_time.tv_usec / 1000);
        
        this_thread::sleep_for(chrono::milliseconds(_time));
        weight = from + (rand() % (to - from + 1));
        prior = Pfrom + (rand() % (Pto - Pfrom + 1));
        push(que, weight, prior);
        
        gettimeofday(&s_time, NULL);
        long finish = (s_time.tv_sec * 1000) + (s_time.tv_usec / 1000);
        avg += finish - start;
        cout << weight <<"(" << prior <<") ";
    }
    cout<<endl;
    avg /= size;
    cout<<"All_time = "<<_time<<"msec \navg = "<<avg<<"msec \ndelay = "<<avg - _time<<"msec"<<endl;
}

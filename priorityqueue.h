#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BookRequest.h"

class PriorityQueue
{
private:
    BookRequestNode* front;
    BookRequestNode* rear;
    int count;

public:
    PriorityQueue();

    void Add(BookRequestNode* request);
    BookRequestNode* Remove();

    bool IsEmpty();
    bool IsNotEmpty();

    void PrintQueue();
    int GetCount();

    ~PriorityQueue();
};

#endif
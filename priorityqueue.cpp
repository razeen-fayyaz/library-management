 
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// Constructor
PriorityQueue::PriorityQueue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

// Add request according to priority
void PriorityQueue::Add(BookRequestNode* request)
{
    if (request == nullptr)
        return;

    request->next = nullptr;

    if (front == nullptr)
    {
        front = request;
        rear = request;
    }
    else if (request->priority < front->priority)
    {
        request->next = front;
        front = request;
    }
    else
    {
        BookRequestNode* current = front;

        while (current->next != nullptr &&
               current->next->priority <= request->priority)
        {
            current = current->next;
        }

        request->next = current->next;
        current->next = request;

        if (request->next == nullptr)
            rear = request;
    }

    count++;
}

// Remove highest-priority request
BookRequestNode* PriorityQueue::Remove()
{
    if (front == nullptr)
        return nullptr;

    BookRequestNode* request = front;
    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    request->next = nullptr;
    count--;

    return request;
}

// Check whether queue is empty
bool PriorityQueue::IsEmpty()
{
    return front == nullptr;
}

// Check whether queue is not empty
bool PriorityQueue::IsNotEmpty()
{
    return front != nullptr;
}

// Return total requests
int PriorityQueue::GetCount()
{
    return count;
}

// Display all requests
void PriorityQueue::PrintQueue()
{
    if (front == nullptr)
    {
        cout << "\nNo book requests available.\n";
        return;
    }

    BookRequestNode* current = front;

    while (current != nullptr)
    {
        cout << "\nStudent ID: " << current->studentID << endl;
        cout << "Student Name: " << current->studentName << endl;
        cout << "Book ID: " << current->bookID << endl;
        cout << "Book Title: " << current->bookTitle << endl;
        cout << "Priority: " << current->priority << endl;
        cout << "-----------------------------\n";

        current = current->next;
    }
}

// Destructor
PriorityQueue::~PriorityQueue()
{
    while (front != nullptr)
    {
        BookRequestNode* temp = front;
        front = front->next;
        delete temp;
    }

    rear = nullptr;
    count = 0;
}

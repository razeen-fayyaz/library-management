#include "BookRequest.h"

BookRequestNode* CreateRequest(
    int studentID,
    string studentName,
    int bookID,
    string bookTitle,
    int priority)
{
    BookRequestNode* request = new BookRequestNode;

    request->studentID = studentID;
    request->studentName = studentName;
    request->bookID = bookID;
    request->bookTitle = bookTitle;
    request->priority = priority;
    request->next = nullptr;

    return request;
}
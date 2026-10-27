#ifndef BOOKREQUEST_H
#define BOOKREQUEST_H

#include <string>
using namespace std;

struct BookRequestNode
{
    int studentID;
    string studentName;
    int bookID;
    string bookTitle;
    int priority;

    BookRequestNode* next;
};

BookRequestNode* CreateRequest(
    int studentID,
    string studentName,
    int bookID,
    string bookTitle,
    int priority
);

#endif
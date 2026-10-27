#include <iostream>
#include <limits>
#include <string>

#include "PriorityQueue.h"
#include "HardCodedData.h"

using namespace std;

int main()
{
    PriorityQueue requests;

    LoadHardCodedData(requests);

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << " LIBRARY BOOK REQUEST MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Display All Book Requests\n";
        cout << "2. Add New Book Request\n";
        cout << "3. Process Highest-Priority Request\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Display Total Requests\n";
        cout << "6. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                cout << "\n=== ALL BOOK REQUESTS ===\n";
                requests.PrintQueue();
                break;

            case 2:
            {
                int studentID, bookID, priority;
                string studentName, bookTitle;

                cout << "Enter Student ID: ";
                if (!(cin >> studentID) || studentID <= 0)
                {
                    cout << "Invalid Student ID.\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Student Name: ";
                getline(cin >> ws, studentName);

                cout << "Enter Book ID: ";
                if (!(cin >> bookID) || bookID <= 0)
                {
                    cout << "Invalid Book ID.\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Book Title: ";
                getline(cin >> ws, bookTitle);

                cout << "Enter Priority (1-3): ";
                if (!(cin >> priority) ||
                    priority < 1 || priority > 3)
                {
                    cout << "Invalid priority. Use 1, 2, or 3.\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                requests.Add(CreateRequest(
                    studentID,
                    studentName,
                    bookID,
                    bookTitle,
                    priority));

                cout << "Book request added successfully!\n";
                break;
            }

            case 3:
            {
                BookRequestNode* processed = requests.Remove();

                if (processed == nullptr)
                {
                    cout << "No requests to process.\n";
                }
                else
                {
                    cout << "\n=== PROCESSED REQUEST ===\n";
                    cout << "Student: "
                         << processed->studentName << endl;
                    cout << "Book: "
                         << processed->bookTitle << endl;
                    cout << "Priority: "
                         << processed->priority << endl;

                    delete processed;
                }
                break;
            }

            case 4:
                if (requests.IsEmpty())
                    cout << "The queue is empty.\n";
                else
                    cout << "The queue is not empty.\n";
                break;

            case 5:
                cout << "Total pending requests: "
                     << requests.GetCount() << endl;
                break;

            case 6:
                cout << "Program closed successfully.\n";
                break;

            default:
                cout << "Invalid choice. Select 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}

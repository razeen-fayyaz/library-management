
#include "HardCodedData.h"
#include "BookRequest.h"

void LoadHardCodedData(PriorityQueue& requests)
{
    requests.Add(CreateRequest(
        101, "Ali", 501, "Data Structures", 3));

    requests.Add(CreateRequest(
        102, "Ahmed", 502, "Database Systems", 1));

    requests.Add(CreateRequest(
        103, "Bilal", 503, "Operating Systems", 2));

    requests.Add(CreateRequest(
        104, "Hamza", 504, "Computer Networks", 1));
}

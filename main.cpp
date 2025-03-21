#include "cash_flow.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numPersons;
    cout << "Enter the number of people: ";
    cin >> numPersons;

    vector<vector<int>> graph(numPersons, vector<int>(numPersons, 0));

    cout << "Enter the transaction matrix (row-wise):\n";
    for (int i = 0; i < numPersons; i++)
    {
        for (int j = 0; j < numPersons; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Minimizing cash flow:\n";
    minimizeCashFlow(graph, numPersons);

    return 0;
}

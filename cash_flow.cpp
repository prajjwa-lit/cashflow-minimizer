#include "cash_flow.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Function to find the person who has maximum debt (min cash flow)
int getMinIndex(vector<int> &netAmount)
{
    int minIndex = 0;
    for (int i = 1; i < netAmount.size(); i++)
    {
        if (netAmount[i] < netAmount[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the person who has maximum credit (max cash flow)
int getMaxIndex(vector<int> &netAmount)
{
    int maxIndex = 0;
    for (int i = 1; i < netAmount.size(); i++)
    {
        if (netAmount[i] > netAmount[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to settle transactions recursively
void settleTransactions(vector<int> &netAmount)
{
    int minIdx = getMinIndex(netAmount);
    int maxIdx = getMaxIndex(netAmount);

    if (netAmount[minIdx] == 0 && netAmount[maxIdx] == 0)
    {
        return; // All debts settled
    }

    int minAmount = min(-netAmount[minIdx], netAmount[maxIdx]);
    netAmount[minIdx] += minAmount;
    netAmount[maxIdx] -= minAmount;

    cout << "Person " << minIdx << " pays " << minAmount << " to Person " << maxIdx << endl;

    // Recursively settle remaining transactions
    settleTransactions(netAmount);
}

// Main function to minimize cash flow
extern "C"
{
    void minimizeCashFlow(vector<vector<int>> &graph, int numPersons)
    {
        vector<int> netAmount(numPersons, 0);

        // Calculate the net amount each person needs to pay
        for (int p = 0; p < numPersons; p++)
        {
            for (int q = 0; q < numPersons; q++)
            {
                netAmount[p] += (graph[q][p] - graph[p][q]);
            }
        }

        // Settle the transactions
        settleTransactions(netAmount);
    }
}
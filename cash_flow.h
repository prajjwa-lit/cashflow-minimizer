#ifndef CASH_FLOW_H
#define CASH_FLOW_H

#include <vector>

extern "C"
{
    void minimizeCashFlow(std::vector<std::vector<int>> &graph, int numPersons);
}

#endif

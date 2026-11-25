
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 4;

    int cost[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int path[] = {1, 2, 3};
    int minCost = 99999;

    do {
        int currentCost = 0;
        int k = 0;

        for (int i = 0; i < n - 1; i++) {
            currentCost += cost[k][path[i]];
            k = path[i];
        }

        currentCost += cost[k][0];

        if (currentCost < minCost) {
            minCost = currentCost;
        }

    } while (next_permutation(path, path + n - 1));

    cout << "Minimum travelling cost = "
         << minCost;

    return 0;
}

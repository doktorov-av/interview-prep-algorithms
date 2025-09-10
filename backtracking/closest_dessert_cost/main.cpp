//
// Created by doktorov-av on 9/10/25.
//

// 1774. Closest dessert cost (leetcode)

#include <climits>
#include <iostream>
#include <numeric>
#include "algorithm"
#include "vector"

// 1774. Closest Dessert Cost

class Solution {
    int target = 0;
    std::vector<int> tCosts = {};
public:
    int closestCost(std::vector<int>& baseCosts, std::vector<int>& toppingCosts, int target) {
        this->target = target;
        this->tCosts = toppingCosts;

        int result = 0;
        for (const auto baseCost : baseCosts) {
            const auto sum = backtrackTopping(0, baseCost);
            if (result != 0) {
                result = closest(result, sum);
            } else {
                result = sum;
            }
        }
        return result;
    }

    int backtrackTopping(int iTop, int sum) {
        if (iTop >= tCosts.size()) {
            return sum;
        }

        const auto a = backtrackTopping(iTop + 1, sum);
        const auto b = backtrackTopping(iTop + 1, sum + tCosts[iTop]);
        const auto c = backtrackTopping(iTop + 1, sum + 2 * tCosts[iTop]);

        sum = closest(a, closest(b, c));
        return sum;
    }

    int closest(int a, int b) {
        const auto aDiff = std::abs(target - a);
        const auto bDiff = std::abs(target - b);
        if (aDiff < bDiff) {
            return a;
        }
        if (aDiff == bDiff) {
            return std::min(a, b);
        }
        return b;
    }
};

int main() {
    std::vector<int> baseCosts = {10};
    std::vector<int> toppingCosts = {1};
    std::cout << Solution().closestCost(baseCosts, toppingCosts, 1);
}
//
// Created by doktorov-av on 9/10/25.
//

// 39. Combination Sum

#include <iostream>
#include <map>
#include <numeric>
#include "algorithm"
#include "vector"


class Solution {
    int target = 0;
public:
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target) {
        this->target = target;
        std::vector<std::vector<int>> out{};
        sumUp(candidates, {}, out);
        return out;
    }

    int sumUp(const std::vector<int>& candidates, std::vector<int> combo, std::vector<std::vector<int>>& out) {
        int s = summarize(combo);

        if (s > target) {
            return 0;
        }
        if (s == target && !alreadyExists(combo, out)) {
            out.emplace_back(combo);
            return 0;
        }

        for (auto v : candidates) {
            combo.emplace_back(v);
            sumUp(candidates, combo, out);
            combo.pop_back();
        }

        return summarize(combo);
    }


    bool alreadyExists(const std::vector<int>& combo, const std::vector<std::vector<int>>& combinations) {
        for (const auto& c : combinations) {
            if (c.size() != combo.size())
                continue;

            if (equal(c, combo))
                return true;
        }
        return false;
    }

    bool equal(const std::vector<int>& combo1, const std::vector<int>& combo2) {
        std::map<int, int> freq{};
        for (auto v : combo1) {
            ++freq[v];
        }
        for (auto v : combo2) {
            if (--freq[v] < 0) {
                return false;
            }
        }
        return true;
    }

    static int summarize(const std::vector<int>& values) {
        return std::accumulate(values.begin(), values.end(), 0);
    }
};

int main() {
    for (const auto& v : Solution().combinationSum({2,3,6,7}, 7)) {
        for (const auto i : v) {
            std::cout << i << '\t';
        }
        std::cout << '\n';
    }
}
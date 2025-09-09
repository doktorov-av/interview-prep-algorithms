//
// Created by doktorov-av on 9/9/25.
//

#include "iostream"
#include "string"
#include "map"
#include "vector"


class Solution {
    static const std::map<char, std::string> map;
    std::vector<std::string> res = {};
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        backtrack(digits, 0, "");
        return res;
    }
private:
    void backtrack(const std::string &digits, size_t pos, const std::string& combo) {
        if (pos == digits.size()) {
            res.emplace_back(combo);
            return;
        }

        const std::string &chars = map.at(digits[pos]);
        for (const auto &ch : chars) {
            backtrack(digits, pos + 1, combo + ch);
        }
    }
};

const std::map<char, std::string> Solution::map = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
};


void printRange(auto &&R) {
    std::cout << '[';
    for (const auto &v : R) {
        std::cout << v << '\t';
    }
    std::cout << "]\n";
}

int main() {
    printRange(Solution().letterCombinations("23"));
    return 0;
}

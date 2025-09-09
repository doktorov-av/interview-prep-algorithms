//
// Created by doktorov-av on 9/9/25.
//

#include <iostream>
#include <string>
#include <vector>

struct testData {
    std::string givenIp;
    std::vector<std::string> expectedVariations;
};

std::vector<testData> tests = {
        {"0000", {"0.0.0.0"}},
        {"1000", {"1.0.0.0"}},
        {"11000", {"1.10.0.0", "11.0.0.0", "1.1.0.0.0"}}, // Note: "1.1.0.0.0" is invalid, correct should be "1.10.0.0",
                                                          // "11.0.0.0", "1.1.0.0" is invalid due to extra segment
};

class Solution {
public:
    std::vector<std::string> findVariations(const std::string &str) {
        std::vector<std::string> variations = {};
        findVariationsImpl(str, 0, 0, "", variations);
        return variations;
    }

    // @str original ip string
    // @dots where dots were placed
    // @variations resulting array of ip variations
    void findVariationsImpl(const std::string &str, size_t start, size_t nDots, const std::string &current_ip, std::vector<std::string> &variations) {
        if (nDots == 3) {
            const auto seg = str.substr(start);
            if (isValidSegment(seg)) {
                variations.emplace_back(current_ip + seg);
            }
            return;
        }

        for (size_t len = 1; len <= 3; ++len) {
            if (start + len > str.size()) {
                break;
            }
            const auto seg = str.substr(start, len);
            if (isValidSegment(seg)) {
                findVariationsImpl(str, start + len, nDots + 1, current_ip + seg + ".", variations);
            }
        }
    }

    bool isValidSegment(const std::string &segment) {
        size_t n = segment.size();
        if (n == 0 || n > 3) {
            return false;
        }
        if (segment[0] == '0' && n > 1) {
            return false;
        }
        int num = std::stoi(segment);
        return num <= 255;
    }
};

int main() {
    Solution solution;
    for (const auto& test : tests) {
        std::vector<std::string> result = solution.findVariations(test.givenIp);
        std::cout << "Test: " << test.givenIp << "\nExpected: ";
        for (const auto& expected : test.expectedVariations) {
            std::cout << expected << " ";
        }
        std::cout << "\nGot: ";
        for (const auto& res : result) {
            std::cout << res << " ";
        }
        std::cout << "\n\n";
    }
    return 0;
}
//
// Created by doktorov-av on 9/9/25.
//

#include <iostream>
#include <string>
#include "algorithm"
#include "format"
#include "limits"
#include "vector"

// this is an example input for testing and algorithm
struct TspData {
    std::vector<std::vector<int>> distances{};
    std::vector<std::string> cities{};

    TspData() {
        distances = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
        cities = std::vector<std::string>(distances.size(), "");
    }
    explicit TspData(std::vector<std::string> inCities) : cities(std::move(inCities)) {
        distances.resize(cities.size());
        for (auto &row: distances) {
            row.resize(cities.size());
        }

        int iColStart = 0;
        for (int iRow = 0; iRow < distances.size(); ++iRow) {
            int iCol = iColStart;
            distances[iRow][iCol++] = 0; // fill diagonal
            while (iCol < cities.size()) { // fill matrix
                const int distance = rand() % 100;
                distances[iRow][iCol] = distance;
                distances[iCol][iRow] = distance;
                ++iCol;
            }
            ++iColStart;
        }
    }
    void print() const {
        std::cout << "Cities: ";
        for (size_t i = 0; i < cities.size(); ++i) {
            std::cout << std::format("[{}] ", cities[i]);
        }

        std::cout << "\nDistances: \n";
        for (const auto &row: distances) {
            for (const auto &value: row) {
                std::cout << value << ' ';
            }
            std::cout << '\n';
        }
    }
};

class Solution {
public:
    Solution() = default;

    int getShortestRouteDistance(const std::vector<std::vector<int>> &distances) {
        // current visited cites
        std::vector<int> cities = {0};

        // current shortest path
        int min_dist = std::numeric_limits<int>::max();
        int curr_dist = 0;

        return shortestRouteImpl(distances, cities, curr_dist, min_dist);
    }

private:
    int shortestRouteImpl(const std::vector<std::vector<int>> &distances, std::vector<int> &cities, int curr_dist,
                          int &min_dist) {
        // this is last city, we should return curr_dist + distance between first and last city
        if (cities.size() == distances.size()) {
            return curr_dist + distances[cities.back()][cities.front()];
        }

        for (int i = 0; i < distances.size(); ++i) {
            // check if city has been visited
            // if not, check if distance is less that min_dist
            if (!isVisited(i, cities)) {
                const auto newDist = curr_dist + distances[cities.back()][i];
                cities.emplace_back(i); // visit city

                // if new min distance is greater than current, skip
                if (newDist < min_dist) {
                    min_dist = shortestRouteImpl(distances, cities, newDist, min_dist);
                }

                cities.pop_back();
            }
        }
        return min_dist;
    }

    static bool isVisited(const int i, const std::vector<int> &cities) {
        return std::ranges::find(cities, i) != cities.end();
    }
};

int main() {
    auto tspData = TspData();
    tspData.print();
    std::cout << Solution().getShortestRouteDistance(tspData.distances);
    return 0;
}

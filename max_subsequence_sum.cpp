// max_subsequence_sum.h

#ifndef MAX_SUBSEQUENCE_SUM_H
#define MAX_SUBSEQUENCE_SUM_H

#include <String>
#include <vector>
#include <utility>

typedef std::pair<std::string, double> DateValuePair;

double calculateAverage(const std::vector<DateValuePair>& sequence);
std::pair<std::string, std::string> findMaxSubsequence(const std::vector<DateValuePair>& sequence);

#endif // MAX_SUBSEQUENCE_SUM_H
// max_subsequence_sum.cpp

#include "max_subsequence_sum.h"

double calculateAverage(const std::vector<DateValuePair>& sequence) {
    double sum = 0.0;

    for (const auto& data : sequence) {
        sum += data.second;
    }

    return sum / static_cast<double>(sequence.size());
}

std::pair<std::string, std::string> findMaxSubsequence(const std::vector<DateValuePair>& sequence) {
    double maxSum = 0;
    double currentSum = 0;
    std::pair<std::string, std::string> maxPeriod;

    int start = 0;
    int currentStart = 0;

    for (int i = 0; i < sequence.size(); ++i) {
        currentSum += sequence[i].second;

        if (currentSum < 0) {
            currentSum = 0;
            currentStart = i + 1;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxPeriod.first = sequence[currentStart].first;
            maxPeriod.second = sequence[i].first;
        }
    }

    return maxPeriod;
}
// max_subsequence_sum.h

#ifndef MAX_SUBSEQUENCE_SUM_H
#define MAX_SUBSEQUENCE_SUM_H

#include <vector>
#include <String>
#include <utility>

typedef std::pair<std::string, double> DateValuePair;

double calculateAverage(const std::vector<DateValuePair>& sequence);
std::pair<std::string, std::string> findMaxSubsequence(const std::vector<DateValuePair>& sequence);

#endif // MAX_SUBSEQUENCE_SUM_H
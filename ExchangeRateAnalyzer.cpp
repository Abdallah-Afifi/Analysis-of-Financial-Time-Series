#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <String>
#include "heap.h"
#include "max_subsequence_sum.h"

// Function to parse CSV data and load it into a vector of pairs
std::vector<DateValuePair> loadData(const std::string& filename) {
    std::vector<DateValuePair> data;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, rateStr;

        if (std::getline(iss, dateStr, ',') && std::getline(iss, rateStr, ',')) {
            double rate = std::stod(rateStr);
            data.emplace_back(dateStr, rate);
        }
    }

    file.close();
    return data;
}

int main() {
    
    
    std::vector<std::string> files = {
        "australian-dollar.csv",
        "dollar-franc.csv",
        "dollar-index.csv",
        "dollar-peso.csv",
        "dollar-singapore.csv",
        "dollar-yen.csv",
        "dollar-yuan.csv",
        "euro-dollar.csv",
        "euro-franc.csv",
        "euro-pound.csv",
        "euro-yen.csv",
        "pound-dollar.csv",
        "pound-yen.csv",
        "newzealand-dollar.csv"
    };

    // Display menu to select file
    std::cout << std::endl << "Select a file to analyze:" << std::endl << std::endl;
    for (size_t i = 0; i < files.size(); ++i) {
        std::cout << i + 1 << ". " << files[i] << std::endl;
    }

    int choice;
    std::cout << std::endl << "Enter the number corresponding to the file: " << std::endl;
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(files.size())) {
        std::cerr << "Invalid choice. Exiting." << std::endl;
        return 1;
    }

    // Load data from the selected file
    std::string selectedFile = files[choice - 1];
    std::vector<DateValuePair> exchangeRates = loadData(selectedFile);

    if (exchangeRates.empty()) {
        std::cerr << "No data loaded. Exiting." << std::endl;
        return 1;
    }

    // Calculate the average exchange rate
    double averageRate = calculateAverage(exchangeRates);

    // Build max heap and min heap for positive and negative changes
    MaxHeap maxHeap;
    MinHeap minHeap;

    for (const auto& data : exchangeRates) {
        double change = data.second - averageRate;
        maxHeap.insert(data.first, change);
        minHeap.insert(data.first, change);
    }

    // Find the N highest and N lowest exchange rates
    int N = 10;
    std::cout << "Top " << N << " highest exchange rates:" << std::endl;
    for (int i = 0; i < N; ++i) {
        auto maxChange = maxHeap.extractMax();
        std::cout << "Date: " << maxChange.first << ", Change: " << maxChange.second << std::endl;
    }

    std::cout << "\nTop " << N << " lowest exchange rates:" << std::endl;
    for (int i = 0; i < N; ++i) {
        auto minChange = minHeap.extractMin();
        std::cout << "Date: " << minChange.first << ", Change: " << minChange.second << std::endl;
    }

    // Find the contiguous period with maximum sum of rate changes
    auto maxSubsequence = findMaxSubsequence(exchangeRates);

    std::cout << "\nMaximum Subsequence Sum Period:" << std::endl;
    std::cout << "Start Date: " << maxSubsequence.first << ", End Date: " << maxSubsequence.second << std::endl;

    std::cout << std::endl << "Do you want to analyze another file? Y/N" << std::endl;
    char option; 
    std::cin >> option;
    if (option == 'Y' || option == 'y') {
        main();
    }
    else exit(0);

    return 0;
}
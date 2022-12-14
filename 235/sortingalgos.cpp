#include <iostream>
#include <vector>

std::vector<int> selectionSort(std::vector<int> arr) {
    std::vector<int> result = arr;
    for (int i = 0; i < result.size(); i++) {
        int smallestIndx = i;
        for (int j = i; j < result.size(); j++) {
            if (result[j] < result[smallestIndx]) {
                smallestIndx = j;
            }
        }
        std::swap(result[i], result[smallestIndx]);
    }
    return result;
}

std::vector<int> bubbleSort(std::vector<int> arr) {
    std::vector<int> result = arr;
    int currPass = 0;
    while (currPass < result.size()) {
        bool swapMade = false;
        for (int j = 0; j < result.size() - 1; j++) {
            if (result[j] > result[j + 1]) {
                std::swap(result[j], result[j + 1]);
                swapMade = true;
            }
        }
        if (!swapMade) {
            break;
        }
        currPass++;
    }
    return result;
}

std::vector<int> insertionSort(std::vector<int> arr) {
    std::vector<int> result = arr;
    for (int progress = 0; progress < result.size(); progress++) {
        int indxToPush = progress + 1;
        if (indxToPush >= result.size()) {
            break;
        }
        for (int i = indxToPush - 1; i >= 0; i--) {
            if (result[indxToPush] < result[i]) {
                std::swap(result[indxToPush], result[i]);
                indxToPush = i;
            } else {
                break;
            }
        }
    }
    return result;
}

int main() {
    std::vector<int> input = {1, -2, 4, 10, 3};
    for (auto elem : insertionSort(input)) {
        std::cout << elem << "\t";
    }
    std::cout << "\n";
    return 0;
}
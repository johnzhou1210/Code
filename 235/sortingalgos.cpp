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

void merge(std::vector<int> &orig, std::vector<int> arr1, std::vector<int> arr2) {
    int i = 0; int pt1 = 0; int pt2 = 0;
    while (pt1 < arr1.size() && pt2 < arr2.size()) {
        if (arr1[pt1] < arr2[pt2]) {
            orig[i] = arr1[pt1];
            pt1++;
        } else if (arr2[pt2] < arr1[pt1]) {
            orig[i] = arr2[pt2];
            pt2++;
        }
        i++;
    }
    while (pt1 < arr1.size()) {
        orig[i] = arr1[pt1];
        pt1++;
        i++;
    }
    while (pt2 < arr2.size()) {
        orig[i] = arr2[pt2];
        pt2++;
        i++;
    }
}

void mergeSort(std::vector<int> &arr) {
    if (arr.size() <= 1) {
        return;
    }
    int mid = (arr.size()) / 2;
    std::vector<int> left, right;
    for (int i = 0; i < mid; i++) {
        left.push_back(arr[i]);
    }
    for (int i = mid; i < arr.size(); i++) {
        right.push_back(arr[i]);
    }
    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right);
}

int main() {
    std::vector<int> input = {1, -2, 4, 10, 3};
    // for (auto elem : insertionSort(input)) {
    //     std::cout << elem << "\t";
    // }
    // std::vector<int> a = {-2,1};
    // std::vector<int> b = {3,5};
    // std::vector<int> dummy = {0,0,0,0,0,0,0,0};
    // merge(dummy,a,b);

    mergeSort(input);
    for (auto elem : input) {
        std::cout << elem << "\t";
    }
    std::cout << "\n";
    return 0;
}
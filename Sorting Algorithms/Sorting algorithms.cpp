#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream> // To handle file output
#include <cstring> // To use memcpy
using namespace std;

// Heapify function for max-heap
int heapify(int arr[], int size, int root, int& comparison_count) {
    int largest = root, left = 2 * root + 1, right = 2 * root + 2;

    // Compare root with left child
    comparison_count++;
    if (left < size && arr[left] > arr[largest]) largest = left;

    // Compare largest so far with right child
    comparison_count++;
    if (right < size && arr[right] > arr[largest]) largest = right;

    // Swap and recurse if root is not largest
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, size, largest, comparison_count);
    }
    return comparison_count;
}

// Heap Sort with comparison count
int heap_sort_count(int arr[], int size) {
    int comparison_count = 0;

    // Build heap
    for (int i = size / 2 - 1; i >= 0; i--)
        comparison_count = heapify(arr, size, i, comparison_count);

    // Extract elements from heap
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        comparison_count = heapify(arr, i, 0, comparison_count);
    }
    return comparison_count;
}

// Bubble Sort with comparison count
int bubble_sort_count(int arr[], int size) {
    int comparison_count = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++) {
            comparison_count++;
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    return comparison_count;
}

// Insertion Sort with comparison count
int insertion_sort_count(int arr[], int size) {
    int comparison_count = 0;
    for (int i = 1; i < size; i++) {
        int current = arr[i], j = i - 1;
        // swap elements to make room for current
        while (j >= 0 && arr[j] > current) {
            comparison_count++;
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = current;
    }
    return comparison_count;
}

// Selection Sort with comparison count
int selection_sort_count(int arr[], int size) {
    int comparison_count = 0;
    for (int i = 0; i < size - 1; i++) {
        int current_min = i;
        for (int j = i + 1; j < size; j++) {
            comparison_count++;
            if (arr[j] < arr[current_min]) current_min = j;
        }
        swap(arr[i], arr[current_min]);
    }
    return comparison_count;
}

// Generate random arrays
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) arr[i] = rand() % 100 + 1;
    return arr;
}

// Fill 2D array with random arrays
void generateRandomArrays(int randomArrays[30][30]) {
    for (int i = 0; i < 30; ++i) {
        vector<int> randomArray = generateRandomArray(i + 1);
        for (int j = 0; j < randomArray.size(); ++j)
            randomArrays[i][j] = randomArray[j];
    }
}

// Fill 2D array with sorted arrays
void generateSortedArrays(int sortedArrays[30][30]) {
    for (int i = 0; i < 30; ++i) {
        vector<int> sortedArray = generateRandomArray(i + 1);
        sort(sortedArray.begin(), sortedArray.end());
        for (int j = 0; j < sortedArray.size(); ++j)
            sortedArrays[i][j] = sortedArray[j];
    }
}

// Fill 2D array with inversely sorted arrays
void generateInverselySortedArrays(int inverselySortedArrays[30][30]) {
    for (int i = 0; i < 30; ++i) {
        vector<int> inverselySortedArray = generateRandomArray(i + 1);
        sort(inverselySortedArray.begin(), inverselySortedArray.end(), greater<int>());
        for (int j = 0; j < inverselySortedArray.size(); ++j)
            inverselySortedArrays[i][j] = inverselySortedArray[j];
    }
}

// Save comparison counts to CSV
void saveResultsToCSV() {
    int randomArrays[30][30], sortedArrays[30][30], inverselySortedArrays[30][30];

    generateRandomArrays(randomArrays);
    generateSortedArrays(sortedArrays);
    generateInverselySortedArrays(inverselySortedArrays);

    ofstream outputFile("sorting_comparisons.csv");
    outputFile << "Array Type,Array Size,Heap Sort Comparisons,Bubble Sort Comparisons,Insertion Sort Comparisons,Selection Sort Comparisons\n";

    // Write data for each array type
    for (int i = 0; i < 30; ++i) {
        int arr[30];

        // Random arrays
        memcpy(arr, randomArrays[i], sizeof(arr));
        outputFile << "Random," << i + 1 << ","
            << heap_sort_count(arr, i + 1) << ","
            << bubble_sort_count(arr, i + 1) << ","
            << insertion_sort_count(arr, i + 1) << ","
            << selection_sort_count(arr, i + 1) << "\n";

        // Sorted arrays
        memcpy(arr, sortedArrays[i], sizeof(arr));
        outputFile << "Sorted," << i + 1 << ","
            << heap_sort_count(arr, i + 1) << ","
            << bubble_sort_count(arr, i + 1) << ","
            << insertion_sort_count(arr, i + 1) << ","
            << selection_sort_count(arr, i + 1) << "\n";

        // Inversely sorted arrays
        memcpy(arr, inverselySortedArrays[i], sizeof(arr));
        outputFile << "Inversely Sorted," << i + 1 << ","
            << heap_sort_count(arr, i + 1) << ","
            << bubble_sort_count(arr, i + 1) << ","
            << insertion_sort_count(arr, i + 1) << ","
            << selection_sort_count(arr, i + 1) << "\n";
    }

    outputFile.close();
    cout << "Results saved to sorting_comparisons.csv\n";
}

int main() {
    srand(time(0)); // Seed for random numbers
    saveResultsToCSV(); // Save comparison results
    return 0;
}

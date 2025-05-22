#include <iostream>
using namespace std;


int alternate_disks(char arr[], int size) {
    int moves = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 'D') { // Find a 'D' disk
            int j = i;
            // swap 'D' right until no adjacent 'L' exists
            while (j < size - 1 && arr[j + 1] == 'L') {
                swap(arr[j], arr[j + 1]); // Swap with 'L'
                moves++
                j++;
            }
        }
    }

    return moves; 
}

int main() {
    char arr[] = { 'D', 'L', 'D', 'L', 'D', 'L' };
    int size = sizeof(arr) / sizeof(arr[0]); 

    int result = alternate_disks(arr, size);
    cout << "Number of moves: " << result << endl;

    return 0;
}



#include <iostream>
using namespace std;

int number_of_moves = 0;

void towerOfHanoi(int disks, char initial_rod, char middle_rod, char goal_rod) {
    if (disks == 1) { // Base case(only 1 disk remains on the first rod)
        cout << "Move disk 1 from rod " << initial_rod << " to rod " << goal_rod << endl;
        number_of_moves++; 
        return;
    }

    // Recursive call: move top (disks - 1) disks from initial_rod to middle_rod
    towerOfHanoi(disks - 1, initial_rod, goal_rod, middle_rod);

    cout << "Move disk " << disks << " from rod " << initial_rod << " to rod " << goal_rod << endl;
    number_of_moves++; 

    // Recursive call: move (disks - 1) disks from middle_rod to goal_rod
    towerOfHanoi(disks - 1, middle_rod, initial_rod, goal_rod);
}


int main() {
    int disks;
    cout << "Enter the number of disks: " << endl;
    cin >> disks;

    towerOfHanoi(disks, 'A', 'B', 'C');

    cout << "Total number of moves: " << number_of_moves << endl;

    return 0;
}

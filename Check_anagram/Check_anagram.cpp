#include <iostream>
#include <map>
#include <string>
using namespace std;

bool anagrams( string word1, string word2) {
    if (word1.length() != word2.length()) {
        return false;
    }
    // initialize maps to fill word
    map<char, int> word1_map, word2_map;

    // fill the maps
    for (char c : word1) {
        word1_map[c]++;
    }

    
    for (char c : word2) {
        word2_map[c]++;
    }

    // return true if they are equal
    return word1_map == word2_map; 

 
}

int main() {
    string word1, word2;

    cout << "Enter the first word: ";
    cin >> word1;

    cout << "Enter the second word: ";
    cin >> word2;

    if (anagrams(word1, word2)) {
        cout << "'" << word1 << "' and '" << word2 << "' are anagrams." << endl;
    }
    else {
        cout << "'" << word1 << "' and '" << word2 << "' are not anagrams." << endl;
    }

    return 0;
}

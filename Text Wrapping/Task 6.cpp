#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void text_wrapping(string text, int LW) {
    vector<string> words;
    stringstream ss(text); // intializes a variable of stringstream 
    string word;

    // string stream splits the whole text into seperate words using spaces as seperator 
    while (ss >> word) {
        words.push_back(word);
    }

    string current_line;
    int current_length = 0;

    // Process each word
    for (const string& word : words) {
        if (current_length + word.length() <= LW) { // Add word to current line if it fits
            if (!current_line.empty()) {
                current_line += " ";
                current_length += 1;
            }
            current_line += word;
            current_length += word.length();
        }
        else { // Print current line and start a new one
            cout << current_line << endl;
            current_line = word;
            current_length = word.length();
        }
    }

    // Print the last line
    if (!current_line.empty()) {
        cout << current_line << endl;
    }
}



int main()
{
	int line_width;
	string text;

	cout << "Enter Line Width: " << endl;

	cin >> line_width;

	cout << "Enter the text: " << endl;

	getline(cin, text);

	text_wrapping(text, line_width);

}
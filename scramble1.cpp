#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

void rule() {
    cout << "    GAME RULES\n------------------\n";
cout << "-> You will be given the length and a scrambled version of a word.\n";
cout << "-> A hint will be provided to help you guess the word.\n";
cout << "-> You have 3 chances to guess the correct word.\n";
cout << "-> There are a total of 100 words to guess from.\n";
cout << "-> Each correct answer earns you 1 point.\n";
cout << "-> Your final score will be displayed at the end of the game.\n";
cout << "_______________________________________________________________________________________________________________________\n";
cout << "\n                         GAME STARTS NOW! Have Fun and Good Luck!\n";
cout << "_______________________________________________________________________________________________________________________\n" << endl;
}

vector<pair<string, string>> satoru() {
    // vector<element type to be stored<datatype for each if pair>> name;
    // in simple to declare use vector<datatype>name;
    vector<pair<string, string>> gojo;
    string line;

    // Here we gonna fetch the file named "whatever.txt". Stored at same location
    ifstream file("scramble.txt");
    if (!file.is_open()) {
        cout << "No text file found" << endl;
        return gojo;
    }

    // getline(location,storage)
    // ss stands for string slicing , ss(of what string)
    // using getline(location,storage,delete or till where)
    // we have created two pair
    // using make_pair function we are making and storing pair as an single element in vector(pair1,pair2)
    // pushback function to add new element, push_back(add new element);
    while (getline(file, line)) {
        stringstream ss(line);
        string word, hint;
        getline(ss, word, '|');
        getline(ss, hint);
        gojo.push_back(make_pair(word, hint));
    }
    file.close();
    return gojo;
}

int main() {
    int total = 0;
    rule();

    vector<pair<string, string>> gojo;
    gojo = satoru();
    int count = gojo.size();

    char temp;
    while (count) {
        // using srand = seed random so that it will choose different seq. of random number. set  time at 0 
        srand(time(0));
        int index = rand() % count;

        // using first & second function to divide and store the pair in different string.
        string words = gojo[index].first;
        string hints = gojo[index].second;
        string new1 = words, h;
        int g = words.length();

        cout << "Length of the word: " << words.length() << endl;
        while (g) {
            int num = rand() % g;
            int num1 = rand() % g;
            if (num1 != num) {
                temp = words[num];
                words[num] = words[num1];
                words[num1] = temp;
            }
            g--;
        }

        cout << "Your jumbled word is: " << words << "\nHint: " << hints << "\nEnter your correct word: " << endl;
        int i = 3;  // Max attempts to guess
        while (i) {
            i--;
            cin >> h;

            if (h == new1) {
                cout << "\nCongrats!!! (^///^)\n";
                cout << "_______________________________________________________________________________________________________________________" << endl;
                total++;
                break;
            } else if (i != 0) {
                cout << "Incorrect :( Try again_ " << endl;
            }
        }

        if (i == 0) {
            cout << "\nCorrect word is: " << new1 << endl;
            cout << "\n_______________________________________________________________________________________________________________________" << endl;
        }

        count--;  // Decrease word count

        cout << "\n -> Enter 1 for next question\n -> Enter anything to end the game\n" << endl;
        string input;
        cin >> input;

        if (input != "1") {
            cout << "YOUR SCORE IS: " << total << endl;
            cout << "_______________________________________________________________________________________________________________________" << endl;
            cout << "\n                                     Arigato for playing\n";
            cout << "_______________________________________________________________________________________________________________________" << endl;
            break;
        } else {
            cout << "_______________________________________________________________________________________________________________________" << endl;
        }
    }

    if (count == 0) {
        cout << "YOUR SCORE IS: " << total << endl;
        cout << "_______________________________________________________________________________________________________________________" << endl;
        cout << "\n                               You have reached the end of the game. Congratulations.\n";
        cout << "_______________________________________________________________________________________________________________________" << endl;
    }

    return 0;
}

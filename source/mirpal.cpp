
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

/*

 Character  Reverse Character   Reverse Character   Reverse
 {'A','A'},       {'M','M'},       {'Y','Y'},
 {'B','?'},       {'N','?'},       {'Z','5'},
 {'C','?'},       {'O','O'},       {'1','1'},
 {'D','?'},       {'P','?'},       {'2','S'},
 {'E','3'},       {'Q','?'},       {'3','E'},
 {'F','?'},       {'R','?'},       {'4','?'},
 {'G','?'},       {'S','2'},       {'5','Z'},
 {'H','H'},       {'T','T'},       {'6','?'},
 {'I','I'},       {'U','U'},       {'7','?'},
 {'J','L'},       {'V','V'},       {'8','8'},
 {'K','?'},       {'W','W'},       {'9','?'},
 {'L','J'},       {'X','X'},
 */

string s1 = " -- is not a palindrome.";
string s2 = " -- is a regular palindrome.";
string s3 = " -- is a mirrored string.";
string s4 = " -- is a mirrored palindrome.";
string strings[] = {s1,s2,s3,s4};
unordered_map<char,char>* letterMap = new unordered_map<char,char>();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    bool isPalindrome = true;
    bool isMirrored = true;

    string word;
    getline(std::cin,word);

    // initialize map
    letterMap->insert({ {'A','A'},       {'M','M'},       {'Y','Y'},
                        {'B','?'},       {'N','?'},       {'Z','5'},
                        {'C','?'},       {'O','O'},       {'1','1'},
                        {'D','?'},       {'P','?'},       {'2','S'},
                        {'E','3'},       {'Q','?'},       {'3','E'},
                        {'F','?'},       {'R','?'},       {'4','?'},
                        {'G','?'},       {'S','2'},       {'5','Z'},
                        {'H','H'},       {'T','T'},       {'6','?'},
                        {'I','I'},       {'U','U'},       {'7','?'},
                        {'J','L'},       {'V','V'},       {'8','8'},
                        {'K','?'},       {'W','W'},       {'9','?'},
                        {'L','J'},       {'X','X'}});
    // check if palindrome
    // check if mirrored string

    rep(i, (int) (word.length()/2)) {
        char letter1 = word[i];
        char letter2 = word[word.length() - i - 1];
        if (letter1 != letter2) {
            isPalindrome = false;
        }

        if(letter1 != letterMap->at(letter2) && letter2 != letterMap->at(letter1)) {
            isMirrored = false;
        }
    }
    // check middle char
    if(word.length()%2 == 1){
        char middleChar = word[word.length()/2];
        if(middleChar != letterMap->at(middleChar)){
            isMirrored = false;
        }
    }
    word += strings[(isMirrored)*2 + isPalindrome];
    cout << word;

    return 0;
}


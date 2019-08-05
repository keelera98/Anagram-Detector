/*
*   MIT License
*
*   Copyright (c) 2019 Austin Keeler
*    
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*   of this software and associated documentation files (the "Software"), to deal
*   in the Software without restriction, including without limitation the rights
*   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*   copies of the Software, and to permit persons to whom the Software is
*   furnished to do so, subject to the following conditions:
*    
*   The above copyright notice and this permission notice shall be included in all
*   copies or substantial portions of the Software.
*    
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*   SOFTWARE.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

bool anagramDetect(string normal, string anagram);

int main(){
    cout << "***********************************************" << endl;
    cout << "*       Welcome to the anagram detector!      *" << endl;
    cout << "***********************************************" << endl;
    
    string anagramWord = "";
    cout << "Enter the anagram:";
    getline(cin, anagramWord); //have to use getline() instead of just cin in order to correctly remove whitespace
    
    string normalWord = "";
    cout << "Enter the word to test:";
    getline(cin, normalWord);
    
    bool anagramAnswer = false;
    anagramAnswer = anagramDetect(normalWord, anagramWord);
    
    if(anagramAnswer == true){
        cout << "The anagram " << anagramWord << " represents the word " << normalWord << endl;
    }else{
        cout << "The anagram " << anagramWord << " does not represent the word " << normalWord << endl;
    }
    
    return 0;
}

bool anagramDetect (string normal, string anagram){
    bool isAnagram = false;
    
    string sortedAnagram = anagram;
    string sortedWord = normal;
    sortedAnagram.erase(remove_if(sortedAnagram.begin(), sortedAnagram.end(), ::isspace), sortedAnagram.end()); //removes whitespace from entered word
    sortedWord.erase(remove_if(sortedWord.begin(), sortedWord.end(), ::isspace), sortedWord.end());
    sort(sortedAnagram.begin(), sortedAnagram.end());
    sort(sortedWord.begin(), sortedWord.end());
    
    for(int i = 0; i < normal.length(); i++){
        if(sortedWord[i] == sortedAnagram[i]){
            isAnagram = true;
        }else{
            isAnagram = false;
        }
    }
    
    return isAnagram;
}

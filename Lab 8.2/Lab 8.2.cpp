#include <iostream>
#include <string>

using namespace std;

// Функція для пошуку останнього слова в рядку
string FindLastWord(const string s) {
    size_t lastChar = s.find_last_not_of(" ");
    if (lastChar == string::npos) return "";

    size_t firstCharOfLastWord = s.find_last_of(" ", lastChar);

    if (firstCharOfLastWord == string::npos) {
        return s.substr(0, lastChar + 1);
    }
    else {
        return s.substr(firstCharOfLastWord + 1, lastChar - firstCharOfLastWord);
    }
}

// Функція для підрахунку кількості букв 'a' (англійських)
size_t CountA(const string word) {
    size_t count = 0;
    for (char c : word) {
        // Перевіряємо на малу 'a' та велику 'A'
        if (c == 'a' || c == 'A') {
            count++;
        }
    }
    return count;
}

// Цей блок ігнорується під час запуску юніт-тестів, 
// щоб не було помилки про дві функції main.
#ifndef UNIT_TESTING
int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    string lastWord = FindLastWord(str);

    if (lastWord.empty()) {
        cout << "No words found." << endl;
    }
    else {
        size_t result = CountA(lastWord);
        cout << "Last word: \"" << lastWord << "\"" << endl;
        cout << "Count of 'a' in it: " << result << endl;
    }

    return 0;
}
#endif
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

void addChars(char* chars, char additionals) {
    int c;

    for (c = 'a'; c <= 'z'; c++) {
        chars[c - 'a'] = c;
    }

    for (c = 'A'; c <= 'Z'; c++) {
        chars[26 + c - 'A'] = c;
    }

    switch (additionals) {
    case '1':
        for (c = '!'; c <= '?'; c++) {
            chars[52 + c - '!'] = c;
        }
        break;

    case '2':
        for (c = '0'; c <= '9'; c++) {
            chars[59 + c - '0'] = c;
        }
        break;

    case '3':
        for (c = '!'; c <= '?'; c++) {
            chars[52 + c - '!'] = c;
        }
        for (c = '0'; c <= '9'; c++) {
            chars[59 + c - '0'] = c;
        }
        break;

    default:
        std::cout << "\nYour choice didn't meet any of the given choices so I didn't add any special/numeric characters\n";
        break;
    }
}

std::string generatePassword(int length, char* chars) {
    std::string password = "";
    int j;

    for (j = 0; j < length; j++) {
        int randomIndex = rand() % 62;
        password += chars[randomIndex];
    }

    return password;
}

int main() {
    char* chars = new char[63];
    srand(time(NULL));

    char other;
    std::cout << "\nWhich other symbols would you like to include? (1=special, 2=numbers, 3=special + numbers)\n";
    std::cin >> other;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    addChars(chars, other);

    int len;
    std::cout << "\nHow long would you like your password to be? (1-30)\n";
    std::cin >> len;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (len >= 1 && len <= 30) {
        std::string password = generatePassword(len, chars);
        std::cout << "\n\nHere's your new password: " << password << std::endl;
    }

    delete[] chars;

    return 0;
}

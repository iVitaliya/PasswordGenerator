#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addChars(char* chars, char additionals) {
    int c;

    for (c = 'a'; c <= 'z'; c++) {
        chars[c - 'a'] = c;
    }

    for (c = 'A'; c <= 'Z'; c++) {
        chars[26 + c - 'A'] = c;
    }

    switch (additionals)
    {
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
            printf("\nYour choice didn't meet any of the given choices so I didn't add any special/numeric characters\n");
            break;
    }
}

char* generatePassword(int length, char* chars) {
    char* password = malloc((length + 1) * sizeof(char));
    int j;

    for (j = 0; j < length; j++) {
        int randomIndex = rand() % 62;
        password[j] = chars[randomIndex];
    }

    password[length] = '\0';

    return password;
}

int main() {
    char chars[62];
    srand(time(NULL));

    char other;
    printf("\nWhich other symbols would you like to include? (1=special, 2=numbers, 3=special + numbers)\n");
    scanf("%c", &other);
    getchar();

    addChars(chars, other);

    int len;
    printf("\nHow long would you like your password to be? (1-30)\n");
    scanf("%d", &len);
    getchar();

    if (len >= 1 && len <= 30) {
        char* password = generatePassword(len, chars);
        printf("\n\nHere's your new password: %s\n", password);
        free(password);
    }

    main();
    return 0;
}
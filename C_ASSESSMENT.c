#include <stdio.h>

void menu() {
    printf("\nString Operations Menu:\n");
    printf("1. Reverse a string\n");
    printf("2. Concatenate two strings\n");
    printf("3. Check if a string is a palindrome\n");
    printf("4. Copy a string\n");
    printf("5. Find the length of a string\n");
    printf("6. Find the frequency of a character in a string\n");
    printf("7. Find the number of vowels and consonants\n");
    printf("8. Find the number of blank spaces and digits\n");
    printf("9. Exit\n");
}

// length of a string
int string_length(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}
// reverse string
void reverse_string(char *s) {
    int len = string_length(s),i;

    for (i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", s);
}

// Concatenate two strings
void concatenate_strings(char *s1, char *s2) {
    int len1 = string_length(s1);
    int len2 = string_length(s2);
    int i;
    for (i = 0; i <= len2; i++) {
        s1[len1 + i] = s2[i];
    }
    printf("Concatenated string: %s\n", s1);
}

// for checking string is palindrom or not
int is_palindrome(char *s) {
    int len = string_length(s),i;
    for (i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Copy a string
void copy_string(char *s, char *copy) {
    int i = 0;
    while (s[i] != '\0') {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    printf("Copied string: %s\n", copy);
}

// frequency of a character in a string
void char_frequency(char *s, char ch) {
    int count = 0,i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ch) {
            count++;
        }
    }
    printf("Frequency of '%c' in the string: %d\n", ch, count);
}

// number of vowels and consonants
void count_vowels_consonants(char *s) {
    int vowels = 0, consonants = 0,i;
    for (i = 0; s[i] != '\0'; i++) {
        char ch = tolower(s[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
}

// number of blank spaces and digits
void count_spaces_digits(char *s) {
    int spaces = 0, digits = 0,i;
    for (i = 0; s[i] != '\0'; i++) {
        if (isspace(s[i])) {
            spaces++;
        } else if (isdigit(s[i])) {
            digits++;
        }
    }
    printf("Number of blank spaces: %d\n", spaces);
    printf("Number of digits: %d\n", digits);
}

int main() {
    char str1[100], str2[100], copy[100], ch;
    int choice;
    do {
        menu();
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter the string to reverse: ");
                gets(str1);
                reverse_string(str1);
                break;
            case 2:
                printf("Enter the first string: ");
                gets(str1);
                printf("Enter the second string: ");
                gets(str2);
                concatenate_strings(str1, str2);
                break;
            case 3:
                printf("Enter the string to check for palindrome: ");
                gets(str1);
                if (is_palindrome(str1)) {
                    printf("'%s' is a palindrome.\n", str1);
                } else {
                    printf("'%s' is not a palindrome.\n", str1);
                }
                break;
            case 4:
                printf("Enter the string to copy: ");
                gets(str1);
                copy_string(str1, copy);
                break;
            case 5:
                printf("Enter the string to find its length: ");
                gets(str1);
                printf("Length of the string: %d\n", string_length(str1));
                break;
            case 6:
                printf("Enter the string: ");
                gets(str1);
                printf("Enter the character to find its frequency: ");
                scanf("%c", &ch);
                getchar();  // Consume newline character left in the buffer
                char_frequency(str1, ch);
                break;
            case 7:
                printf("Enter the string: ");
                gets(str1);
                count_vowels_consonants(str1);
                break;
            case 8:
                printf("Enter the string: ");
                gets(str1);
                count_spaces_digits(str1);
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }

        if (choice != 9) {
            printf("Do you want to continue? (y/n): ");
            char cont = getchar();
            getchar();  // Consume newline character left in the buffer
            if (cont == 'n' || cont == 'N') {
                break;
            }
        }

    } while (choice != 9);

    return 0;
}


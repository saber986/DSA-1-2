#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int freq[26] = {0};

    printf("Enter a word or string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }

    printf("\nLetter Frequency:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c : %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[100], sub[50];
    int i, j, found = 0;

    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the substring: ");
    fgets(sub, sizeof(sub), stdin);

    int len1 = strlen(str);
    int len2 = strlen(sub);

    if (str[len1 - 1] == '\n') str[len1 - 1] = '\0';
    if (sub[len2 - 1] == '\n') sub[len2 - 1] = '\0';

    len1 = strlen(str);
    len2 = strlen(sub);

    for (i = 0; i <= len1 - len2; i++) {
        for (j = 0; j < len2; j++) {
            if (str[i + j] != sub[j])
                break;
        }
        if (j == len2) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Substring found at index %d\n", i);
    else
        printf("Substring not found\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int capacity;
    int length;
} String;

// Create a new dynamic string from a normal C string
void createString(String *s, char text[]) {
    int len = 0;
    while (text[len] != '\0') {
        len++;
    }

    s->capacity = len * 2 + 1;
    s->length = 0;
    s->data = (char*)malloc(s->capacity * sizeof(char));

    for (int i = 0; i < len; i++) {
        s->data[s->length++] = text[i];
    }
}

// Add a character at the end
void pushBack(String *s, char c) {
    if (s->length == s->capacity) {
        s->capacity *= 2;
        s->data = (char*)realloc(s->data, s->capacity * sizeof(char));
    }
    s->data[s->length++] = c;
}

// Remove last character
void popBack(String *s) {
    if (s->length > 0) {
        s->length--;
    }
}

// Get current length
int getLength(String *s) {
    return s->length;
}

// Get character at a specific index
char getChar(String *s, int index) {
    if (index >= 0 && index < s->length) {
        return s->data[index];
    }
    return '\0';
}

// Clear the string (without freeing memory)
void clearString(String *s) {
    s->length = 0;
}

// Concatenate another string
void concatenate(String *s1, String *s2) {
    for (int i = 0; i < s2->length; i++) {
        pushBack(s1, s2->data[i]);
    }
}

// Insert a character at a specific position
void insertAt(String *s, char c, int index) {
    if (index < 0 || index > s->length) return;

    pushBack(s, c);  // temporary increase size

    for (int i = s->length - 2; i >= index; i--) {
        s->data[i + 1] = s->data[i];
    }
    s->data[index] = c;
}

// Delete character at a specific position
void deleteAt(String *s, int index) {
    if (index < 0 || index >= s->length) return;

    for (int i = index; i < s->length - 1; i++) {
        s->data[i] = s->data[i + 1];
    }
    s->length--;
}

// Replace character at a specific position
void replaceAt(String *s, char c, int index) {
    if (index >= 0 && index < s->length) {
        s->data[index] = c;
    }
}

// Find substring (returns starting index or -1)
int findSubstring(String *s, String *pattern) {
    if (pattern->length > s->length || pattern->length == 0) {
        return -1;
    }

    for (int i = 0; i <= s->length - pattern->length; i++) {
        int j;
        for (j = 0; j < pattern->length; j++) {
            if (s->data[i + j] != pattern->data[j]) {
                break;
            }
        }
        if (j == pattern->length) {
            return i;
        }
    }
    return -1;
}

// Display the string
void display(String *s) {
    for (int i = 0; i < s->length; i++) {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

// Free memory
void freeString(String *s) {
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->length = 0;
}

int main() {
    String s1, s2;

    createString(&s1, "Saber");
    createString(&s2, "Kabir");

    printf("String 1: ");
    display(&s1);

    printf("String 2: ");
    display(&s2);

    concatenate(&s1, &s2);
    printf("After concatenation: ");
    display(&s1);

    insertAt(&s1, ' ', 5);
    printf("After inserting space: ");
    display(&s1);

    deleteAt(&s1, 5);
    printf("After deleting space: ");
    display(&s1);

    printf("Substring found at index: %d\n", findSubstring(&s1, &s2));

    freeString(&s1);
    freeString(&s2);

    return 0;
}

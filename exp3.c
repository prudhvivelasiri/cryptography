#include <stdio.h>
#include <string.h>

#define SIZE 5

void generateKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int used[26] = {0}; // Array to mark used letters
    int k = 0;

    // Fill the matrix with the keyword
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] == 'j') key[i] = 'i'; // Replace 'j' with 'i'
        if (!used[key[i] - 'a']) {
            keyMatrix[k / SIZE][k % SIZE] = key[i];
            used[key[i] - 'a'] = 1;
            k++;
        }
    }

    // Fill remaining letters
    for (int i = 0; i < 26; i++) {
        if (i + 'a' == 'j') continue; // Skip 'j'
        if (!used[i]) {
            keyMatrix[k / SIZE][k % SIZE] = i + 'a';
            k++;
        }
    }
}

void encrypt(char message[], char keyMatrix[SIZE][SIZE]) {
    for (int i = 0; i < strlen(message); i += 2) {
        char first = message[i];
        char second = (i + 1 < strlen(message)) ? message[i + 1] : 'x'; // Add 'x' if odd

        int row1, col1, row2, col2;
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (keyMatrix[r][c] == first) {
                    row1 = r; col1 = c;
                }
                if (keyMatrix[r][c] == second) {
                    row2 = r; col2 = c;
                }
            }
        }

        // Same row
        if (row1 == row2) {
            first = keyMatrix[row1][(col1 + 1) % SIZE];
            second = keyMatrix[row2][(col2 + 1) % SIZE];
        }
        // Same column
        else if (col1 == col2) {
            first = keyMatrix[(row1 + 1) % SIZE][col1];
            second = keyMatrix[(row2 + 1) % SIZE][col2];
        }
        // Rectangle swap
        else {
            first = keyMatrix[row1][col2];
            second = keyMatrix[row2][col1];
        }

        message[i] = first;
        message[i + 1] = second;
    }
}

int main() {
    char key[100], message[100];
    char keyMatrix[SIZE][SIZE];

    printf("Enter a keyword: ");
    gets(key);
    
    printf("Enter the plaintext (lowercase): ");
    gets(message);

    generateKeyMatrix(key, keyMatrix);
    encrypt(message, keyMatrix);

    printf("Encrypted message: %s\n", message);

    return 0;
}

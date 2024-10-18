#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

int main() {
    char plaintext[100], keyword[100], ciphertext[100];
    int shift;

    printf("Enter the plaintext (lowercase): ");
    gets(plaintext);
    
    printf("Enter the keyword (lowercase): ");
    gets(keyword);

    int keywordLength = strlen(keyword);
    int j = 0; // Keyword index
    int k = 0; // Ciphertext index

    // Encrypting the plaintext
    while (plaintext[k] != '\0') {
        if (plaintext[k] == ' ') {
            ciphertext[k] = ' '; // Preserve spaces
        } else {
            // Calculate the shift
            shift = keyword[j % keywordLength] - 'a'; // Get shift from keyword letter
            ciphertext[k] = ((plaintext[k] - 'a' + shift) % ALPHABET_SIZE) + 'a'; // Encrypt the letter
            j++; // Move to next letter in keyword
        }
        k++; // Move to next character in plaintext
    }

    ciphertext[k] = '\0'; // Null-terminate the ciphertext string

    // Output the ciphertext
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}

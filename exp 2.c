#include <stdio.h>

int main() {
    char message[100];
    char plaintext_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char ciphertext_alphabet[] = "qwertyuiopasdfghjklzxcvbnm"; 
    int i, j;

    printf("Enter a message (lowercase): ");
    gets(message);

    for(i = 0; message[i] != '\0'; i++) {
        for(j = 0; j < 26; j++) {
            if(message[i] == plaintext_alphabet[j]) {
                message[i] = ciphertext_alphabet[j];
                break;
            }
        }
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}

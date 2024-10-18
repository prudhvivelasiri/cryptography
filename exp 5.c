#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[100], ciphertext[100], decrypted[100];
    int a, b, a_inverse;
    int flag = 0; 

    printf("Enter value of a (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    // Input plaintext message (in lowercase)
    printf("Enter the plaintext (lowercase): ");
    scanf("%s", plaintext);

    int length = strlen(plaintext);

    for (int i = 0; i < length; i++) {
        ciphertext[i] = ((a * (plaintext[i] - 'a') + b) % 26) + 'a';
    }
    ciphertext[length] = '\0'; 

    printf("Encrypted message: %s\n", ciphertext);

    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1) {
            a_inverse = x;
            flag = 1;  // Inverse found
            break;
        }
    }

    if (flag == 0) {
        printf("Decryption is not possible since inverse of a does not exist.\n");
    } else {
        // Decryption
        for (int i = 0; i < length; i++) {
            decrypted[i] = ((a_inverse * ((ciphertext[i] - 'a' - b + 26)) % 26) + 'a');
        }
        decrypted[length] = '\0'; 

        printf("Decrypted message: %s\n", decrypted);
    }

    return 0;
}

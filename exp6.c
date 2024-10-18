#include <stdio.h>

int main() {
    int a, b, a_inverse, found = 0;
    int E = 4, T = 19, B = 1, U = 20;  
    char ciphertext[100], plaintext[100];

    
    for (a = 1; a < 26; a++) {
        if ((19 * a - 4 * a) % 26 == (20 - 1 + 26) % 26) {
            b = (B - a * E + 26) % 26;  
            found = 1;
            printf("Found a = %d and b = %d\n", a, b);
            break;
        }
    }

    if (found) {
        printf("Enter the ciphertext (uppercase): ");
        scanf("%s", ciphertext);

        a_inverse = -1;  
        for (int x = 1; x < 26; x++) {
            if ((a * x) % 26 == 1) {
                a_inverse = x;
                break;
            }
        }

        if (a_inverse != -1) {
            for (int i = 0; ciphertext[i] != '\0'; i++) {
                if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
                    plaintext[i] = ((a_inverse * (ciphertext[i] - 'A' - b + 26)) % 26) + 'A';
                } else {
                    plaintext[i] = ciphertext[i]; 
                }
            }

            plaintext[strlen(ciphertext)] = '\0'; 
            printf("Decrypted message: %s\n", plaintext);
        } else {
            printf("Modular inverse of a does not exist. Decryption failed.\n");
        }
    } else {
        printf("Could not find suitable values of a and b.\n");
    }

    return 0;
}

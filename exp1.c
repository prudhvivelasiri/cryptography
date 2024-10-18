#include <stdio.h>

int main() {
    char message[100];
    int i, k;

    printf("Enter a message (lowercase): ");
    gets(message);

    printf("Enter shift value: ");
    scanf("%d", &k);

    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + k) % 26 + 'a';
        }
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}

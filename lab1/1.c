//Write a program to demonstrate encryption and decryption of your full name using Caesar Cipher 

#include <stdio.h>
#include <ctype.h>

void caesar_encrypt(char *text, int key) {
	int i;
    for ( i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char shift = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - shift + key) % 26 + shift;
        }
    }
}

void caesar_decrypt(char *text, int key) {
    caesar_encrypt(text, -key);
}

int main() {
    char full_name[100];
    int key;

    printf("Enter your full name: ");
    fgets(full_name, sizeof(full_name), stdin);

    printf("Enter the encryption key (an integer): ");
    scanf("%d", &key);

    caesar_encrypt(full_name, key);
    printf("Encrypted Name: %s", full_name);

    caesar_decrypt(full_name, key);
    printf("Decrypted Name: %s", full_name);

    return 0;
}

//Write a program to demonstrate encryption and decryption of your full name using Vigenere Cipher.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(char *text, char *keyword) {
    int text_len = strlen(text);
    int keyword_len = strlen(keyword);
     int i;

    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            int key_index = i % keyword_len;
            int shift = toupper(keyword[key_index]) - 'A';
            if (isupper(text[i])) {
                text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            } else {
                text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
            }
        }
    }
}

void vigenere_decrypt(char *text, char *keyword) {
    int text_len = strlen(text);
    int keyword_len = strlen(keyword);
     int i;

    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            int key_index = i % keyword_len;
            int shift = toupper(keyword[key_index]) - 'A';
            if (isupper(text[i])) {
                text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
            } else {
                text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
            }
        }
    }
}

int main() {
    char full_name[100];
    char keyword[20];

    printf("Enter your full name: ");
    fgets(full_name, sizeof(full_name), stdin);
    full_name[strcspn(full_name, "\n")] = '\0';

    printf("Enter the encryption/decryption keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; 

    vigenere_encrypt(full_name, keyword);
    printf("Encrypted Name: %s\n", full_name);

    vigenere_decrypt(full_name, keyword);
    printf("Decrypted Name: %s\n", full_name);

    return 0;
}


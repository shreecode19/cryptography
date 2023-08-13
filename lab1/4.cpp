//Write a program to demonstrate encryption and decryption of your full name using Playfair cipher.


#include <iostream>
#include <string>
#include <cctype>

void prepare_key(std::string &key) {
    std::string temp = "";
    int len = key.length();

    for (int i = 0; i < len; i++) {
        char c = std::toupper(key[i]);
        if (std::isalpha(c)) {
            if (c == 'J') {
                c = 'I';
            }
            if (temp.find(c) == std::string::npos) {
                temp += c;
            }
        }
    }

    // Filling the remaining characters
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J' && temp.find(c) == std::string::npos) {
            temp += c;
        }
    }

    key = temp;
}

void generate_playfair_square(const std::string &key, char square[5][5]) {
    int index = 0;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            square[row][col] = key[index++];
        }
    }
}

void find_position(const char square[5][5], char letter, int &row, int &col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (square[i][j] == letter) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

void playfair_encrypt(const char square[5][5], const std::string &text, std::string &cipher) {
    int row1, col1, row2, col2;
    int len = text.length();

    for (int i = 0; i < len; i += 2) {
        find_position(square, std::toupper(text[i]), row1, col1);
        find_position(square, std::toupper(text[i + 1]), row2, col2);

        if (row1 == row2) {
            cipher += square[row1][(col1 + 1) % 5];
            cipher += square[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            cipher += square[(row1 + 1) % 5][col1];
            cipher += square[(row2 + 1) % 5][col2];
        } else {
            cipher += square[row1][col2];
            cipher += square[row2][col1];
        }
    }
}

void playfair_decrypt(const char square[5][5], const std::string &cipher, std::string &text) {
    int row1, col1, row2, col2;
    int len = cipher.length();

    for (int i = 0; i < len; i += 2) {
        find_position(square, std::toupper(cipher[i]), row1, col1);
        find_position(square, std::toupper(cipher[i + 1]), row2, col2);

        if (row1 == row2) {
            text += square[row1][(col1 + 4) % 5];
            text += square[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            text += square[(row1 + 4) % 5][col1];
            text += square[(row2 + 4) % 5][col2];
        } else {
            text += square[row1][col2];
            text += square[row2][col1];
        }
    }
}

int main() {
    std::string full_name;
    std::string key;
    char square[5][5];
    std::string encrypted_name;
    std::string decrypted_name;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, full_name);

    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    prepare_key(key);
    generate_playfair_square(key, square);

    playfair_encrypt(square, full_name, encrypted_name);
    std::cout << "Encrypted Name: " << encrypted_name << std::endl;

    playfair_decrypt(square, encrypted_name, decrypted_name);
    std::cout << "Decrypted Name: " << decrypted_name << std::endl;

    return 0;
}


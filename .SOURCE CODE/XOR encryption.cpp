#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void encryptDecryptFile(const string &filename, const string &key) {
    fstream file(filename.c_str(), ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not open file!" << endl;
        return;
    }
    char ch;
    size_t keyLength = key.length();
    size_t i = 0;

    while (file.get(ch)) {
        // XOR encryption/decryption
        ch ^= key[i % keyLength];
        file.seekp(-1, ios::cur); 
        file.put(ch);           
        i++;
    }
    file.close();
    cout << "Operation completed successfully!" << endl;
}
int main() {
    string filename, key, choice;
    cout << "Welcome to File Encryption and Decryption Tool\n";
    cout << "Enter file name: ";
    cin >> filename;
    cout << "Enter a secret key: ";
    cin >> key;
    cout << "Choose an option:\n1. Encrypt File\n2. Decrypt File\n";
    cin >> choice;
    if (choice == "1") {
        encryptDecryptFile(filename, key);
        cout << "File encrypted successfully.\n";
    } else if (choice == "2") {
        encryptDecryptFile(filename, key);
        cout << "File decrypted successfully.\n";
    } else {
        cout << "Invalid choice. Exiting...\n";
    }
    return 0;
}


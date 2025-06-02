#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSpecial) {
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special = "!@#$%^&*()-_=+[{]}|;:',<.>/?`~";
    
    string allChars = "";
    if (useUpper) allChars += upper;
    if (useLower) allChars += lower;
    if (useDigits) allChars += digits;
    if (useSpecial) allChars += special;

    if (allChars.empty()) {
        return "Error: No character sets selected!";
    }

    string password = "";
    for (int i = 0; i < length; ++i) {
        int randIndex = rand() % allChars.size();
        password += allChars[randIndex];
    }

    return password;
}

int main() {
    srand(time(0)); // Seed random generator

    int length;
    char upperChoice, lowerChoice, digitsChoice, specialChoice;

    cout << "==== PASSWORD GENERATOR ====\n";
    cout << "Enter password length: ";
    cin >> length;

    cout << "Include uppercase letters? (y/n): ";
    cin >> upperChoice;

    cout << "Include lowercase letters? (y/n): ";
    cin >> lowerChoice;

    cout << "Include digits? (y/n): ";
    cin >> digitsChoice;

    cout << "Include special characters? (y/n): ";
    cin >> specialChoice;

    bool useUpper = (upperChoice == 'y' || upperChoice == 'Y');
    bool useLower = (lowerChoice == 'y' || lowerChoice == 'Y');
    bool useDigits = (digitsChoice == 'y' || digitsChoice == 'Y');
    bool useSpecial = (specialChoice == 'y' || specialChoice == 'Y');

    string password = generatePassword(length, useUpper, useLower, useDigits, useSpecial);

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}

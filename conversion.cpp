#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ---------- Binary to Decimal ----------
int binaryToDecimal(const string& bin) {
    int dec = 0;
    int power = 0;

    for (int i = bin.length() - 1; i >= 0; i--) {
        dec += (bin[i] - '0') * pow(2, power++);
    }
    return dec;
}

// ---------- Octal to Decimal ----------
int octalToDecimal(const string& oct) {
    int dec = 0;
    int power = 0;

    for (int i = oct.length() - 1; i >= 0; i--) {
        dec += (oct[i] - '0') * pow(8, power++);
    }
    return dec;
}

// ---------- Hexadecimal to Decimal ----------
int hexToDecimal(const string& hex) {
    int dec = 0;
    int base = 1;

    for (int i = hex.length() - 1; i >= 0; i--) {
        char c = hex[i];

        if (c >= '0' && c <= '9')
            dec += (c - '0') * base;
        else if (c >= 'A' && c <= 'F')
            dec += (c - 'A' + 10) * base;
        else if (c >= 'a' && c <= 'f')
            dec += (c - 'a' + 10) * base;

        base *= 16;
    }
    return dec;
}

// ---------- Decimal to Binary ----------
string decimalToBinary(int dec) {
    if (dec == 0) return "0";
    string bin = "";
    while (dec > 0) {
        bin = char('0' + dec % 2) + bin;
        dec /= 2;
    }
    return bin;
}

// ---------- Decimal to Octal ----------
string decimalToOctal(int dec) {
    if (dec == 0) return "0";
    string oct = "";
    while (dec > 0) {
        oct = char('0' + dec % 8) + oct;
        dec /= 8;
    }
    return oct;
}

// ---------- Decimal to Hex ----------
string decimalToHex(int dec) {
    if (dec == 0) return "0";
    string hex = "";
    char map[] = "0123456789ABCDEF";

    while (dec > 0) {
        hex = map[dec % 16] + hex;
        dec /= 16;
    }
    return hex;
}

// ---------- MAIN ----------
int main() {
    int source, target;
    string input;
    int decimalValue = 0;

    cout << "===== Base Conversion Menu =====\n";
    cout << "1. Binary\n";
    cout << "2. Decimal\n";
    cout << "3. Octal\n";
    cout << "4. Hexadecimal\n";

    cout << "Choose source base: ";
    cin >> source;

    cout << "Choose target base (1-Bin, 2-Dec, 3-Oct, 4-Hex): ";
    cin >> target;

    cout << "Enter number: ";
    cin >> input;

    // Convert source to decimal
    switch (source) {
        case 1:
            decimalValue = binaryToDecimal(input);
            break;
        case 2:
            decimalValue = stoi(input);
            break;
        case 3:
            decimalValue = octalToDecimal(input);
            break;
        case 4:
            decimalValue = hexToDecimal(input);
            break;
        default:
            cout << "Invalid source base!\n";
            return 0;
    }

    cout << "Result: ";

    // Convert decimal to target
    switch (target) {
        case 1:
            cout << decimalToBinary(decimalValue);
            break;
        case 2:
            cout << decimalValue;
            break;
        case 3:
            cout << decimalToOctal(decimalValue);
            break;
        case 4:
            cout << decimalToHex(decimalValue);
            break;
        default:
            cout << "Invalid target base!";
    }

    cout << endl;
    return 0;
}

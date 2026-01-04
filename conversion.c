#include <stdio.h>
#include <math.h>
#include <string.h>

// ---------- Binary to Decimal ----------
int binaryToDecimal(long long bin) {
    int dec = 0, i = 0, rem;
    while (bin != 0) {
        rem = bin % 10;
        dec += rem * pow(2, i);
        bin /= 10;
        i++;
    }
    return dec;
}

// ---------- Octal to Decimal ----------
int octalToDecimal(int oct) {
    int dec = 0, i = 0;
    while (oct != 0) {
        dec += (oct % 10) * pow(8, i);
        oct /= 10;
        i++;
    }
    return dec;
}

// ---------- Hexadecimal to Decimal ----------
int hexToDecimal(char hex[]) {
    int len = strlen(hex);
    int dec = 0, base = 1;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9')
            dec += (hex[i] - '0') * base;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            dec += (hex[i] - 'A' + 10) * base;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            dec += (hex[i] - 'a' + 10) * base;

        base *= 16;
    }
    return dec;
}

// ---------- Decimal to Binary ----------
void decimalToBinary(int dec) {
    int bin[32], i = 0;
    while (dec > 0) {
        bin[i++] = dec % 2;
        dec /= 2;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
}

// ---------- Decimal to Octal ----------
void decimalToOctal(int dec) {
    int oct[32], i = 0;
    while (dec > 0) {
        oct[i++] = dec % 8;
        dec /= 8;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", oct[j]);
}

// ---------- Decimal to Hex ----------
void decimalToHex(int dec) {
    char hex[32];
    int i = 0, rem;

    while (dec > 0) {
        rem = dec % 16;
        if (rem < 10)
            hex[i++] = rem + '0';
        else
            hex[i++] = rem - 10 + 'A';
        dec /= 16;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}

// ---------- MAIN MENU ----------
int main() {
    int choice, dec, oct;
    long long bin;
    char hex[20];

    printf("===== Number Base Conversion Menu =====\n");
    printf("1. Binary\n");
    printf("2. Decimal\n");
    printf("3. Octal\n");
    printf("4. Hexadecimal\n");
    printf("Choose source base: ");
    scanf("%d", &choice);

    int target;
    printf("Choose target base (1-Bin, 2-Dec, 3-Oct, 4-Hex): ");
    scanf("%d", &target);

    if (choice == 1) { // Binary
        printf("Enter binary number: ");
        scanf("%lld", &bin);
        dec = binaryToDecimal(bin);
    }
    else if (choice == 2) { // Decimal
        printf("Enter decimal number: ");
        scanf("%d", &dec);
    }
    else if (choice == 3) { // Octal
        printf("Enter octal number: ");
        scanf("%d", &oct);
        dec = octalToDecimal(oct);
    }
    else if (choice == 4) { // Hex
        printf("Enter hexadecimal number: ");
        scanf("%s", hex);
        dec = hexToDecimal(hex);
    }
    else {
        printf("Invalid source base!\n");
        return 0;
    }

    printf("Result: ");
    if (target == 1)
        decimalToBinary(dec);
    else if (target == 2)
        printf("%d", dec);
    else if (target == 3)
        decimalToOctal(dec);
    else if (target == 4)
        decimalToHex(dec);
    else
        printf("Invalid target base!");

    printf("\n");
    return 0;
}

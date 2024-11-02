#include <stdio.h>
#include <string.h>
#include <ctype.h>

int BINTODEC(int num);
int DECTOBIN(int num);
void DECTOHEX(int num);
int HEXTODEC(char *hexnum);
void BINTOHEX(int num);
void HEXTOBIN(char *hexnum);

int main() {
    int num, binnum, dec;
    char hexnum[10]; 

    printf("Enter number:\n"
           "1 for (BIN TO DEC)\n"
           "2 for (DEC TO BIN)\n"
           "3 for (DEC TO HEX)\n"
           "4 for (HEX TO DEC)\n"
           "5 for (BIN TO HEX)\n"
           "6 for (HEX To BIN)\n");
           
    scanf("%d", &num);

    switch (num) {
        case 1:
            printf("Enter a binary number: ");
            scanf("%d", &binnum);
            dec = BINTODEC(binnum);
            printf("%d\n", dec);
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &dec);
            binnum = DECTOBIN(dec);
            printf("%d\n", binnum);
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &dec);
            DECTOHEX(dec);
            printf("\n");
            break;
        case 4:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexnum);
            dec = HEXTODEC(hexnum);
            printf("%d\n", dec);
            break;
        case 5:
            printf("Enter a binary number: ");
            scanf("%d", &binnum);
            BINTOHEX(binnum);
            printf("\n");
            break;
        case 6:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexnum);
            HEXTOBIN(hexnum);
            printf("\n");
            break;
        default:
            printf("Invalid number, try again\n");
            break;
    }

    return 0;
}

int BINTODEC(int num) {
    int decimal = 0, base = 1;
    while (num > 0) {
        int lastDigit = num % 10;
        num /= 10;
        decimal += lastDigit * base;
        base *= 2;
    }
    return decimal;
}

int DECTOBIN(int num) {
    int binary = 0, base = 1;
    while (num > 0) {
        int lastDigit = num % 2;
        num /= 2;
        binary += lastDigit * base;
        base *= 10;
    }
    return binary;
}

void DECTOHEX(int num) {
    char hex[20];
    int i = 0;
    while (num > 0) {
        int temp = num % 16;
        hex[i++] = (temp < 10) ? temp + '0' : temp - 10 + 'A';
        num /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
}

int HEXTODEC(char *hexnum) {
    int decimal = 0, base = 1, len = strlen(hexnum);
    for (int i = len - 1; i >= 0; i--) {
        int value;
        if (hexnum[i] >= '0' && hexnum[i] <= '9') {
            value = hexnum[i] - '0';
        } else if (toupper(hexnum[i]) >= 'A' && toupper(hexnum[i]) <= 'F') {
            value = toupper(hexnum[i]) - 'A' + 10;
        } else {
            printf("Invalid hexadecimal number.\n");
            return 0;
        }
        decimal += value * base;
        base *= 16;
    }
    return decimal;
}

void BINTOHEX(int num) {
    int decimal = BINTODEC(num);
    DECTOHEX(decimal);
}

void HEXTOBIN(char *hexnum) {
    int decimal = HEXTODEC(hexnum);
    printf("%d\n", DECTOBIN(decimal));
}
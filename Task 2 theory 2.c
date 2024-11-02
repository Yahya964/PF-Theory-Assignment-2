#include <stdio.h>
#include <string.h>
void countcharacterfreq(const char *slogan);
int main() {
    char slogans[10][100];  
    int slogansNum;
    printf("Enter the number of slogans: ");
    scanf("%d", &slogansNum);
    getchar();  
    for (int i = 0; i < slogansNum; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogans[i], 100, stdin);

        
        int length = strlen(slogans[i]);
        if (length > 0 && slogans[i][length - 1] == '\n') {
            slogans[i][length - 1] = '\0';
        }
    }
    for (int i = 0; i < slogansNum; i++) {
        countcharacterfreq(slogans[i]);
    }
}
void countcharacterfreq(const char *slogan) {
    int ASCIIvalue = 128;  
    int frequency[ASCIIvalue];
    for (int m = 0; m < ASCIIvalue; m++) {
        frequency[m] = 0;
    }
    for (int j = 0; slogan[j] != '\0'; j++) {
        frequency[(unsigned char)slogan[j]]++;
    }
    printf("For \"%s\": {", slogan);
    int first = 1; 
    for (int j = 0; j < ASCIIvalue; j++) {
        if (frequency[j] > 0) {
            if (!first) printf(", ");
            printf("'%c': %d", j, frequency[j]);
            first = 0;
        }
    }
    printf("}\n");
}



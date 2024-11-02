#include <stdio.h>

void horizontalhist(int values[], int count);
void verticalhist(int values[], int count, int maxvalue);

int main() {
    int values[100];
    int count = 0;
    int maxvalue = 0;

    printf("Enter values (enter -1 to stop):\n");

    for (int i = 0; i < 100; i++) {
        int value;
        printf("Value %d: ", count + 1);
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        values[count] = value;
        if (value > maxvalue) {
            maxvalue = value;
        }
        count++;
    }

    printf("\nTotal values entered: %d\n", count);
    horizontalhist(values, count);
    verticalhist(values, count, maxvalue);
    return 0;
}
void horizontalhist(int values[], int count) {
    printf("\nHorizontal Histogram:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: ", values[i]);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
void verticalhist(int values[], int count, int maxvalue) {
    printf("\nVertical Histogram:\n");
    for (int i = maxvalue; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < count; i++) {
        printf("%2d ", values[i]);
    }
    printf("\n");
}

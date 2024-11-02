#include <stdio.h>
int Firstpick(int sticks) {

    if (sticks % 5 == 0) {
        return -1;
    } else {
        return sticks % 5;
    }
}
int main() {
    int sticks;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &sticks);

    int firstpick = Firstpick(sticks);
    if (firstpick == -1) {
        printf("It's impossible for A to guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick(s) on their first turn to guarantee a win.\n", firstpick);
    }
}

#include <stdio.h>

int main() {
    int n = 7; 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
           
            if ((i == 0 && j == 4) || 
                (i == 1 && (j == 3 || j == 5)) || 
                (i == 2 && (j !=3 && j!=4 && j !=5 )) ||
                (i == 3 && (j == 1 || j == 7)) || 
                (i == 4 && (j == 1 || j==3 || j==5 || j==7)) || 
                (i == 5 && (j == 0 || j == 8)))  
            {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

return 0;
}
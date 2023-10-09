#include <stdio.h>

int main(){
    for (int i = 1; i <=9; i++)
    {
       for (int j = 1; j <=9;j++)
       {
            if (i*j<10)
                printf("%dX%d= %d ", j, i, j*i);
            else
                printf("%dX%d=%d ", j, i, i*j);
       }
        printf("\n");
    }
    
    return 0;
}
#include <stdio.h>

int main(){
    for(int k=0;k<7; k++)
    {
        for (int i = 1; i <=9; i++)
        {
            for (int j = 1+k; j <=3+k; j++)
            {
                if (i*j<10)
                    printf("%d X %d =  %d\t", j, i, j*i);
                else
                    printf("%d X %d = %d\t", j, i, j*i);
            }
            printf("\n");
        }
        printf("\n\n\n");
        k=k+2;
    }

    return 0;
}
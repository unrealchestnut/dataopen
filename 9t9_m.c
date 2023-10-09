#include <stdio.h>

int main(){
    for(int k=0;k<3; k++)
    {
        for (int i = 1; i <=9; i++)
        {
            for (int j = 1+k; j <=9; j++)
            {
                if (i*j<10)
                    printf("%d X %d =  %d\t", j, i, j*i);
                else
                    printf("%d X %d = %d\t", j, i, j*i);
                j=j+2;
            }
            printf("\n");
        }
        printf("\n\n\n");
    }

    return 0;
}
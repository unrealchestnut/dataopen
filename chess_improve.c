#include <stdio.h>

#define length 8
#define width 8
#define empty 0

int main(){
    int chess[length][width];

    //printf("左至右，上至下、空0黑1白2");//單純提示
    /*for(int i=0;i<length;i++)
        for(int j=0;j<width;j++)
            scanf("%d", &(chess[i][j]));*/

    for(int i=0;i<length;i++)//暴力輸入
        for(int j=0;j<width;j++)
            chess[i][j]=empty;
    chess[3][3]=1;
    chess[3][4]=2;
    chess[4][3]=2;
    chess[4][4]=1;
    chess[4][2]=2;

    for(int i=0;i<length;i++)//確認輸入的正確與否
    {    
        for(int j=0;j<width;j++)
            printf("%d ", chess[i][j]);
        printf("\n");
    }

    int mine, enemy;
    scanf("%d", &mine);
    if(mine==1)
    enemy=2;
    else 
    enemy=1;//告知要檢測的是黑子還是白子

    int check[3][3];//用迴圈算出可以接續棋子之地方的真偽
    int ans[length][width];//標記答案
    for(int i=0;i<length;i++)
        for(int j=0;j<width;j++)
            ans[i][j]=0;

    for(int ty=0;ty<length;ty++){
        for(int tx=0;tx<width;tx++){
            if(chess[ty][tx]==enemy){
                for(int i=0;i<3;i++)//清除標記
                    for(int j=0;j<3;j++)
                        check[i][j]=0;
                for(int dy=-1;dy<2;dy++)//標記我方棋子
                    for(int dx=-1;dx<2;dx++){
                        if(chess[ty+dy][tx+dx]==mine)
                            check[dy+1][dx+1]=1;
                        if(chess[ty+dy][tx+dx]==enemy){
                            for(int t=2;t<7;t++){
                                if(chess[ty+dy*t][tx+dx*t]==mine){
                                    check[dy+1][dx+1]=1;
                                    break;
                                }
                                else if(chess[ty+dy*t][tx+dx*t]==empty)
                                    break;
                            }
                        }
                    }
                for(int ay=-1;ay<2;ay++)//輸出答案
                    for(int ax=-1;ax<2;ax++)
                        if(check[ay+1][ax+1] == 1)
                            ans[ty-ay][tx-ax]=1;
            }
        }
    }

    for(int recheck_y=0;recheck_y<length;recheck_y++)//排除已被下棋子的地方
        for(int recheck_x=0;recheck_x<width;recheck_x++)
            if(chess[recheck_y][recheck_x]!=0 && ans[recheck_y][recheck_x]==1)
                ans[recheck_y][recheck_x]=0;
    
    for(int i=0;i<length;i++)//確認排布情況的正確與否
    {    
        for(int j=0;j<width;j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }

    for(int ansy=0;ansy<length;ansy++)
        for(int ansx=0;ansx<width;ansx++)
            if(ans[ansy][ansx]==1)
                printf("%d,%d\n", ansx+1, ansy+1);

    return 0;
}
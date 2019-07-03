#include<cstdio>

void FindContinuousSequence(int sum){
    if(sum<3)
        return;
    //初始值
    int small = 1;
    int big = 2;
    int middle = (1+sum)/2;
    int curSum = small + big;

    while(small < middle){
        if(curSum == sum){
            PrintContinousSequence(small,big);
        }

        while(curSum > sum && small < middle){

            curSum -= small;//  small前移一位，数值变小
            small++;

            if(curSum == sum){
                PrintContinousSequence(small,big);
            }

        }

        big++;
        curSum +=big;

    }

}

void PrintContinousSequence(int small,int big){
    for(int i=small;i<=big;i++){
        printf("%d ",i);
    }
    printf("\n");
}
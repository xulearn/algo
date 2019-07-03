#include<algorithm>
using namespace std;

bool IsContinuous(int* numbers, int length){
    if(numbers == nullptr || length<1)
        return false;
    qsort(numbers,length,sizeof(int),compare);

    int numberOfZero = 0;
    int numberOfGap = 0;

    //统计0的个数
    for(int i=0;i<length && numbers[i]==0; ++i){
        ++numberOfZero;
    }

    //统计间隔数目
    int small = numberOfZero;
    int big = small +1;
    while(big<length){
        if(numbers[small] == numbers[big]){
            return false;
        }
        numberOfGap += numbers[big] - numbers[small] -1;//用这一句判断big和small是否相邻还是有间隔
        small = big;
        ++big;

    
    }

    return (numberOfGap > numberOfZero) ? false:true;

}

int compare(const void *arg1, const void *arg2){
    return *(int*)arg1-*(int*)arg2;
}
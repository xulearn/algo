#include<exception>
#include<ctime>

using namespace std;

bool g_bInputInvalid = false;


bool CheckInvalidArray(int* numbers,int length){
    g_bInputInvalid = false;
    if(numbers==nullptr || length<=0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers,int length,int number){
    int times=0;
    for(int i=0;i<length;i++){
        if(numbers[i]==number)
            times++;
    }

    bool isMoreThanHalf = true;
    if(times*2<=length){
        g_bInputInvalid=true;
        isMoreThanHalf=false;
    }
    return isMoreThanHalf;
}


int MoreThanHalfNum(int* numbers,int length){
    if(CheckInvalidArray)
        return 0;

    int result = numbers[0];//设置一个初始基准值
    int times = 1;//初始计数

    for(int i=1;i<length;i++){
        if(times==0){//若times为0，则修改基准值
            result = numbers[i];
            times = 1;
        }else if(numbers[i]==result){//若与result相等，则次数加
            times++;
        }else{//若与result不等，则次数减
            times--;
        }
    }
    if(!CheckMoreThanHalf(numbers,length,result))
        result = 0;
    return result;
}
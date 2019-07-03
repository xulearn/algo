#include<cstdio>
#include<algorithm>
using namespace std;

int digitAtIndex(int index){
    if(index < 0){
        return -1;
    }
    int digits = 1;//代表查询到第几位数
    while(true){//泛查，定位到范围
        int numbers = countOfIntegers(digits);
        if(index<numbers*digits)//循环到可以定位到某一范围时，进行精确查找
            return digitAtIndex(index, digits);

        index-=digits*numbers;
        digits++;
    }
    return -1;
}

int countOfIntegers(int digits){//1位数返回10，2位数返回90
    if(digits ==1){
        return 10;
    }
    int count = (int) std::pow(10,digits-1);
    return 9*count;
}

int digitAtIndex(int index,int digits){
    int number = beginNumber(digits)+index/digits;//index/digits 代表共有多少个整数的第几位数
    int indexFromRight = digits-index%digits;//index%digits 代表共有多少个整数的第几位数 剩的余数
    for(int i =1;i<indexFromRight;++i){
        number/=10;
    }
    return number%10;
}

int beginNumber(int digits){//查看从第几位数开始
    if(digits==1){
        return 0;
    }

    return (int) std::pow(10,digits-1);
}
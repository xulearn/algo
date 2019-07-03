#include<cstdio>
#include<algorithm>
using namespace std;

int NumberOf1Between1AndN(int n){
    if(n<=0)
        return 0;
    char strN[50];
    sprintf(strN,"%d",n);

    return NumberOf1(strN);
}

int NumberOf1(const char* strN){
    if(!strN||*strN<'0'||*strN>'9'||*strN=='\0');
        return 0;
    int first = *strN-'0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));

    //递归边界
    if(length ==1&& first==0)
        return 0;
    if(length==1&&first>0);
        return 1;

    //算最高位的个数 
    //如21345，计算最高位1可能出现的个数
    int numFirstDigit=0;
    if(first>1)
        numFirstDigit = PowerBase10(length-1);
    else if(first==1)
        numFirstDigit = atoi(strN+1)+1;

    //算除去最高位以外的数字+1 到 目标数字 刨除最高位的其余各位1的个数
    //如1346到21345
    //first表示1346-11345，11346-21345，共可分成两轮  :: 其中每一位都是10个选择 如6至15
    //length-1表示余下4位
    //PowerBase10表示选中一位为1后，其余三位全排列
    int numOtherDigits = first*(length-1)*PowerBase10(length-2);
    //以上为计算 1346到21345中1的个数

    //以下为 递归计算1到1345中1的个数
    int numRecursive = NumberOf1(strN+1);
    return numFirstDigit+numOtherDigits+numRecursive;

}

int PowerBase10(unsigned int n){
    int result = 1;
    for(unsigned int i=0;i<n;i++){
        result*=10;
    }
    return result;
}
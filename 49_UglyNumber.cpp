int GetUglyNumber_solution(int index){
    if(index<=0){
        return 0;
    }

    int* pUglyNumber = new int[index];

    pUglyNumber[0] = 1;
    int nextUglyIndex = 1;

    int* pMultiply2 = pUglyNumber;
    int* pMultiply3 = pUglyNumber;
    int* pMultiply5 = pUglyNumber;

    while(nextUglyIndex<index){
        int min = Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);//将刚刚好大于这个数的乘积进行比较
        pUglyNumber[nextUglyIndex] = min;

        while(*pMultiply2*2 <=pUglyNumber[nextUglyIndex])//找到乘积结果刚刚好大于最后一个数的下标
            ++pMultiply2;
        while(*pMultiply3*3 <=pUglyNumber[nextUglyIndex])//找到乘积结果刚刚好大于最后一个数的下标
            ++pMultiply3;
        while(*pMultiply5*5 <=pUglyNumber[nextUglyIndex])//找到乘积结果刚刚好大于最后一个数的下标
            ++pMultiply5;
        ++nextUglyIndex;
    }

    int ugly = pUglyNumber[nextUglyIndex-1];
    delete[] pUglyNumber;
    return ugly;



}

int Min(int num1,int num2, int num3){
    int min = (num1<num2)? num1: num2;
    min = (min<num3)? min: num3;
    return min;
}
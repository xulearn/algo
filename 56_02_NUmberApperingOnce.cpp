#include<exception>

int FindNumberApperingOnce(int numbers[], int length){
    if(numbers == nullptr || length <=0)
        throw new std::exception("Invalid input.");

    int bitSum[32] = {0};

    for(int i=0;i<length ;++i){
        int bitMask = 1;

        for(int j = 31;j>=0;--j){   //从低位向高位遍历
            int bitMask = 1;

            int bit = numbers[i] & bitMask;

            if(bit){
                bitSum[j] += 1;
            }
            bitMask = bitMask << 1;     //bitMask表示测试位，每次乘2，1的位置向前一位

        }
    }

    int result = 0;

    for(int i=0;i<32;++i){
        result = result<<1;
        result += bitSum[i]%3;
    }
    
    // int base = 1;

    // for(int i=0;i<32;++i){
    //     result += (bitSum[i]%3)*base;
    //     base = base*2;
    // }
    


}
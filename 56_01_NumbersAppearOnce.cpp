void FindNumsAppearOnce(int data[], int length, int* num1, int* num2){
    if(data == nullptr || length <2){
        return ;
    }

    int resultExclusiveOR = 0;

    for(int i =0;i<length;++i){
        resultExclusiveOR ^=data[i];    //两个数不同，异或结果一定不为0，一定有一位为1，而且这两个数在这一位一定不同（一个为0，一个为1）
    }
    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);//   第一个为1的下标

    *num1 = *num2 = 0;              //初始用0异或，数值不变

    for(int j=0;j<length;++j){
        if(IsBit1(data[j],indexOf1))    //该位为1，用num1异或，该位为0，用num2异或，
            *num1 ^= data[j];       //初始用0异或，数值不变
        else
            *num2 ^= data[j];
    }


}


unsigned int FindFirstBitIs1(int num){
    int indexBit = 0;
    while(((num&1)==0) && indexBit < 8*sizeof(int)){
        num = num>>1;
        ++indexBit;
    }

    return indexBit;
}

bool IsBit1(int num, unsigned int indexBit){
    num = num >>indexBit;
    return (num&1);
}
int MaxDiff(const int* numbers, unsigned int length){
    if(numbers == nullptr && length<2)
        return 0;
    int min = numbers[0];
    int maxDiff = numbers[1]-min;       //diff(i)定义为当卖出价为i时，可获得的最大利润

    for(int i=2;i<length;++i){
        if(numbers[i-1]<min)
            min = numbers[i-1];

        int currentDiff = numbers[i] - min;
        if(currentDiff > maxDiff){
            maxDiff = currentDiff;
        }
        return maxDiff;
    }


}
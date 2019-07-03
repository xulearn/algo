
int InversePairs(int* data,int length){
    if(data==nullptr || length<0){
        return 0;
    }
    int* copy = new int[length];
    for(int i=0;i<length;i++){
        copy[i] = data[i];
    }

    int count = InversePairsCore(data,copy,0,length-1);

    delete copy;
    return count;

}


int InversePairsCore(int* data,int* copy,int start,int end){
    if(start==end){
        copy[start] = data[start];
        return 0;
    }

    int length = end-start;

    int medium = start + length/2;

    //归并排序，向左递归，直到递归到只剩一个元素
    int left = InversePairsCore(copy,data,start,medium);
    //int left = InversePairsCore(copy,data,start,medium);  这种情况输出正确，上面输出错误

    //归并排序，向右递归，直到递归到只剩一个元素
    int right = InversePairsCore(copy,data,medium+1,end);
    //int right = InversePairsCore(copy,data,medium+1,end);     这种情况输出正确，上面输出错误

    //递归结束，将相邻数组，进行排序，排序的过程中统计逆序对
    //i为左侧最后一个
    int i = medium;
    //j为右侧最后一个，也是整个数组最后一个
    int j = end;
    
    int indexCopy = end;
    
    int count = 0;

    while(i>=start&&j>=medium+1){
        if(data[i]>data[j]){
            copy[indexCopy--] = data[i--];
            count += j-medium;      //只要data[i]>data[j],则就出现逆序对，逆序对个数即为 当前j 到medium 的所有个数（即在j这一侧中，所有j前的元素都与data[i]构成逆序对，因为已经排好序）
        }else{
            copy[indexCopy--] = data[j--];
        }
    }

    for(;i>=start;--i){
        copy[indexCopy--] = data[i];
    }
    for(;j>=medium+1;--j){
        copy[indexCopy--] = data[j];
    }
    return left+right+count;
}

int GetFirstK(int* data,int length,int K,int start,int end){
    if(start>end){
        return -1;
    }

    int middleIndex = (start+end)/2;
    int middleData = data[middleIndex];

    if(middleData==K){
        if((middleIndex>0 && data[middleIndex-1]!=K) || middleIndex==0){
            return middleIndex;
        }else{
            end = middleIndex-1;
        }
    }else if(middleData>K){
        end = middleIndex-1;
    }else{          //middle<K时
        start = middleIndex +1;
    }

    return GetFirstK(data,length,K,start,end);


}


int GetLastK(int* data,int length,int K,int start, int end){
    if(start>end){
        return -1;
    }

    int middleIndex = (start+end)/2;
    int middleData = data[middleIndex];

    if(middleData==K){
        if((middleIndex<length-1 && data[middleIndex+1] != K)|| middleIndex == length-1){
            return middleIndex;
        }else{
            start = middleIndex+1;
        }   
    }else if(middleData>K){
        end = middleIndex-1;
    }else{
        start = middleIndex+1;
    }

}

int GetNUmberOfK(int* data,int length,int K){
    int number = 0;
    if(data!=nullptr && length>0){
        int first = GetFirstK(data,length,K,0,length-1);
        int last = GetLastK(data,length,K,0,length-1);

        if(first>-1 && last>-1)
            number = last-first+1;
    }
    return number;
}



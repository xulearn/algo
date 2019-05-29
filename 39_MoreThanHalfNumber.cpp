/*
此即为快排算法
*/

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

//用来在start与end两个数区间产生随机数
int RandomInRange(int start, int end){
    srand(time(NULL));
    return rand()% (end-start+1)+start;
}

void swap(int cs[], int i, int j){
        int temp = cs[i];
        cs[i]=cs[j];
        cs[j] = temp;
    }

int Partition(int data[],int length,int start,int end){
    if(data==nullptr ||length<=0||start<0||end>=length)
        throw new std::exception("invalid parameters");
    
    int index = RandomInRange(start,end);//找一个标兵
    swap(data,index,end);

    int small = start-1;
    for(index=start;index<end;index++){
        if(data[index]<data[end]){
            small++;
            if(small!=index)//说明small与index之间有大于data[end]的元素
                swap(data,index,small);
        }
    }
    small++;
    swap(data,small,end);
    return small;

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
    if(CheckInvalidArray(numbers,length))
        return 0;
    int middle = length>>1;
    int start = 0;
    int end = length-1;
    
    int index = Partition(numbers,length,start,end);
    while(index!=middle){
        if(index>middle){//大于middle
            end = index-1;
            index = Partition(numbers,length,start,end);
        }else{//小于middle
            start = index+1;
            index = Partition(numbers,length,start,end);
        }
    }
    int result = numbers[index];
    if(!CheckMoreThanHalf(numbers,length,result)){
        result = 0;
    }
    return result;

}
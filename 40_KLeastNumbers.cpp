#include<exception>

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

void GetLeastNumbers(int* input,int n,int* output,int k){
    if(input==nullptr ||output==nullptr||k>n||n<=0||k<=0)
        return ;

    int start=0;
    int end = n-1;
    int index = Partition(input,n,start,end);
    while(index!=k-1){//index的左右都是排好序的
        if(index>k-1){
            end = index-1;
            Partition(input,n,start,end);
        }else{
            start=index+1;
            Partition(input,n,start,end);

        }
    }

    for(int i=0;i<k;i++){
        output[i]=input[i];
    }

}
#include<iostream>
#include<algorithm>
using namespace std;
bool isMatch(int A[]){
    if(A==NULL)
        return false;
    int r1 = A[0] + A[1] + A[2] + A[3];
	int r2 = A[4] + A[5] + A[6] + A[7];
	int r3 = A[0] + A[2] + A[4] + A[6];
	int r4 = A[1] + A[3] + A[5] + A[7];
	int r5 = A[0] + A[1] + A[4] + A[5];
	int r6 = A[2] + A[3] + A[6] + A[7];
    if((r1==r2)&&(r3==r4)&&(r5==r6))
        return true;
}

void count_case(int A[],int length,int index,bool& is){
    if(A==NULL || length<=0 || index<0)
        return ;
    if(index==length)
        return ;
    if(isMatch(A)){
        is=true;
        return ;
    }else{
        for(int p = index;p<=length;p++){
            swap(A[p],A[index]);
            count_case(A,length,index+1,is);
            swap(A[index],A[p]);
        }
    }
}

bool cub_case(){
    const int index=8;
    int A[index]={1,2,3,4,5,6,7,8};
    bool is = false;
    count_case(A,index-1,0,is);
    return is;
}

int main(){
    bool i = cub_case();
    cout<<i<<endl;
    system("pause");
    return 0;
}
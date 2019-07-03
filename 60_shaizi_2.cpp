#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;

/****************************************
func:给定骰子数目n，求所有可能点数和的种类数
para：n:骰子个数;count:存放各种点数和的种类数，下标i表示点数和为（i+n）
return:出错返回-1，成功返回0
****************************************/
int getNSumCountNotRecusion(int n,int* count){
    if(n<1)
        return -1;
    count[1]=count[2] = count[3]=count[4]=count[5]=count[6]=1;  //在此赋初值(有一个骰子时)
    if(n==1) return 0;

    for(int i = 2;i<=n; ++i){//i=2,3,4...以后的状态转移方程
        for(int sum=6*i;sum>=i;--sum){
            int tmp1 = sum-1-(i-1) >=0 ? count[sum-1]: 0;
            int tmp2 = sum-2-(i-1) >=0 ? count[sum-2]: 0;
            int tmp3 = sum-3-(i-1) >=0 ? count[sum-3]: 0;
            int tmp4 = sum-4-(i-1) >=0 ? count[sum-4]: 0;
            int tmp5 = sum-5-(i-1) >=0 ? count[sum-5]: 0;
            int tmp6 = sum-6-(i-1) >=0 ? count[sum-6]: 0;
            /*
            此处sum-3-(i-1)可分为两段看：
            1、sum-3 即如果当前骰子点数为3，剩下的骰子点数和将为sum-3, 即状态方程f(n-1,s-3)
            2、sum-3 -(i-1) 即剩下的骰子点数和至少要大于剩下的骰子的个数（即剩下的骰子每个点数至少大于1）
                            此式中，i为骰子数，i-1即为剩下的骰子数

                            如3个骰子，sum=3时，只能每个骰子点数分别为1点，不可能出现2点+0点
            
            */
            count[sum] = tmp1+tmp2+tmp3+tmp4+tmp5+tmp6;
        }
    }
    return 0;

}
int main(){
    int n;
    while(true){
        cout<<"iteration input dice num：";
        cin>>n;
        int* count = new int[6*n];
        memset(count,0,6*n*sizeof(int));

        getNSumCountNotRecusion(n,count);
        int allCount=0;
        for(int i=n;i<=6*n;++i){
            cout<<"f("<<n<<","<<i<<")="<<count[i]<<endl;
            allCount+=count[i];
        }
        delete[] count;

    }
}
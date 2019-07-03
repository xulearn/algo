#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

/****************************
func:获取n个骰子指定点数和出现的次数
para:n:骰子个数;sum:指定的点数和
return:点数和为sum的排列数
****************************/
int getNSumCount(int n,int sum){    //递归方式
    if(n<1 || sum<n || sum>6*n)
        return 0;
    if(n==1)
        return 1;

    int resCount = 0;
    resCount = getNSumCount(n-1,sum-1)+getNSumCount(n-1,sum-2)+getNSumCount(n-1,sum-3)+
                getNSumCount(n-1,sum-4)+getNSumCount(n-1,sum-5)+getNSumCount(n-1,sum-6);
    return resCount;

}

int main(){
    int n=0;
    while(true){
        cout<<"input dice num = ";
        cin>>n;
        for(int i=n;i<=6*n;++i)
            cout<<"f("<<n<<","<<i<<")="<<getNSumCount(n,i)<<endl;
    }

    int total = pow((float)6, n);   
    for(int i = n; i <=6*n; ++i){   //n:骰子数目
        float ratio = (float)getNSumCount(n,i)/total;  
        printf("%d: %f/n", i, ratio);  
    }  

}


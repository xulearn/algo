#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
/*
由此定义状态转移方程为f(n,k)表示n个骰子点数和为k时出现的次数，于是可得:

f(n,k)=f(n−1,k−1)+f(n−1,k−2)+f(n−1,k−3)+f(n−1,k−4)+f(n−1,k−5)+f(n−1,k−6)

其中 n>0且k<=6n。其中f(n−1,k−i)表示的是第n次掷骰子时，骰子的点数为i对应的情况，所以从k−1到k−6分别对应第n次掷骰子时骰子正面为1到6的情况。而初始状态可以定义为：

f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1

*/
void FindSum(int n){
    if(n<=0)
        return ;
    int sum = 0;

    
    //int arr[n+1][6*n+1];//行表示有几个骰子，列表示几个骰子点数和,arr数组表示出现和的次数
                        //  点数和从n开始到6n结束

    int** arr = new int*[n+1];
    for(int i=0;i<n+1;i++){
        arr[i] = new int[6*n+1];
    }
    // int** arr = (int**)malloc((n+1)*sizeof(int*));

    // for(int i = 0;i<n+1;i++){
    //     arr[i] = (int*)malloc((6*n+1)*sizeof(int));
    // }

    memset(arr,0,sizeof(arr));

    for(int j = 1; j<=6;j++){
        arr[1][j] = 1;      //i=1在此赋初值(有一个骰子时)
    }

    for(int i = 2; i<=n; i++){  //i=2,3,4...以后的状态转移方程
        for(int j = i;j<= 6*i; j++){    //点数和受骰子个数影响
            arr[i][j] += (arr[i-1][j-1]+arr[i-1][j-2]+arr[i-1][j-3]+arr[i-1][j-4]+arr[i-1][j-5]+arr[i-1][j-6]);
        }
    }        

    for(int j=n; j<=6*n; ++j){
        sum += arr[n][j];
    }  

    cout<<n<<"个骰子总共的次数为 "<<sum<<endl;

    for(int j=n;j<=6*n; ++j){
        cout<<"骰子的和为 "<<j<<" 时，对应的频率为："<<(arr[n][j] * 1.0 / sum)<<endl;
    }

    // for(int i=0;i<n+1;i++){
    //     free(arr[i]);
    // }
    // free(arr);

    for(int i=0;i<n+1;i++){
        delete[] arr[i];
    }
    delete[] arr;


}

int main(){
    int n;
    cout<<"请输入骰子的个数:"<<endl;
    cin>>n;
    FindSum(n);
}
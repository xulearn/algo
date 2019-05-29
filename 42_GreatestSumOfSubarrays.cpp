#include<vector>
#include<algorithm>
using namespace std;
bool g_InvalidInput = false;

int FindGreatestSumOfSunArray(int* pData,int nlength){
    if((pData == nullptr)||(nlength<=0)){
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for(int i=0;i<nlength;++i){
        if(nCurSum<=0)
            nCurSum = pData[i];
        else
            nCurSum +=pData[i];

        if(nCurSum>nGreatestSum)
            nGreatestSum=nCurSum;
    }
    return nGreatestSum;

}

//动态规划1：
int FindGreatestSumOfSubArray(vector<int> array){
    if(array.empty()) return 0;
    int sum = array[0], tempSum = array[0];
    for(int i=1;i<array.size();++i){
        tempSum = (tempSum<0)? array[i] : tempSum+array[i];
        sum = (tempSum>sum)? tempSum : sum;
    }
    return sum;
}

//动态规划2：

int Find(vector<int> array){
    vector<int> dp(array.size());
    dp[0] = array[0];
    for(int i=1;i<array.size();++i){//dp[i]表示以下标i为结束的子序列的最大和，但并未记录最大和序列
        dp[i]=max(array[i],array[i]+dp[i]);
    }
    return *max_element(dp.begin(),dp.end());
}
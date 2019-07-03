#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void perm(vector<int> input,int k,vector<vector<int> >& res){
    if(k==input.size()){
        res.push_back(input);
    }else{
        for(int i=k;i<input.size();i++){
            swap(&input[i],&input[k]);
            perm(input,k+1,res);
            swap(&input[k],&input[i]);
        }
    }
    
}

vector<vector<int> > perm(vector<int> input){
    vector<vector<int> > res;
    if(!input.empty()){
        perm(input,0,res);
    }
    return res;
}

bool isMatched(vector<int> array){
    if(array.empty()) return false;
    int len = array.size();

    for(int i=0;i<len;i++){//按行为基准，一次循环向后查看是否后面的行是否与前面的行有冲突
        for(int j=i+1;j<len;++j){
            if( (j-i)==(array[j]-array[i]) || (j-i)==(array[i]-array[j]) )
                return false;
        }
    }
    return true;

}

int Queens(unsigned int numbers, vector<vector<int> >& res){
    if(numbers==0) return -1;

    vector<int> input(numbers,0);
    vector<vector<int> > ans;
    vector<vector<int> > arrays;
    for(unsigned int i=0;i<numbers;++i){
        input[i]=i;
    }
    arrays=perm(input);
    int count=0;
    for(auto v: arrays){
        if(isMatched(v)){
            ans.push_back(v);
            ++count;
        }
    }
    res = ans;
    return count;
}
int main(){
    vector<vector<int> > res;
    int n = Queens(8,res);
    if(n){
        for(auto v: res){
            for(auto i: v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<"total is"<<n<<endl;
    }
    getchar();
    return 0;
}                           
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

void combination(char* str,int number,vector<char>& cRes,vector<string>& res){
    if(str==NULL)
        return ;
    if(number==0){
        string tempStr(cRes.size(),' ');
        for(size_t i=0;i<cRes.size();++i){
            tempStr[i] = cRes[i];
        }
        res.push_back(tempStr);
        return;
    }

    if(*str =='\0') return;//若number多于剩下的str串，则返回空，表示此法不通
    //选当前字符
    cRes.push_back(*str);
    combination(str+1,number-1,cRes,res);

    //不选当前字符
    cRes.pop_back();
    combination(str+1,number,cRes,res);

    
}

vector<string> combination(char* str){
    vector<string> res;
    int len = strlen(str);
    if(len){
        for(int i=1;i<=len;i++){//循环以确定每种组合的长度
            vector<char> cRes;
            combination(str,i,cRes,res);
        }
    }
    return res;
}

int main(){
    char* str2 = "abc";
    vector<string> res = combination(str2);
    for(auto s : res){
        cout<<s<<endl;
    }
    getchar();
    return 0;
}
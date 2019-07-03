#include<string>
using namespace std;

void Reverse(char* pBegin,char* pEnd){
    if(pBegin == nullptr || pEnd == nullptr)
        return;
    while(pBegin < pEnd){
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++;
        pEnd--;
    }
}

char* LeftRotateString(char* pStr,int n){
    if(pStr!=nullptr){
        int nLength = static_cast<int>(strlen(pStr));

        if(nLength>0 && n>0 && n<nLength){
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr+n;
            char* pSecondEnd = pStr+nLength-1;

            Reverse(pFirstStart, pFirstEnd);

            Reverse(pSecondStart, pSecondEnd);

            Reverse(pFirstStart,pSecondEnd);


        }



    }
}
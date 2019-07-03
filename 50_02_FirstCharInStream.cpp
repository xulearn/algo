#include<limits>
using namespace std;

class CharStatics{
private:
    int occurence[256]; //i表示ascii码，数组存第一次出现的下标
                        // =-1没找到，=-2，找到多次
    int index;      //字符出现的位置，即下标

public:
    CharStatics():index(0){
        for(int i=0;i<256;++i){
            occurence[i]=-1;
        }
    }

    void insert(char ch){
        if(occurence[ch]==-1)
            occurence[ch] = index;
        else if(occurence[ch]>=0)
            occurence[ch] = -2;
        index++;
    }

    char FirstAppearing(){
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for(int i=0;i<256;i++){
            if(occurence[i]>=0&&occurence[i]<minIndex){
                minIndex = occurence[i];
                ch = (char)i;
            }
               
        }
        return ch;
    }


}


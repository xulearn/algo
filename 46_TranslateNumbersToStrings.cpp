#include<cstring>
#include<string>
using namespace std;

int GetTranslationCount(int number){
    if(number<0){
        return 0;
    }
    string numberInString = to_string(number);
    return GetTranslationCount(numberInString);
}


int GetTranslationCount(const string& number){
    int length = number.length();
    int* counts = new int[length];
    int count = 0;
    for(int i=length-1;i>=0;i--){
        count=0;

        //采用公式f(i)=f(i+1)+(0,1)*f(i+2)进行递归,f(i)表示从第i位开始（递归）的不同的翻译数目 (0,1) = g(i,i+1)
        //如：a, b, c
        /*
        可分为两种情况f(a)=
        a+ (bc...   此种为f(i+1), 即a单独翻译成字母，此种情况必可以
        ab+ (c...   此种为f(i+2)，即a和b共同翻译成数字，但此种情况可能就超过25无法翻译成字母，
                        因此进行判断，并用0或1与之相乘，构成选择开关
        */
       //但采用此种从左至右的递归方式，会进行重复判断
       //因此采用从右至左的迭代方式，即f(i-2) = f(i-1) + g(i-2,i-1)*f(i)

        if(i<length-1)  //i为其他位时，则必然可以先把f(i+1)赋给当前值
            count = counts[i+1];
        else            //i为最后一位时，必然可以为1
            count = 1;
        


        //以下为计算g(i-2,i-1) 亦即g(i,i+1)
        if(i<length-1){
            int digit1 = number[i]-'\0';
            int digit2 = number[i+1]-'\0';
            int converted = digit1*10 +digit2;
            if(converted>=10&&converted<=25){   //若在字母表范围内，则g(i,i+1)=1,与前值累加即可
                if(i<length-1)  //若有f(i+2)则相加
                    count+=counts[i+2];
                else            //若f(i+2)超出数组范围，则只可能多出一种情况，如a,b 和ab两种情况，加一即可
                    count+=1;
            }
        }

        counts[i]=count;

    }
    count = counts[0];
    delete[] counts;
    return count;


}
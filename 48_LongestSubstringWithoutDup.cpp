#include<string>

int longestSubstringWithoutDuplication(const std::string& str){
    int curLength = 0;//当前不重复子串的长度
    int maxLength = 0;

    int* position = new int[26];

    //position数组表示26个字母上一次出现的位置
    for(int i=0;i<26;i++){
        position[i]=-1;
    }
    for(int i=0;i<str.length();++i){
        int preIndex = position[str[i]-'a'];
        if(preIndex<0 || i-preIndex>curLength){//i-preIndex为两相同字符之间的距离 与 当前不重复子串的长度 比较大小
            ++curLength;
        }else{
            if(curLength>maxLength)     //先把cur的值保存下来，再更新cur的值
                maxLength = curLength;
            curLength = i-preIndex;     //若相同，则不重复子串长度不变（向后平移一位），即不要pre，要i，方便后续遍历
        }

        position[str[i]-'a'] = i;
    }

    if(curLength>maxLength)
        maxLength=curLength;
    delete[] position;
    return maxLength;


}
enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

int StrToInt(const char* str){
    g_nStatus = kInvalid;
    long long num=0;
    if(str!=nullptr && *str!='\0'){
        bool minus = false;
    }
}
char FirstNotReaptingChar(char* pString){
    unsigned int hashTable[256];

    for(unsigned int i = 0;i<256;i++){
        hashTable[i]=0;
    }


    char* p = pString;
    while(*p!='\0'){
        hashTable[*(p++)]++;
    }
    p = pString;
    while(*p!='\0'){
        if(hashTable[*p]==1)
            return *p;
        p++;
    }
    return '\0';
}
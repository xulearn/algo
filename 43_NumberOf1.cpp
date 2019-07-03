int NumberOf1Between1AndN(unsigned int n){

    int number =0;

    for(unsigned int i=1;i<=n;i++){
        number+=NumberOf1(i);
    }
    return number;

}

int NumberOf1(unsigned int n){
    int number=0;
    while(n){
        if(n%10==1)
            number++;
        n /= 10;
    }
    return number;
}

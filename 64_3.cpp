typedef unsigned int(*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n){
    return 0;
}

unsigned int Sum_Solution3(unsigned int n){
    static fun f[2] = {Solution3_Teminator,Sum_Solution3};
    return n+f[!!n](n-1);
}

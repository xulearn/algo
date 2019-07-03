class A;
A* Array[2];

class A{
public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};

class B:public A{
public:
    virtual unsigned int Sum(unsigned int n){
        return Array[!!n]->Sum(n-1)+n;  //取!!n 表示非零的时候，取反为0，再取反为1，保证再0，1之间取值
    }
};

int Sum_Solution(int n){
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);
    return value;
}
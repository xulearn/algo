class Temp{
private:
    static unsigned int N;
    static unsigned int Sum;
public:
    Temp(){
        ++N;
        Sum +=N;
    }

    static void Reset(){
        N=0;
        Sum =0;
    }

    static unsigned int GetSum(){
        return Sum;
    }

};

unsigned int Temp::N=0;
unsigned int Temp::Sum = 0;
unsigned int Sum_Solution1(unsigned int n){
    Temp::Reset();
    Temp *a = new Temp[n];
    delete[] a;
    a = nullptr;
    return Temp::GetSum();
}
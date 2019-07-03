template<unsigned int n> struct Sum_Solution4{
    enum Value{
        N = Sum_Solution4<n-1>::N+n
    };
};

template <> struct Sum_Solution4<1>{
    enum Value{
        N=1
    };
};
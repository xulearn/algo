#include<list>
using namespace std;

int LastRemaining(unsigned int n,unsigned int m){
    if(n<1 || m<1)
        return -1;
    unsigned int i =0;
    list<int> numbers;
    for(int i=0;i<n;++i){
        numbers.push_back(i);
    }

    list<int>::iterator current = numbers.begin();

    while(numbers.size()>1){
        for(int i=1;i<m;++i){
            current++;
            if(current == numbers.end())
                current = numbers.begin();
        }
        list<int>::iterator next = ++current;   //为了标记next，current又向后+1
        if(next == numbers.end())
            next = numbers.begin();
        --current;                              //要将前面的加一，减回来

        numbers.erase(current);
        current = next;


    }
    return *(current);

}
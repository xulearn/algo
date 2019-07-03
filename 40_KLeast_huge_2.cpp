#include<set>
#include<vector>
using namespace std;

typedef multiset<int,greater<int> > intSet;
typedef multiset<int,greater<int> >::iterator setIterator;

//采用set，内部红红黑树实现，可以满足大量数据的查找

void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k){
    leastNumbers.clear();
    if(k<1||data.size()<k)
        return ;
    vector<int>::const_iterator iter = data.begin();
    for(;iter!=data.end();++iter){
        if(leastNumbers.size()<k)
            leastNumbers.insert(*iter);
        else{
            setIterator iterGreatest = leastNumbers.begin();
            if(*iter<*(leastNumbers.begin())){
                leastNumbers.erase(*iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}
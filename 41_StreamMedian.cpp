#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

template<typename T> class DynamicArray{
private:
    vector<T> min;//最小堆，大数里面取最小
    vector<T> max;//最大堆，小数里面取最大
public:
    void Insert(T num){
        if(((min.size()+max.size())&1)==0){
            if(max.size()>0&&num<max[0]){
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<T>());

                num = max[0];

                pop_heap(max.begin(),max.end(),less<T>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<T>());

        }else{
            if(min.size()>0&&num>min[0]){
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<T>());
                num = min[0];
                pop_heap(min.begin(),min.end(),greater<T>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<T>());
        }
    }

    T GetMedian(){
        int size = min.size()+max.size();
        if(size==0)
            throw exception("No NUMBER");
        T median = 0;
        if((size&1)==1)
            median = min[0];
        else
            median = (min[0]+max[0])/2;
        return median;
    }



};
#include<vector>
#include<deque>
using namespace std;

template<typename T> class QueueWithMax{
private:
    struct InternalData{
        T number;
        int index;
    };

    deque<InternalData> data;
    deque<InternalData> maximums;
    int currentIndex;

public:
    QueueWithMax():currentIndex(0){
    }

    void push_back(T number){
        while(!maximums.empty() && number >= maximums.back().number){   //此while循环是滑动窗口关键
            maximums.pop_back();        //双端队列：既保证小数可以从
        }

        InternalData internalData = {number, currentIndex};

        data.push_back(internalData);
        maximums.push_back(internalData);

        ++currentIndex;

    }

    void pop_front(){
        if(maximums.empty())
            throw new exception("queue is empty");

        if(maximums.front().index == data.front().index)        //如果date的front也是max的front，也要弹出
            maximums.pop_front();

        data.pop_front();
    }


    T max() const{
        if(maximums.empty())
            throw new exception("queue is empty");

        return maximums.front().number;
    
    }


};
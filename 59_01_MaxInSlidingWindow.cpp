#include<vector>
#include<deque>
using namespace std;

vector<int> maxInWindow(const vector<int>& num, unsigned int size){
    vector<int> maxInWindows;
    if(num.size()>=size && size>=1){
        deque<int> index;   //这个双端队列里存的是下标
                            //双端队列的front端永远保留窗口里最大的值的下标
                            //因为即可能在front弹出，也可能在back弹出，所以用双端队列

        //先处理前size个
        for(unsigned int i=0;i<size;++i){
            while(!index.empty() && num[i] >= num[index.back()])    //此while循环是滑动窗口关键
                index.pop_back();                               //当新进入的值比index里存的值大，则从back端删

            index.push_back(i);
        }

        //再处理剩下的
        for(unsigned int i=size;i<num.size();++i){
            
            maxInWindows.push_back(num[index.front()]);     //每一次更新最大值

            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();                                   //当新进入的值比index里存的值大，则从back端删

            if(!index.empty() && index.front() <= (int)(i-size))    //只有前面的（front的）index滑出窗口，即将front弹出
                index.pop_front();

            index.push_back(i); //这里存的是下标

        }

        maxInWindows.push_back(num[index.front()]);     //当跳出循环时，将上一次更新过的index队列取front存入max数组



    }

    return maxInWindows;

}
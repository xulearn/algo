#include<algorithm>

int getMaxValue_solution1(const int* values,int rows,int cols){
    if(values==nullptr || rows<=0||cols<=0){
        return 0;
    }
    int ** maxValues = new int*[rows];
    for(int i=0;i<rows;++i){
        maxValues[i] = new int[cols];
    }

    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            //保证从左上角0行0列的初值，以便后续计算maxValues二维数组
            int left = 0;
            int up = 0;

            if(i>0)
                up = maxValues[i-1][j];
            if(j>0)
                left = maxValues[i][j-1];

            //一边计算最大，一边更新二维数组
            maxValues[i][j] = std::max(left,up)+values[i*cols+j];
        }
    }
    int maxValue = maxValues[rows-1][cols-1];

    for(int i=0;i<rows;i++)
        delete[] maxValues[i];
    delete[] maxValues;

    return maxValue;


}


int getMaxValue_solution2(const int* values,int rows,int cols){
    if(values == nullptr || rows<=0 || cols<=0){
        return 0;
    }

    //数组只保存按列计算的最大值即可
    //随着行数向下迭代，只需保留最新一行各列的数据，之前行的数据可以被覆盖，以节省空间
    int* maxvalues= new int [cols];

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            int left = 0;
            int up = 0;

            if(i>0)     //当行数向下迭代时，本行的up标记，即为上一行maxvalues数组中各列的数据
                up = maxvalues[j];
            if(j>0)     //当列数向右迭代时，本列的left标记，即为前一列的maxvalues数组中的数据
                left = maxvalues[j-1];

            //用max判断是从上边过来还是从左边过来
            maxvalues[j] = std::max(up,left) + values[i*cols+j]; 

        }
    }

    int maxValue = maxvalues[cols-1];
    delete[] maxvalues;

    return maxValue;

}
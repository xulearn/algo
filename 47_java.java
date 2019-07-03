import java.util.LinkedList;
import java.util.Queue;

public class P233_MaxValueOfGifts{

    //递归方式
    public static int getMaxValue(int[][] data) {
        if(data.length ==0 || data[0].length == 0)
            return 0;
        int[][] dp = new int[2][data[0].length];

        int dpCurRowIndex = 0;
        int dpPreRowIndex = 0;
        for(int row = 0;row<data.length;row++){//按行遍历
            dpCurRowIndex = row&1;
            dpPreRowIndex = 1- dpCurRowIndex;

            for(int col=0;col<data[0].length;col++){//按列遍历
                if(col==0){                         //第一列不可能从左来，只能从上来
                    dp[dpCurRowIndex][col] = dp[dpPreRowIndex][col]+data[row][col];
                }else{                              
                    if(dp[dpPreRowIndex][col]>=dp[dpCurRowIndex][col-1])    //如果上面的大于左面的
                        dp[dpCurRowIndex] = dp[dpPreRowIndex][col] + data[row][col];    //从上面来
                    else
                        dp[dpCurRowIndex] = dp[dpCurRowIndex][col-1] + data[row][col];  //从左面来
                }
            }

        }

        return dp[(data.length-1)&1][data[0].length-1];

    }


    //广度搜索方式
    public static int getMaxvalue2(int[][] data){
        if(data.length==0||data[0].length==0)
            return 0;
        int maxRowIndex = data.length-1;
        int maxColIndex = data[0].length-1;
        Queue<Node> queue = new LinkedList<>();//********************* */

        queue.offer(new Node(0,0,data[0][0]));
        Node nodeCur = null;
        while(!(queue.peek().row == maxRowIndex && queue.peek().col == maxColIndex)){
            nodeCur = queue.poll();
            if(nodeCur.row!=maxRowIndex)
                queue.offer(new Node(nodeCur.row+1,nodeCur.col,nodeCur.sum+data[nodeCur.row+1][nodeCur.col]));
            if(nodeCur.col!=maxColIndex)
                queue.offer(new Node(nodeCur.row,node.col+1,nodeCur.sum+data[nodeCur.row][nodeCur.col+1]));

        }

        int maxSum = 0;
        int temp=0;
        while(!queue.isEmpty()){
            temp = queue.poll().sum;
            if(temp>maxSum)
                maxSum = temp;
        }
        return maxSum;


    }


    public static class Node{
        int row;
        int col;
        int sum;
        public Node(int r,int c,int s){
            this.row = r;
            this.col = c;
            this.sum = s;
        }
    }

    public static void main(String[] args) {
        int[][] data = {1,2,3};
        System.out.println();
    }



}
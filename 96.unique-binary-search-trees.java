/*
 * @lc app=leetcode id=96 lang=java
 *
 * [96] Unique Binary Search Trees
 */
class Solution {
    public int numTrees(int n) {
        int[] G = new int[n+1];

        G[0] = 1;   //空树和只有一个节点都只有一种情况
        G[1] = 1;
        
        //G(n): 长度为n的序列的不同二叉搜索树个数。
        //F(i,n): 以i为根的不同二叉搜索树个数(1<=i<=n)。
        //G(n) = F(i,n)(从i...n求和)
        //F(i,n) = G(i-1)*G(n-i) 笛卡儿积求组合数

        for(int i=2;i<=n;++i){      //i即为总结点数
            for(int j=1;j<=i;++j){  //j即为以j为root节点
                G[i] += G[j-1]*G[i-j];
            }
        }

        return G[n];
    }
}


import java.util.*;



import javafx.util.Pair;

/*
 * @lc app=leetcode id=104 lang=java
 *
 * [104] Maximum Depth of Binary Tree
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    // public int maxDepth(TreeNode root) {
    //     if(root==null){
    //         return 0;
    //     }else{
    //         int left = maxDepth(root.left);
    //         int right = maxDepth(root.right);
    //         return Math.max(left, right)+1;
    //     }
    // }

    public int maxDepth(TreeNode root) {
        Queue<Pair<TreeNode, Integer> > queue = new LinkedList<>();
        if(root != null){
            queue.add(new Pair(root,1));
        }
        int depth = 0;
        while(!queue.isEmpty()){
            Pair<TreeNode,Integer> current = queue.poll();
            root = current.getKey();
            int cur_depth = current.getValue();
            if(root!=null){
                depth = Math.max(depth, cur_depth);
                queue.offer(new Pair(root.left,cur_depth+1));
                queue.offer(new Pair(root.right,cur_depth+1));
            }

        }
        return depth;

    }

}


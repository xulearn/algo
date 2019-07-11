import java.util.*;


/*
 * @lc app=leetcode id=94 lang=java
 *
 * [94] Binary Tree Inorder Traversal
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
    public List<Integer> inorderTraversal(TreeNode root) {

        List<Integer> list = new ArrayList<Integer>();

        core(root,list);
        return list;

        
    }
    private void core(TreeNode root, List<Integer> list){
        if(root==null)
            return;
        if(root.left!=null)
            core(root.left, list);
        list.add(root.val);
        if(root.right!=null)
            core(root.right, list);
    }
}


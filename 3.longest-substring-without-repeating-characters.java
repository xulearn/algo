import java.util.*;


/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
    // public int lengthOfLongestSubstring(String s) {
    //     Set<Character> set = new HashSet<>();
    //     int[] index = new int[128];
    //     for(int i=0;i<128;++i){
    //         index[i] = -1;
    //     }
    //     int max = 0;
    //     for(int i=0;i<s.length();++i){
    //         char ch = s.charAt(i);
    //         if(!set.contains(ch)){
                
    //             set.add(ch);
    //             index[ch-' '] = i;
                
    //         }else{
                
    //             for(int j=0;j<128;++j){
    //                 if(index[j]<=index[ch-' ']&& index[j]>=0)
    //                     set.remove((char)(j+(int)(' ')));
    //             }
                
    //             set.add(ch);
    //             index[ch-' '] = i;
                
               
    //         }
    //         max = max>set.size()? max :set.size();
            
    //     }
    //     return max;
    // }

    public int lengthOfLongestSubstring(String s) {
        int ans = 0, left = 0, len = s.length();
        char[] ch = s.toCharArray();
        int[] last = new int[255];

        for(int i=0;i<255;++i){
            last[i] = -1;
        }

        for(int i=0;i<len;++i){
            if(last[ch[i]] >= left)
                left = last[ch[i]]+1;
            last[ch[i]] = i;

            ans = Math.max(ans, i-left+1);
        }
        return ans;
    }
}


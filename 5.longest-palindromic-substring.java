import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
    // public String longestPalindrome(String s) {
    //     if(s == null || s.length()< 1 ) 
    //         return "";
    //     int start = 0 , end = 0;
    //     for(int i = 0;i<s.length();++i){
    //         int len1 = expandAroundCenter(s,i,i);   //bab型：n个中心
    //         int len2 = expandAroundCenter(s,i,i+1);     //baab型：n-1个中心
    //         int len = Math.max(len1,len2);
    //         if(len > end-start){
    //             start = i - (len-1)/2;
    //             end = i+len/2;
    //         }
            
    //     }
    //     return s.substring(start, end+1);

    // }

    // private int expandAroundCenter(String s,int left,int right){
    //     int L = left, R = right;
    //     while(L >=0 && R<s.length() && s.charAt(L) == s.charAt(R)){
    //         L--;    //向两侧扩展
    //         R++;
    //     }
    //     return R-L-1;
    // }

    public String longestPalindrome(String s) {

        if(s == null || s.length()< 1 ) 
             return "";
        int len = s.length();
        char[] ch = s.toCharArray();
        boolean[][] f = new boolean[len][len];//标记是否为回文串

        int maxlen = 0, start=0;

        for(int i=0;i<len;++i){
            for(int j=0;j<len;++j){
                f[i][j] = false;
            }
        }

        for(int i=0;i<len;++i){
            f[i][i] = true;
            for(int j = 0;j<i;++j){
                if(j==i-1){
                    f[j][i] = (ch[j]==ch[i]);
                }else{
                    f[j][i] = (ch[j]==ch[i]) && f[j+1][i-1];
                }
                //f[j][i] = (ch[j]==ch[i] && (i-j<2 || f[j+1][i-1]));

                if(f[j][i]&&maxlen<i-j+1){
                    maxlen = i-j+1;
                    start = j;
                }
            }
            
        }
        

        if(maxlen==0)
            return String.valueOf(ch[0]);
        
        



        return s.substring(start, start+maxlen);

    }



}


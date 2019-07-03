import java.util.*;
public class Solution{

    public ArrayList<String> Permutation(String str){
        ArrayList<String> list = new ArrayList<String>();
        if(str!=null&&str.length()>0){
            Permutation(str.toCharArray(),0,list);
            Collections.sort(list);
        }
        return list;
    }

    private void Permutation(char[] chars,int i,ArrayList<String> list){
        if(i==chars.length-1){
            list.add(String.valueOf(chars));
        }else{
            Set<Character> charSet = new HashSet<Character>();
            for(int j=i;j<chars.length;++j){
                if(j==i || !charSet.contains(chars[j])){
                    charSet.add(chars[j]);
                    swap(chars,i,j);
                    Permutation(chars, i+1, list);
                    swap(chars,j,i);
                }
            }
        }
    }

    private void swap(char[] cs, int i, int j){
        char temp = cs[i];
        cs[i]=cs[j];
        cs[j] = temp;
    }

}

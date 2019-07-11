import java.util.*;

public class P199_StringCombination{
    public static List<char[]> combination(char[] strs){
        if(strs==null || strs.length ==0)
            return null;
        Arrays.sort(strs);
        List<char[]> ret = new LinkedList<>();
        combinationCore(strs,ret,new StringBuilder(),0);
        return ret;
    }

    public static void combinationCore(char[] strs,List<char[]> ret, StringBuilder stringBuilder,int cur){
        if(cur == strs.length){
            if(stringBuilder.length()>0)
                ret.add(stringBuilder.toString().toCharArray());
        }else if(cur+1 == strs.length || strs[cur]!=strs[cur+1]){
            combinationCore(strs, ret, stringBuilder.append(strs[cur]), cur+1);
            stringBuilder.deleteCharAt(stringBuilder.length()-1);
            combinationCore(strs, ret, stringBuilder, cur+1);
        }else{
            //先计算出重复字数
            int dumplicateStart = cur;
            while(cur!=strs.length && strs[dumplicateStart]==strs[cur]){
                stringBuilder.append(strs[cur]);
                cur++;
            }
            int newStart = cur;
            while(cur>=dumplicateStart){
                combinationCore(strs, ret, stringBuilder, newStart);
                if(cur!=dumplicateStart)
                    stringBuilder.deleteCharAt(stringBuilder.length()-1);
                cur--;
            }
        }


    }

    public static void main(String[] args) {
        char[] strs2 = {'a','a','b'};
        List<char[]> ret2 = combination(strs2);
        for(char[] item : ret2){
            for(int i=0;i<item.length;++i){
                System.out.println(item[i]);
            }
            System.out.println();
        }
    }

}
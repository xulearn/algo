import java.util.*;


public class solution{
    public char firstnotRep(String str){
        int[] hashTable = new int[256];
        for(int i=0;i<str.length();i++){
            hashTable[str.charAt(i)]++;
        }
        for(int i=0;i<str.length();i++){
            if(hashTable[str.charAt(i)]==1)
                return str.charAt(i);
        }
    }
}
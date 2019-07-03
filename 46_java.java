public class P231_TranslateNumbersToStrings{
    public static int getTranslationCount(int number){
        if(number<0)
            return 0;
        if(number==1)
            return 1;
        return getTranslationCount(Integer.toStrng(number));
    }

    public static int getTranslationCount(String number){
        int f1=0, f2=1, g=0;
        int temp;
        for(int i=number.length()-2;i>=0;i--){//从倒数第二位开始，f2为倒数第一位，f1为f2后一位
            /**
             * 单个字符之间相加时，系统会把其对应的ASCII值相加起来，并不会把字符变成字符串
             * 一个字符串和一个字符相加时，字符转化成字符串，两个字符串进行拼接操作
             * 字符串和多个字符之间用加号连接时，应多加注意字符的位置。
             *  *//
            if(Integer.parseInt(number.charAt(i)+""+number.charAt(i+1))<26)//加了个空串，使字符自动转为字符串
                g = 1;
            else
                g = 0;
            temp = f2;
            f2 = f2+g*f1;
            f1 = temp;
        }
        return f2;
    }

    public static void main(String[] args) {
        System.out.println(getTranslationCount(1234));
    }


}
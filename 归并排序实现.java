public class MergeSort{

    public static void mergeSort(int[] arr){
        sort(arr,0,arr.length-1);
    }

    //重点：先分割再排序
    public static void sort(int[] arr,int L,int R){
        if(L==R){
            return ;
        }
        
        int mid = L + ((R-L) >> 1);

        //递归分割排序左一半
        sort(arr,L,mid);
        //递归分割排序右一半
        sort(arr,mid+1,R);
    
        merge(arr,L,mid,R);

    }

    public static void merge(int[] arr,int L, int mid, int R){
        int[] temp = new int[R-L+1];
        int i = 0;
        int p1 = L;
        int p2 = mid+1;
        while(p1 <= mid && p2 <= R){
            temp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
            temp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];//可保证稳定性，即相同数字先复制左边的再复制右边的

        }
        while(p1<=mid){
            temp[i++] = arr[p1++];
        }
        while(p2<=R){
            temp[i++] = arr[p2++];
        }

        for(i= 0;i<temp.length;i++){
            arr[L+i] = temp[i];
        }

    }
}

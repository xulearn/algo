import java.util.*;
import structure.ListNode;

public class Solution{
    public static ListNode<Integer> findFirstCommonNode3(ListNode<Integer> head1,ListNode<Integer> head2){

        ListNode<Integer> node1 = head1;
        ListNode<Integer> node2 = head2;

        int size1 = 0;
        int size2 = 0;
        for(;node1!=null;node1 = node1.next){
            size1++;
        }
        for(;node2!=null;node2 = node2.next){
            size++;
        }

        node1 = head1;
        node2 = head2;

        while(size1>size2){
            node1 = node1.next;
            size1--;
        }

        while(size2>size1){
            node2 = node2.next;
            size2--;
        }
        while(node1!=null){
            if(node1!=node2){
                node1 = node1.next;
                node2 = node2.next;
            }else{
                break;
            }
        }
        return node1;


    }
}
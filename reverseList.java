

public class solution{

    public ListNode reverseList(ListNode head){
        ListNode prev = null;
        ListNode curr = head;
        while(curr!=null){
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
    
        return prev;
    
    }


    public ListNode reverseList2(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode p = reverseList2(head.next);   //递归返回后，p并没有变，每次返回的都是原来链表的最后一个，即反转后的头节点
        head.next.next = head;                  //这两行才是修改next的真正操作，上面一行只是保证反转后返回头节点
        head.next = null;
        return p;
    }


}



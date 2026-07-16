/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode list1first = list1;
        for(int i=1; i<= a-1 ;i++){
            list1first =list1first .next;
        }

        ListNode list2first = list1;
        for(int i =1;i <= b+1 ;i++){
            list2first = list2first .next;
        }

        list1first.next = list2;
        while(list1first.next != null){
            list1first = list1first.next;
        }

        list1first.next=list2first ;
        return list1;
    }
}

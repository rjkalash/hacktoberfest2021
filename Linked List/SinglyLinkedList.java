import java.util.Scanner;

public class SinglyLinkedList {
	private ListNode head;
	private static class ListNode {
		private int data;
		private ListNode next;
		public ListNode(int data) {
			this.data = data;
			this.next = null;
		}
	}	
	
	public void display() {
		ListNode current = head;
		while(current!=null) {
			System.out.print(current.data+" --> ");
			current = current.next;
		}
		System.out.println("Null\n");
	}
	
	public void length() {
		ListNode current = head;
		int count = 0;
		while(current!=null) {
			count++;
			current=current.next;
		}
		System.out.println("The length of the linked list is : " + count +"\n");
	}

	public void insert(int n) {
		ListNode node = new ListNode(n);
		node.next=null;
		ListNode current = head;
		while (1<2) {
			current = current.next;
			if(current.next==null) {
				 current.next = node;
				 break;
			}
		}
		display();
	}
	
	public static void main(String[] args) {
		 SinglyLinkedList sll = new SinglyLinkedList();
		 sll.head = new ListNode(10);
		 ListNode second = new ListNode(11);
		 ListNode third = new ListNode(12);
		 ListNode fourth = new ListNode(13);
		 sll.head.next = second;
		 second.next = third;
		 third.next = fourth;
		 
		 ListNode current = sll.head;
		 while(current!=null) {
			System.out.print(current.data+" --> "); 
			current = current.next;	 
		 }
		 System.out.println("Null\n");
		 System.out.println("printing using a function : ");
		 sll.display();
		 sll.length();
		 int n ;
		 Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		 sll.insert(n);
	}
}

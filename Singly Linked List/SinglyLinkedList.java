public class SinglyLinkedList {
    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node head;

    public SinglyLinkedList() {
        this.head = null;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public void insertAtHead(int data) {
        if (isEmpty()) {
            head = new Node(data);
            return;
        }
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public void insertAtTail(int data) {
        if (isEmpty()) {
            head = new Node(data);
            return;
        }
        Node newNode = new Node(data);
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void deleteAtHead() {
        if (isEmpty()) {
            System.out.println("Error...LinkedList is Empty.");
            return;
        }
        head = head.next;
    }

    public void deleteAtTail() {
        if (isEmpty()) {
            System.out.println("Error...LinkedList is Empty.");
            return;
        }
        if (head.next == null) {
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Empty...");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + (temp.next != null ? " -> " : "."));
            temp = temp.next;
        }
        System.out.println();
    }

    public void deleteLinkedList() {
        head = null;
    }

    public boolean contains(int data) {
        if (isEmpty()) {
            return false;
        }
        Node temp = head;
        while (temp != null) {
            if (temp.data == data) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    public int getSize() {
        Node temp = head;
        int size = 0;
        while (temp != null) {
            temp = temp.next;
            size++;
        }
        return size;
    }
}

public class StackByLinkedList {
    static class Node {
        int data;
        Node next;

        public Node() {
            data = 0;
            next = null;
        }

        public Node(int data) {
            this.data = data;
            next = null;
        }
    }
    
    Node top;
    
    public StackByLinkedList() {
        top = null;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void peek() {
        if (isEmpty()) {
            System.out.println("Stack is Empty!");
        } else {
            System.out.println(top.data);
        }
    }

    public void pop() {
        if (!isEmpty()) {
            System.out.println(top.data);
            top = top.next;
        } else {
            System.out.println("Cannot be popped!");
        }
    }

    public void push(int data) {
        Node newNode = new Node(data);
        newNode.next = top;
        top = newNode;
    }

    public void display() {
        Node temp = top;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}

package assignment;

import java.util.logging.Level;
import java.util.logging.Logger;

public class PriorityQueueApp {

    public static void main(String[] args) {

        PriorityQueue x = new PriorityQueue();
        x.enqueue("Lak", 2.63);
        x.enqueue("Sam", 3.5);
        x.enqueue("Mursit", 1.2);
        x.enqueue("Ran", 4.9);
        x.enqueue("Dock", 1.2);
        x.enqueue("Anan", 0.98);
        x.enqueue("Yello", 2);

        x.display();

        System.out.println();

        try {
            System.out.println(x.dequeue() + " ,student is removed from the list.");
        } catch (Exception e) {
            Logger.getLogger(PriorityQueueApp.class.getName()).log(Level.SEVERE, null, e);
        }
        System.out.println();
        x.display();
    }

}

class Student {

    String studentName;
    double gpa;

    Student(String studentName, double gpa) {
        //fill the body

        this.studentName = studentName;
        this.gpa = gpa;
    }
}

class Node {

    Student s;
    Node next;

    Node(Student s) {
        this.s = s;
        this.next = null;
    }
}

class PriorityQueue {

    private Node head;
    private Node tail;

    public PriorityQueue() {
        this.head = null;
        this.tail = null;
    }

    public void enqueue(String studentName, double gpa) {
        if (head == null) {
            Student student = new Student(studentName, gpa);
            head = new Node(student);
            tail = head;
            return;
        }

        Student student = new Student(studentName, gpa);
        head = insertNewNode(student, head);
    }

    private Node insertNewNode(Student student, Node currentNode) {
        //class to inser new node

        if (student.gpa < currentNode.s.gpa) {
            Node newNode = new Node(student);
            newNode.next = currentNode;
            return newNode;
        }

        if (currentNode.next == null) {
            currentNode.next = new Node(student);
            this.tail = currentNode.next;
        } else {
            currentNode.next = insertNewNode(student, currentNode.next);
        }

        return currentNode;
    }

    public String dequeue() throws Exception {
        /*remove the node of the front student and return the name of the student*/

        if (this.head == null) {
            throw new Exception("Queue is Empty");
        }
        String removedData = this.head.s.studentName;
        this.head = this.head.next;
        return removedData;
    }

    public String peek() throws Exception {
        //return the name of the front student

        return this.head.s.studentName;
    }

    public void display() {
        //display all the student names in the queue

        System.out.println("Studets list with GPA :");
        Node currentNode = this.head;
        while (currentNode != null) {
            System.out.println(currentNode.s.gpa + "  -  " + currentNode.s.studentName);
            currentNode = currentNode.next;
        }
    }

}

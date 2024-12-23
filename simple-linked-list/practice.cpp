#include "simple_linked_list.cpp"
#include <iostream>

// a singly linked list made by Chatgpt
struct Node {
  int data;   // Data stored in the node
  Node *next; // Pointer to the next node

  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
  // Constructor
  LinkedList() : head(nullptr) {}

  // Destructor to clean up memory
  ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }

  // Add a node at the beginning
  void pushFront(int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  // Add a node at the end
  void pushBack(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
  }

  // Delete the first node
  void popFront() {
    if (head == nullptr) {
      std::cout << "List is empty!" << std::endl;
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  void display() {
    Node *current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }

private:
  Node *head;
};

int main() {
  LinkedList List;

  List.pushBack(10);
  List.pushBack(20);
  List.pushBack(30);

  List.display();
}

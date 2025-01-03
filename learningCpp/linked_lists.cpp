
#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
public:
  SinglyLinkedList() : head(nullptr) {}

  ~SinglyLinkedList() {
    Node *current = head;

    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }

  void pushFront(int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  void display() {

    Node *current = head;
    while (current != nullptr) {
      current = current->next;
      std::cout << current->data;
    }
    std::cout << "nullptr" << "\n";
  }

private:
  Node *head;
};

int main() {
  SinglyLinkedList List;

  List.pushFront(10);
  List.display();
}

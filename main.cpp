#include <iostream>
#include <string>

struct SneakerNode {
  std::string brand;
  std::string model;
  int size;
  int quantity;
  SneakerNode* next;
};

class SneakerInventory {
 private:
  SneakerNode* head;
  SneakerNode* tail;
  int length;

 public:
  SneakerInventory() {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }

  void insert() {
    std::string brand;
    std::string model;
    int size;
    int quantity;
    std::cout << "Enter brand: ";
    std::cin >> brand;
    std::cout << "Enter model: ";
    std::cin >> model;
    std::cout << "Enter size: ";
    std::cin >> size;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    SneakerNode* new_node = new SneakerNode();
    new_node->brand = brand;
    new_node->model = model;
    new_node->size = size;
    new_node->quantity = quantity;
    new_node->next = nullptr;

    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    length++;
  }

  void remove() {
    std::string brand;
    std::string model;
    int size;
    std::cout << "Enter brand: ";
    std::cin >> brand;
    std::cout << "Enter model: ";
    std::cin >> model;
    std::cout << "Enter size: ";
    std::cin >> size;

    SneakerNode* current_node = head;
    SneakerNode* previous_node = nullptr;
    while (current_node != nullptr) {
      if (current_node->brand == brand && current_node->model == model && current_node->size == size) {
        if (previous_node == nullptr) {
          head = current_node->next;
        } else {
          previous_node->next = current_node->next;
        }
        if (current_node == tail) {
          tail = previous_node;
        }
        delete current_node;
        length--;
        break;
      }
      previous_node = current_node;
      current_node = current_node->next;
    }
  }

  void display() {
    SneakerNode* current_node = head;
    while (current_node != nullptr) {
      std::cout << "Brand: " << current_node->brand << ", Model: " << current_node->model
                << ", Size: " << current_node->size << ", Quantity: " << current_node->quantity << std::endl;
      current_node = current_node->next;
    }
  }
};
int main() {
  SneakerInventory inventory;

  while (true) {
    std::cout << "Enter 1 to insert, 2 to remove, 3 to display, or 0 to exit: ";
    int input;
    std::cin >> input;
    if (input == 0) {
      break;
    }
    if (input == 1) {
      inventory.insert();
    } else if (input == 2) {
      inventory.remove();
    } else if (input == 3) {
      inventory.display();
    } else {
      std::cout << "Invalid input" << std::endl;
    }
  }

  return 0;
}

#include <iostream>

class Stack{
  static const int capacity = 20;
  int vec[capacity];
  int size_ = 0;
public:
  Stack() = default;
  Stack(int new_element) {
    push(new_element);
  }
  bool empty() const {
    return size_ == 0;
  }
  bool push(int new_element) {
    if (size_ >= capacity) 
      return false;
    vec[size_++] = new_element;
    return true;
  }
  bool pop() {
    if (empty())
      return false;
    size_--;
    return true;
  }
  int top() {
    return vec[size_ - 1];
  }
  void print() const {
    for (int i = 0; i < size_; i++) {
      std::cout << vec[i] << "-> ";
    }
    std::cout << std::endl;
  }
};

int main() {
  Stack s1;
  s1.push(3);
  s1.push(4);
  std::cout << "Top element is " << s1.top() << std::endl;
  s1.print();
  s1.pop();
  s1.print();
  s1.pop();
  std::cout << "Stack is empty: " << s1.empty() << std::endl;
  Stack s2(5);
  s2.print();
}

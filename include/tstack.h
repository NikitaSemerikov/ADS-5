// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
  T data[size];
  int topIndex;

 public:
  TStack() : topIndex(-1) {}

  bool isEmpty() const {
    return topIndex < 0;
  }

  bool isFull() const {
    return topIndex >= size - 1;
  }

  void put(const T& val) {
    if (!isFull()) {
      data[++topIndex] = val;
    }
  }

  T get() {
    return data[topIndex--];
  }

  T see() const {
    return data[topIndex];
  }

  int getSize() const {
    return topIndex + 1;
  }

  // Обёртки для совместимости с чужим кодом
  void push(const T& val) {
    put(val);
  }

  T pop() {
    return get();
  }

  T top() const {
    return see();
  }

  bool empty() const {
    return isEmpty();
  }
};

#endif  // INCLUDE_TSTACK_H_

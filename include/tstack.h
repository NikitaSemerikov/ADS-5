// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
  static const int kSize = size;
  T data[kSize];
  int topIndex;

 public:
  TStack() : topIndex(-1) {}

  bool isEmpty() const {
    return topIndex < 0;
  }

  bool isFull() const {
    return topIndex >= kSize - 1;
  }

  void put(const T& val) {
    if (!isFull()) {
      ++topIndex;
      data[topIndex] = val;
    }
  }

  T get() {
    if (isEmpty()) {
      return T();
    }
    T val = data[topIndex];
    --topIndex;
    return val;
  }

  T see() const {
    if (isEmpty()) {
      return T();
    }
    return data[topIndex];
  }

  // Обёртки для совместимости с тестами
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

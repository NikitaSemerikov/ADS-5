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
};

#endif  // INCLUDE_TSTACK_H_

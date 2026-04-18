// Copyright 2025 NNTU-CS
#include <string>
#include <cctype>
#include "tstack.h"

int priority(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

int apply(int a, int b, char op) {
  switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
  }
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 256> st;
  std::string out;

  for (size_t i = 0; i < inf.size(); ++i) {
    char c = inf[i];

    if (std::isdigit(c)) {
      while (i < inf.size() && std::isdigit(inf[i])) {
        out += inf[i++];
      }
      out += ' ';
      --i;
    } else if (c == '(') {
      st.put(c);
    } else if (c == ')') {
      while (!st.isEmpty() && st.see() != '(') {
        out += st.get();
        out += ' ';
      }
      st.get();  // remove '('
    } else if (!std::isspace(c)) {
      while (!st.isEmpty() && priority(st.see()) >= priority(c)) {
        out += st.get();
        out += ' ';
      }
      st.put(c);
    }
  }

  while (!st.isEmpty()) {
    out += st.get();
    out += ' ';
  }

  return out;
}

int eval(const std::string& post) {
  TStack<int, 256> st;

  for (size_t i = 0; i < post.size(); ++i) {
    if (std::isdigit(post[i])) {
      int x = 0;
      while (i < post.size() && std::isdigit(post[i])) {
        x = x * 10 + (post[i] - '0');
        ++i;
      }
      st.put(x);
      --i;
    } else if (!std::isspace(post[i])) {
      int b = st.get();
      int a = st.get();
      st.put(apply(a, b, post[i]));
    }
  }

  return st.get();
}

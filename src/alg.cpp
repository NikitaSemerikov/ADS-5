// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include <cctype>
#include <stdexcept>
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
    case '/':
      if (b == 0) throw std::runtime_error("division by zero");
      return a / b;
  }
  throw std::runtime_error("bad operator");
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
      st.push(c);
    } else if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        out += st.pop();
        out += ' ';
      }
      st.pop();
    } else if (!std::isspace(c)) {
      while (!st.empty() && priority(st.top()) >= priority(c)) {
        out += st.pop();
        out += ' ';
      }
      st.push(c);
    }
  }

  while (!st.empty()) {
    out += st.pop();
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
      st.push(x);
      --i;
    } else if (!std::isspace(post[i])) {
      int b = st.pop();
      int a = st.pop();
      st.push(apply(a, b, post[i]));
    }
  }

  return st.pop();
}

#include<bits/stdc++.h>

using namespace std;

//precedence of operators
int precedence(char ch) {
  if (ch == '^')
    return 3;
  else if (ch == '/' || ch == '*')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return -1;
}

string infixToPostfix(string s) {
  stack < char > st;
  string postfix_exp;

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    // // If the input character is
    // an operand, add it to the postfix output string. 
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
      postfix_exp += ch;

    // // If the input character is an
    // '(', push it to the stack.
    else if (ch == '(')
      st.push('(');

    // If the input character is an ')',
    //pop and output string from the stack
    // until an '(' is encountered.
    else if (ch == ')') {
      while (st.top() != '(') {
        postfix_exp += st.top();
        st.pop();
      }
      st.pop();
    }

    //If the character is an operator
    else {
      while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
        postfix_exp += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    postfix_exp += st.top();
    st.pop();
  }

  return postfix_exp;
}


string inToPre(string infix) {
  string prefix;
  reverse(infix.begin(), infix.end()); //reverse the infix expression
  string::iterator it;

  for (it = infix.begin(); it != infix.end(); it++) { //reverse the parenthesis after reverse
    if ( * it == '(')
      *
      it = ')';
    else if ( * it == ')')
      *
      it = '(';
  }

  prefix = infixToPostfix(infix); //convert new reversed infix to postfix form.
  reverse(prefix.begin(), prefix.end()); //again reverse the result to get final prefix form
  return prefix;
}

int main() {
  string infix_expression = "A*B-(C+D)+E";
  cout << "Ahmad Kubagus Subkhi\nC2C021064" << endl;
  cout << "Infix: " << infix_expression << endl;
  cout << "Prefix Form Is: " << inToPre(infix_expression) << endl;
  cout << "The postfix string is: " << infixToPostfix(infix_expression);
  return 0;
}

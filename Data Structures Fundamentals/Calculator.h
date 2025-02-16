#include <iostream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <cmath>
#include "Stack.h"

using namespace std;

class CalculatorFunction{
    public:
        // evaluate_rpn function to evaluate Reverse Polish Notation (RPN)
        int evaluate_rpn(const string& expression) {
            MyStackArrayType stack;
            istringstream tokens(expression);       // Convert the expression int a steam of tokens
            string token;

            // Read the tokens one by one
            while (tokens >> token) {
                // If the token is a number (including negative numbers), push it onto the stack
                if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1 && isdigit(token[1]))) {
                    stack.push(stoi(token));        // Convert the token to an integer and push onto the stack
                } else {
                    // Otherwise, the token is an operator, so pop two operands from the stack
                    int b = stack.top();        // Second operand
                    stack.pop();
                    int a = stack.top();        // First operand
                    stack.pop();

                    // Perform the operation based on the operator
                    switch (token[0]) {
                        case '+':
                            stack.push(a + b);
                            break;
                        case '-':
                            stack.push(a - b);
                            break;
                        case '*':
                            stack.push(a * b);
                            break;
                        case '/':
                            stack.push(a / b);
                            break;
                        case '^':  // Handle exponentiation
                            stack.push(pow(a, b));
                            break;
                        default:
                            throw invalid_argument("Invalid Operator\n");
                    }
                }
            }
            return stack.top();         // Return the final result from the stack
        }

        // Precedence of operators
        int precedence(char op) {
            if (op == '+' || op == '-') {
                return 1;           // Lowest precedence
            }
            if (op == '*' || op == '/') {
                return 2;           // Higher precedence
            }
            if (op == '^') {
                return 3;           // Higher precedence for exponentiation
            }
            return 0;
        }

        // Apply the operator to two operands
        int apply_operator(int a, int b, char op) {
            switch (op) {
                case '+':               // Handle Addition
                    return a + b;
                case '-':               // Handle Subtraction
                    return a - b;
                case '*':               // Handle Multiplication
                    return a * b;
                case '/':               // Handle Division
                    return a / b;
                case '^':               // Handle exponentiation
                    return pow(a, b);
                default:
                    throw invalid_argument("Invalid Operator\n");
            }
        }

        // evaluate_infix method to evaluate Infix Expression
        int evaluate_infix(const string& expression) {
            MyStackArrayType values;        // Stack to store operands
            MyStackArrayType ops;           // Stack to store operators
            size_t i = 0;

            while (i < expression.length()) {
                // Skip whitespace characters
                if (isspace(expression[i])) {
                    i++;
                    continue;
                }

                // If a number is encountered (handling negative numbers as well)
                if (isdigit(expression[i]) || (expression[i] == '-' && i + 1 < expression.length() && isdigit(expression[i + 1]))) {
                    int value = 0;
                    bool is_negative = (expression[i] == '-');
                    if (is_negative) {
                        i++;  // Move past the negative sign
                    }
                    // Convert the number string into an integer
                    while (i < expression.length() && isdigit(expression[i])) {
                        value = (value * 10) + (expression[i] - '0');
                        i++;
                    }
                    if (is_negative) {
                        value = -value;         // Apply the negative sign
                    }
                    values.push(value);         // Push the value onto the values stack
                } 
                // If an opening parenthesis is encountered, push it onto the operators stack
                else if (expression[i] == '(') {
                    ops.push(expression[i]);
                    i++;
                } 
                // If a closing parenthesis is encountered, solve the expression inside the parentheses
                else if (expression[i] == ')') {
                    while (!ops.is_empty() && ops.top() != '(') {
                        int value2 = values.top(); 
                        values.pop();
                        int value1 = values.top(); 
                        values.pop();
                        char op = ops.top(); 
                        ops.pop();
                        values.push(apply_operator(value1, value2, op));
                    }
                    ops.pop(); // Remove '('
                    i++;
                } 
                // If an operator is encountered
                else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
                    while (!ops.is_empty() && precedence(ops.top()) >= precedence(expression[i])) {
                        int value2 = values.top(); 
                        values.pop();
                        int value1 = values.top(); 
                        values.pop();
                        char op = ops.top(); 
                        ops.pop();
                        values.push(apply_operator(value1, value2, op));
                    }
                    ops.push(expression[i]);        // Push the current operator onto the stack
                    i++;
                } 
                else {
                    throw invalid_argument("Invalid operator encountered: " + string(1, expression[i]));
                }
            }

            // Process any remaining operators in the stack
            while (!ops.is_empty()) {
                int value2 = values.top(); 
                values.pop();
                int value1 = values.top(); 
                values.pop();
                char op = ops.top(); 
                ops.pop();
                values.push(apply_operator(value1, value2, op));
            }

            return values.top();        // Return the final result
        }
};
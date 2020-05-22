/*
    Title:      Evaluator.cpp - Postfix Evaluator
    Purpose:    Evaluate input of postfix equation
    Author:     Rami Isaac
    Date:       May 20, 2020
*/

#include "evaluator.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

double Evaluate(const string& postfix, bool& error);         // Evaluate postfix equation
double Calculate(const string& input, stack<double>& stack); // Preform calculation

bool IsOperator(const string& input);                        // True if string element is an operator
bool IsOperand(const string& input);                         // True if char c is a number
    bool IsDigit(char c);                                    // True if char c is 0-9

/*
 * Evaluate() Postfix string
     * Evaluates a postfix string by reading individual elements
     * into a vector. The vector is then traversed from position 0
     * and the following operations occur:
     *      0. String elements are pushed individually to vector
     *      1. If vector element [i] is a number, push to stack
     *      2. If vector element [i] is an operator, apply operator to
     *      top two stack elements (LIFO), pop() those two elements,
     *      then push the result to the top of the stack.
 * @param const string& | String containing postfix equation
 * @param bool& | Error bool
 * @returns Double containing result if no error occurs
 */
double Evaluate(const string& postfix, bool& error){

    stack<double> stack; // Stack of doubles, holds number elements
    vector<string> list; // Vector of strings, holds all elements

    // Push string elements to vector
    string element;
    stringstream iss(postfix);
    while (iss >> element) { list.push_back(element); }

    double result, num; // Holds final result, number element

    // Iterate through vector of elements
    for (int i = 0; i < list.size(); i++) {

        stringstream  temp(list.at(i));     // Read individual element

        if(i < 2){  // First two elements in postfix can only be numbers
            // If element [0] or [1] is a number, push to stack
            if(IsOperand(list.at(i))){
                    temp >> num;
                    stack.push(num);
            // All other inputs results in an error
            } else {
                error = true;
                return -1;
            }
        // For all elements [>1] (3rd element and forward)
        } else {
            // If element [i] is a number
            if(IsOperand(list.at(i))){
                temp >> num;
                stack.push(num);
            // If element [i] is an operator
            } else if (IsOperator(list.at(i))) {
                result = Calculate(list.at(i), stack);
            // If element is anything else, error
            } else {
                error = true;
                return -1;
            }
        }
    }
    error = false; // Default, bool error is false
    return result; // Return result of type double
}

/*
 * Calculate(const string&, stack<double)
    * 1. String parameter determines operation
    * 2. Operation is applied to top two elements on stack
 * Operators:
    * Add [+] OR Subtract [-] OR Multiply [*] OR Divide [/] OR Pow [^]
 * @param const string& | String of operator
 * @param stack<double> | Stack of doubles
 * @returns result of type double
 */
double Calculate(const string& input, stack<double>& stack) {

    // Stores top two stack elements and their result
    double lVal, rVal, result;

    rVal = stack.top(); // Retrieve top element from stack
    stack.pop();        // Remove top element from stack

    lVal = stack.top(); // Retrieve top element from stack
    stack.pop();        // Remove top element from stack

    if (input == "+") {                 // Add
        result = lVal + rVal;
    } else if (input == "-") {          // Subtract
        result = lVal - rVal;
    } else if (input == "*") {          // Multiply
        result = lVal * rVal;
    } else if (input == "/") {          // Divide
        result = lVal / rVal;
    } else if (input == "^") {          // Pow
        result = pow(lVal, rVal);
    }
    stack.push(result); // Push result of operation to top of stack
    return result;      // Return result of type double
}

/*
 * IsOperator(const string&)
    * Ensures that string input is a valid operator, else, returns false
 * Operators:
    * Add [+] OR Subtract [-] OR Multiply [*] OR Divide [/] OR Pow [^]
 * @param const string& | String of operator
 * @returns true if string input is a valid operator, false if not
 */
bool IsOperator(const string& input){
    string ops[] = {"+", "-", "*", "/", "^"};
    for(int i = 0; i < 5; i++){
        if(input == ops[i])
            return true;
    } return false;
}

/*
 * IsOperand(const string&)
    * Verifies that string input is an operand, checks the following:
        *    a. If negative, negative sign can only appear at
        *       the beginning of string (Ex: -120)
        *    b. Negative sign can only occur once in string
        *    b. Is not an operator
 * @param const string& | String of operand
 * @returns true if string is holds an operand, else, false
 */
bool IsOperand(const string& input) {
    if(IsOperator(input) || input.length() == 0)
        return false; // False if input is an operator or string length == 0

    // Iterate through string, char by char
    for (int i = 0; i < input.length(); i++){

        char c = input[i]; // c temporarily holds char at input[i]

        if(i == 0){ // At input[0], c can only be a digit or a negative sign
            if(!IsDigit(c) && c!= '-')
                return false;
        } else {    // Checks input[i] characters at i > 0

            // Decimal can only occur once
            bool decimalPresent = false; // No decimal present by default
            if(c == '.'){                // If c is a decimal
                if(decimalPresent)       // Check if decimal has already occurred
                    return false;          // -> Return false
                else                     // If first time decimal occurs
                    decimalPresent = true; // -> Record occurrence

            // If not a decimal, c can only be a digit
            } else if(!IsDigit(c))
                return false;
        }
    }
    return true; // If no errors occurred and input is a valid operand
}

/*
 * IsDigit(const string&)
    * Helper function for IsOperand()
    * Verifies that character c is a valid number
 * @param char | Character from string of operand element
 * @returns true if c is >= 0 && <= 9, else, false
 */
bool IsDigit(char c) {
    return c >= '0' && c <= '9';
}
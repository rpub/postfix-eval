# Evaluating Postfix Operations
This lab concerns the coding of a program that evaluates
postfix expressions using a stack.

Additionally, this lab will help you understand the use of STL
classes as the [`stack`](http://www.cplusplus.com/reference/stack/stack/)
class and possibly the [`queue`](http://www.cplusplus.com/reference/queue/queue/) class.

## Design

Basically the design is a function with the following prototype: `double Evaluate(const string& postfix, bool& error);`.

The function takes in a parameter `postfix` that contains a string with a postfix arithmetic
expression. The expression will have only integers (each can have several digits)
and it can have the following operators: +, -, *, / and ^. The other parameter is used
to check whether the postfix operation was correctly formatted, therefore if `Evaluate` finds
an error, it must set the `error` variable to `true` and return `-1`. If everything goes well
the function should set `error` to `false` and return the result of the expression.

### Examples

Postfix Expression | Infix Expression | Result
-------------------|------------------|-------
`2 5 +`            | `2 + 5`          | `7`
`4 5 * 2 +`        | `4 * 5 + 2`      | `22`
`5 1 + 3 *`        | `(5 + 1) * 3`    | `18`
`1 4 + 10 4 - *`   | `(1  + 4) * (10 - 4)` | `30`
`3 2 ^ 5 -`        | `3 ^ 2 - 5`      | `4`


## What is given?
You will be given the following four files:
* `makefile` this file will help you compile your program, you will only need to run `make`. **DO NOT MODIFY THIS FILE**
* `main.cpp` this file will hold the main function, it contains the unit tests, the output will
   tell you how much of the unit tests you passed. **DO NOT MODIFY THIS FILE**
* `evaluator.h` this file is the header file for the module you need to make. **DO NOT MODIFY THIS FILE**
* `evaluator.cpp` this file is where you will work, you need to define the function `Evaluate`. You may declare and define additional functions if you want. You **must** use a `stack` class from the C++ STL to evaluate the postfix expression.


## What is expected?
- Your code ***must*** compile.
- Your grade will be *almost* the percentage of your passed unit tests.
- Your code needs to show good programming practices: indentation, meaningful variable names, identifiers convention (CamelCase for functions, camelCase for variables, _camelCase for data members, SNAKE_CASE for constants), header comments, correct file names, etc. Failure to
code appropriately will result in strong points penalization.

## Extra Credit
You may get extra credit if your Evaluate function can also work with Real numbers, just consider decimal point notation and no scientific format notation. For example, your Evaluate function can take and calculate `2.7172 0.5 ^`.

## Sample Output

This is a sample output in case you do all the extra credit:
```
$ make
g++ -c main.cpp -std=c++11 -Wall
g++ -c evaluator.cpp -std=c++11 -Wall
g++ -c token.cpp -std=c++11 -Wall
g++ main.o evaluator.o token.o -o postfix -std=c++11 -Wall
$ ./postfix
Normal Tests:
= = = = = = = = = = = = = = = = = = = = = = = = = = = = =
                       2 14 + 1 5 + * =    96	9.09
                            2 5 ^ 5 + = 37.00	18.18
 * * * * There was an error  * * * * 	4 + 5	27.27
                   2 3 ^ 3 * 21 3 / + = 31.00	36.36
                               15 2 / =  7.50	45.45
                     100 90 - 5 3 - / =  5.00	54.55
           10 5 - 2 * 4 3 ^ 2 3 / / + = 106.00	63.64
 * * * * There was an error  * * * * 	10 5+	72.73
 * * * * There was an error  * * * * 	some	81.82
          2 2 + 4 + 5 * 30 - 5 * 25 / =  2.00	90.91
                       4 5 10 3 - * + = 39.00	100.00
Unit Tests Grade: 100.00
Extra Credit Tests:
= = = = = = = = = = = = = = = = = = = = = = = = = = = = =
                              2.5 2 * =  5.00	33.33
             2.7172 3.0 ^ 3.1415954 / =  6.39	66.67
                1.2 5 * 0.75 0.75 + / =  4.00	100.00
Extra Credit Unit Tests Grade: 30.00
= = = = = = = = = = = = = = = = = = = = = = = = = = = = =


Unit Tests Final Grade:
Normal Test:  100.00
Extra Credit:  30.00

Total:        130.00


```

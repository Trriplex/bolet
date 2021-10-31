# Bolet
A stack-based esolang. Not a serious project.

## Hello world
Bolet uses the postfix notation, like most stack-based languages. <br>
In order to make a hello world, you need to type the following: <br>
`> "Hello world !" print` <br>

First, the string `"Hello world !"` is added to the stack, and then, it's printed.

## Basic arithmetic
`> 2 3 + .` prints 5. `+` pops 2 and 3 out of the stack, and then pushes 5. `.`, like in forth, pops and prints the top of the stack.<br>

## Compiling
`gcc -o main main.c`

## Reference
### `+`, `-`, `*`, `/`
Pops two numbers out of the stack, compute an operation and pushes the result to stack
### `.`
Pops and prints the top of the stack. It only works with numbers
### `..`
Pops and prints the top of the stack. It only works with strings
### `swp`
Swaps the first two elements of the stack
### `print`
Prints the string on the top of the stack without popping it.
### `printn`
Prints the number on the top of the stack without popping it.

# Bolet 🍄
A stack-based esolang. Not a serious project.

## Hello world
Bolet uses the postfix notation, like most stack-based languages. <br>
In order to make a hello world, you need to type the following: <br>
`> "Hello world !" print` <br>

First, the string `"Hello world !"` is added to the stack, and then, it's printed.

## Basic arithmetic
`> 2 3 + .` prints 5. `+` pops 2 and 3 out of the stack, and then pushes 5. `.`, like in forth, pops and prints the top of the stack.<br>

## Compiling
Just run `make`.

## Exiting the REPL
Type `^D` (`ctrl + D` or `EOF`)

## Methods reference
### `+`, `-`, `*`, `/`, `%'
Basic arithmetic operations. It pops two numbers out of the stack and pushes the result
### `.`
Pops and prints the top of the stack. It only works with numbers
### `..`
Pops and prints the top of the stack. It only works with strings
### `print`
Prints the top item without popping it
### `printn`
Prints the top item without popping it
### `swp`
Swaps the first two elements of the stack
### `dup`
Duplicates the top of the stack
### `drp`
Pops the top of the stack without printing it
### `nip`
Pops the second item of the stack without printing it
### `over`
Duplicates the second item to the top
### `>r`
Puts the value into a temporary place
### `r>`
Retrieve the temporary value

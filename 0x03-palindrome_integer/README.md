# Palindrome Integer

## Synopsis
This function will check if a number is a palindrome.

## Compilation
`gcc -Wall -Werror -Wextra -pedantic main.c is_palindrome.c -o palindrome`

## Usage
* `is_palindrome(101)` -> True
* `is_palindrome(10)` -> False

## Helper Functions
```
/**
 * i_len - gets the length of an int
 * @n: integer
 * Return: length of the integer
 */
unsigned long i_len(unsigned long n)

/**
 * i_pow - calculates x to the power of y
 * @x: integer
 * @y: integer
 * Return: x^y
 */
unsigned long i_pow(unsigned long x, unsigned long y)

```

## Authors
* Jared Heck

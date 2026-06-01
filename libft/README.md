*This project has been created as part of the 42 curriculum by zscekic.*

## Description
The libft library consists of recoded standard functions in C. The goal was to implement the functions and gain deeper understanding of how they work, as well as learning how to use them effectively. Libft includes string manipulation, memory allocation, and linked list management functions.

### Library Overview
The library is divided into three parts:
<details>

<summary><b>Part 1: standard Libc functions </b></summary>

- `ft_isalpha` - Checks if the character is alphabetic (A-Z or a-z).
- `ft_isdigit` - Checks if the character is a digit (0-9).
- `ft_isalnum` - Checks if the character is alphanumeric (either a letter or a digit).
- `ft_isascii` - Checks if the character is a member of the standard ASCII set.
- `ft_isprint` - Checks if the character is printable (including space).
- `ft_strlen` - Calculates the length of a string.
- `ft_memset` - Fills a memory block with a specific constant byte.
- `ft_bzero` - Sets all bytes in a memory area to zero.
- `ft_memcpy` - Copies a memory area to another, behaviour is undefined if areas overlap
- `ft_memmove` - Safely copies memory even if the source and destination overlap.
- `ft_strlcpy` - Size-bounded string copying with guaranteed null-termination.
- `ft_strlcat` - Size-bounded string concatenation with guaranteed null-termination.
- `ft_toupper` - Converts a lowercase letter to uppercase.
- `ft_tolower` - Converts an uppercase letter to lowercase.
- `ft_strchr`- Locates the first occurrence of a character in a string.
- `ft_strrchr` - Locates the last occurrence of a character in a string.
- `ft_strncmp` - Compares two strings up to a specified number of characters.
- `ft_memchr` - Searches for a specific byte within a memory block.
- `ft_memcmp` - Compares two memory blocks byte by byte.
- `ft_strnstr` - Locates a substring within a string, limited by length.
- `ft_atoi` - Converts a string representation of an integer into an actual int.
- `ft_calloc` - Allocates zero-initialized memory for an array.
- `ft_strdup` - Creates a duplicate of a string by allocating the new memory.

</details>

<details>

<summary><b>Part 2: additional functions </b></summary>

- `ft_substr` - Extracts a specific substring from a string starting at a given index.
- `ft_strjoin` - Concatenates two strings into a newly allocated third string.
- `ft_strtrim` - Removes specified characters from the beginning and end of a string.
- `ft_split` - Splits a string into an array of strings using a specific character as a delimiter.
- `ft_itoa` - Converts an integer value into a null-terminated string.
- `ft_strmapi` - Creates a new string by applying a function to each character of an existing string.
- `ft_striteri` - Applies a function to each character of a string by passing its index and address.
- `ft_putchar_fd` - Outputs a single character to a specific file descriptor.
- `ft_putstr_fd` - Outputs a string to a specific file descriptor.
- `ft_putendl_fd` - Outputs a string followed by a newline to a specific file descriptor.
- `ft_putnbr_fd` - Outputs an integer value to a specific file descriptor.

</details>

<details>

<summary><b>Part 3: linked list functions </b></summary>

- `ft_lstnew` - Creates a new list node with the provided content.
- `ft_lstadd_front` - Adds a new node to the beginning of a list.
- `ft_lstsize` - Counts a number of nodes in a list.
- `ft_lstlast` - Returns the last node of a list.
- `ft_lstadd_back` - Adds a new node to the end of a list.
- `ft_lstdelone` - Deletes a node and frees its content using a provided function.
- `ft_lstclear` - Deletes and frees an entire list and all its contents.
- `ft_lstiter` - Iterates through a list and applies a function to the content of each node.
- `ft_lstmap` - Creates a new list by applying a function to each node of an existing list.

</details>


## Instructions
### Compilation
The project includes a Makefile with following rules:
- `all` - compiles the source files and generates the library `libft.a`
- `clean` - removes object files
- `fclean` - removes object files and compiled library
- `re` - forces a full recompilation of the library

To compile, run the following command in your terminal:
```
make
```
### Installation and Usage
To use the library in your project, include the header in your source code:
```
#include "libft.h"
```
Link the library file when compiling your project:
```
gcc main.c -L. -lft
```

*Note*: `-L` tells the compiler to look in the current directory for the library, and `-lft` links the libft.a file.

## Resources
- **Man pages**: used as a primary source via the terminal to understand expected return values and function declarations.
- **42 Library Norm**: the official school guidelines followed for code formatting and project structure.
- **42 Cursus Guide (Libft)** (https://42-cursus.gitbook.io/guide/0-rank-00/libft) : a community guide used to understand the logic and requirements of the project.
- **W3Schools - C Tutorial** (https://www.w3schools.com/c/): used for quick syntax reference and basic examples of C built-in functions.
- **GeekforGeeks - C Programming Language** (https://www.geeksforgeeks.org/c/c-programming-language/) : referenced for explanations of memory management and linked list implementation.

### AI Usage Disclosure
Artificial Intelligence (Gemini) was utilized during this project for the following tasks:
- Assisted in generating the organized layout for this documentation
- Used to clarify C programming concepts
- Aided in resolving memory-related exercises to ensure the library is leak-free and memory-safe
- Used to help structure the project timeline, prioritize function implementation, and organize the overall development workflow.
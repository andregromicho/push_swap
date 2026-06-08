*This project has been created as part of the 42 curriculum by abrandao.*

# 📚 Libft

## 📝 Description

Libft is a custom implementation of essential C standard library functions, along with additional utilities.

This project aims to deepen understanding of low-level programming concepts such as memory management, pointers, and data manipulation.

The resulting library serves as a reusable foundation for future 42 projects.

---

## ⚙️ Instructions

### Compilation

```bash
make
```

### 🛠 Makefile Commands

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

## 🚀 Usage

### 1. Include the library

```c
#include "libft.h"
```

### 2. Compile your program with Libft

```bash
cc main.c -L. -lft -o program
```

### 3. Example

```c
#include <stdio.h>
#include "libft.h"

int main(void)
{
    char str[] = "Hello, World!";
    
    printf("Length: %zu\n", ft_strlen(str));
    printf("Uppercase h: %c\n", ft_toupper('h'));

    return (0);
}
```

### 4. Using the static library directly

After running `make`, a file called `libft.a` will be generated.  
This is a **static library**, meaning all compiled functions are bundled together.

You can also compile like this:

```c
cc main.c libft.a -o program
```

---

## 📦 Library Overview

### Libc Functions

| Function   | Prototype                                                              | Description                         |
| ---------- | ---------------------------------------------------------------------- | ----------------------------------- |
| ft_isalpha | int ft_isalpha(int c)                                                  | Checks if character is alphabetic   |
| ft_isdigit | int ft_isdigit(int c)                                                  | Checks if character is a digit      |
| ft_isalnum | int ft_isalnum(int c)                                                  | Checks if character is alphanumeric |
| ft_isascii | int ft_isascii(int c)                                                  | Checks if character is ASCII        |
| ft_isprint | int ft_isprint(int c)                                                  | Checks if character is printable    |
| ft_strlen  | size_t ft_strlen(const char *s)                                        | Returns string length               |
| ft_memset  | void *ft_memset(void *s, int c, size_t n)                            | Fills memory with a constant byte   |
| ft_bzero   | void ft_bzero(void *s, size_t n)                                       | Sets memory to zero                 |
| ft_memcpy  | void *ft_memcpy(void *dest, const void *src, size_t n)                  | Copies memory area                  |
| ft_memmove | void *ft_memmove(void *dest, const void *src, size_t len)               | Copies memory safely                |
| ft_strlcpy | size_t ft_strlcpy(char *dst, const char *src, size_t size)          | Copies string with size limit       |
| ft_strlcat | size_t ft_strlcat(char *dst, const char *src, size_t size)          | Concatenates strings safely         |
| ft_toupper | int ft_toupper(int c)                                                  | Converts to uppercase               |
| ft_tolower | int ft_tolower(int c)                                                  | Converts to lowercase               |
| ft_strchr  | char *ft_strchr(const char *s, int c)                                  | Finds first occurrence of character |
| ft_strrchr | char *ft_strrchr(const char *s, int c)                                 | Finds last occurrence of character  |
| ft_strncmp | int ft_strncmp(const char *s1, const char *s2, size_t n)               | Compares strings                    |
| ft_memchr  | void *ft_memchr(const void *s, int c, size_t n)                        | Scans memory                        |
| ft_memcmp  | int ft_memcmp(const void *s1, const void *s2, size_t n)                | Compares memory                     |
| ft_strnstr | char *ft_strnstr(const char *haystack, const char *needle, size_t len) | Finds substring                     |
| ft_atoi    | int ft_atoi(const char *str)                                           | Converts string to integer          |
| ft_calloc  | void *ft_calloc(size_t nmemb, size_t size)                             | Allocates zero-initialized memory   |
| ft_strdup  | char *ft_strdup(const char *s)                                        | Duplicates a string                 |

---

### Additional Functions

| Function    | Prototype                                                      | Description                   |
| ----------- | -------------------------------------------------------------- | ----------------------------- |
| ft_substr   | char *ft_substr(char const *s, unsigned int start, size_t len) | Returns a substring from s    |
| ft_strjoin  | char *ft_strjoin(char const *s1, char const *s2)               | Concatenates s1 and s2        |
| ft_strtrim  | char *ft_strtrim(char const *s1, char const *set)              | Trims characters from set     |
| ft_split    | char **ft_split(char const *s, char c)                         | Splits string by delimiter    |
| ft_itoa     | char *ft_itoa(int n)                                           | Converts integer to string    |
| ft_strmapi  | char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) | Applies function to each char |
| ft_striteri | void ft_striteri(char *s, void (*f)(unsigned int, char *))     | Applies function in place     |

---

### File Descriptor Functions

| Function      | Prototype                           | Description                 |
| ------------- | ----------------------------------- | --------------------------- |
| ft_putchar_fd | void ft_putchar_fd(char c, int fd)  | Outputs a character to fd   |
| ft_putstr_fd  | void ft_putstr_fd(char *s, int fd)  | Outputs a string to fd      |
| ft_putendl_fd | void ft_putendl_fd(char *s, int fd) | Outputs string with newline |
| ft_putnbr_fd  | void ft_putnbr_fd(int n, int fd)    | Outputs integer to fd       |

---

### Linked Lists

| Function | Prototype | Description |
| :--- | :--- | :--- |
| ft_lstnew | t_list *ft_lstnew(void *content) | Creates a new list element |
| ft_lstadd_front | void ft_lstadd_front(t_list **lst, t_list *new) | Adds element at the beginning of list |
| ft_lstsize | int ft_lstsize(t_list *lst) | Counts the number of elements in list |
| ft_lstlast | t_list *ft_lstlast(t_list *lst) | Returns the last element of list |
| ft_lstadd_back | void ft_lstadd_back(t_list **lst, t_list *new) | Adds element at the end of list |
| ft_lstdelone | void ft_lstdelone(t_list *lst, void (*del)(void*)) | Deletes one specific element |
| ft_lstclear | void ft_lstclear(t_list **lst, void (*del)(void*)) | Deletes and frees entire list |
| ft_lstiter | void ft_lstiter(t_list *lst, void (*f)(void *)) | Applies function to all list elements |
| ft_lstmap | t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) | Creates new list from mapping |

---
## 📚 Resources

- man pages.
- GNU C Library documentation.
- 42 subject PDF.
- Francinette: automated testing tool for 42 projects.
- Peer discussions and testing.
- AI tools were used to help understand some concepts.

---

## 🎯 Purpose

This project builds a strong foundation in C programming and prepares for future projects by creating a reusable personal library.


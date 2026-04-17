*This project has been created as part of the 42 curriculum by tolrafan.*

---

## Description

*Libft* is a custom C library that reimplements a wide range of standard C library functions, along with additional utility functions and list management tools. This project serves as the foundation for many future 42 projects by providing a personal toolkit of essential functions.

*Goal:* To deepen understanding of C programming, memory management, string manipulation, and linked lists by rebuilding standard functions from scratch.

*Overview:*
- *Part 1:* Reimplementation of libc functions.
- *Part 2:* Additional utility functions.
- *Part 3:* Linked list manipulation functions.

---

## Instructions

### Compilation


make	# Compile the library

make clean	# Remove object files

make fclean	# Remove object files and library

make re	# Recompile everything

### How to Use the Library

1. *Clone the repository:*
```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-ab5c6f97-de62-4a68-9669-59e9b3ea7732-7255794-tolrafan libft
cd libft
```

2. *Compile the library:*
make
This will generate a libft.a static library file.

3. *Include the header in your C file:*
```C
#include "libft.h"

int main(void)
{
    char *str;
    
    str = ft_strdup("Hello 42!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

4. *Compile your program with the library:*
# If your program and libft are in the same directory
```Bash
cc -Wall -Wextra -Werror your_program.c libft.a -o your_program
```

# If libft is in a subfolder
```Bash
cc -Wall -Wextra -Werror your_program.c -L./libft -lft -o your_program
```

5. *Run your program:*
```Bash
./your_program
```

### Example Usage

*String manipulation:*
```C
char *s1 = "Hello";
char *s2 = "World";
char *joined = ft_strjoin(s1, s2);
```

*Memory manipulation:*
```C
char buffer[10];
ft_memset(buffer, 'A', 5);
```

*Linked list:*
```C
t_list *list = NULL;
t_list *node = ft_lstnew("42");
ft_lstadd_back(&list, node);
```

### Project Structure
libft/
├── Makefile          # Compilation configuration
├── libft.h           # Header file with all prototypes
├── ft_*.c           # Function implementations
└── README.md        # This file

---

## Resources

### Official Documentation
- [Official GNU C Language Facilities in the Library)](https://sourceware.org/glibc/manual/2.43/html_mono/libc.html#Language-Features)
- [Official GNU Memory Allocation in C Programs](https://sourceware.org/glibc/manual/2.43/html_mono/libc.html#Unconstrained-Allocation)
- [Official GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)

### Tutorials & References
- [DevDocs.io - C/C++ Documentation](https://devdocs.io/c/)
- [W3Schools - C Tutorial](https://www.w3schools.com/c/)
- [GeeksforGeeks - C Programming Language](https://sourceware.org/glibc/manual/2.43/html_mono/libc.html#Memory-Allocation-and-C)
- [Markdown and README.md Files](https://www.codecademy.com/article/markdown-and-readmemd-files)

### How AI Was Used

In accordance with 42's policy on AI-assisted learning, AI tools were used as supplementary resources to deepen understanding, not to generate complete solutions. All code was written, tested, and debugged personally.

*AI Tools Used:*
- [ChatGPT](https://chatgpt.com/)
- [DeepSeek](https://chat.deepseek.com/)

*Tasks assisted with AI:*
- *Concept clarification:* Understanding complex pointer arithmetic in ft_memmove and the difference between memcpy and memmove when handling overlapping memory
- *Debugging assistance:* Identifying causes of segmentation faults and memory leaks during development
- *Peer-learning simulation:* Explaining function logic in beginner-friendly terms to verify personal comprehension
- *Documentation formatting:* Structuring the README and organizing function tables for clarity

All AI assistance was used as a learning aid to supplement personal research and peer discussions, not as a substitute for understanding the material.

---

## Library Functions

### Part 1 - Libc Functions
| Function | Description |
|----------|-------------|
| ft_isalpha | Check for alphabetic character |
| ft_isdigit | Check for digit (0-9) |
| ft_isalnum | Check for alphanumeric character |
| ft_isascii | Check for ASCII character |
| ft_isprint | Check for printable character |
| ft_strlen | Calculate string length |
| ft_memset | Fill memory with a constant byte |
| ft_bzero | Zero a byte string |
| ft_memcpy | Copy memory area |
| ft_memmove | Copy memory area with overlap handling |
| ft_strlcpy | Size-bounded string copying |
| ft_strlcat | Size-bounded string concatenation |
| ft_toupper | Convert char to uppercase |
| ft_tolower | Convert char to lowercase |
| ft_strchr | Locate character in string |
| ft_strrchr | Locate character in string (reverse) |
| ft_strncmp | Compare two strings |
| ft_memchr | Scan memory for a character |
| ft_memcmp | Compare memory areas |
| ft_strnstr | Locate a substring in a string |
| ft_atoi | Convert string to integer |
| ft_calloc | Allocate and zero-initialize memory |
| ft_strdup | Duplicate a string |

### Part 2 - Additional Functions
| Function | Description |
|----------|-------------|
| ft_substr | Extract substring from string |
| ft_strjoin | Concatenate two strings |
| ft_strtrim | Trim characters from string |
| ft_split | Split string into array |
| ft_itoa | Convert integer to string |
| ft_strmapi | Apply function to each char of string |
| ft_striteri | Apply function to each char (in-place) |
| ft_putchar_fd | Output char to file descriptor |
| ft_putstr_fd | Output string to file descriptor |
| ft_putendl_fd | Output string + newline to fd |
| ft_putnbr_fd | Output integer to file descriptor |

### Part 3 - Linked List Functions
| Function | Description |
|----------|-------------|
| ft_lstnew | Create new list node |
| ft_lstadd_front | Add node at beginning |
| ft_lstsize | Count list elements |
| ft_lstlast | Return last node |
| ft_lstadd_back | Add node at end |
| ft_lstdelone | Delete one node |
| ft_lstclear | Delete entire list |
| ft_lstiter | Apply function to each node |
| ft_lstmap | Apply function and create new list |

---

## Technical Choices

- *Norminette compliant:* Code follows 42's strict coding standard
- *No forbidden functions:* All functions written from scratch
- *Static library:* Compiled as libft.a for easy integration
- *Makefile automation:* Automatic compilation and dependency management
- *Memory safety:* Extensive NULL checks and boundary validation

---

### Testing

The library has been tested with:
- [Francinette](https://github.com/xicodomingues/francinette)
- [LibftTester](https://github.com/Tripouille/libftTester)
- Custom test programs
# ft_printf

Because ft_putnbr() and ft_putstr() aren't enough

## Description

This project involves recoding the printf() function from libc. The goal is to learn about using variable numbers of arguments while creating a function that will mimic the original printf().

### Prototype
```c
int ft_printf(const char *, ...);
```

## Technical Requirements

- Program name: `libftprintf.a`
- Files to submit: Makefile, *.h, */*.h, *.c, */*.c
- Makefile rules: NAME, all, clean, fclean, re
- External functions allowed: 
  - malloc
  - free
  - write
  - va_start
  - va_arg
  - va_copy
  - va_end
- Libft usage: Authorized

## Mandatory Features

The function must handle the following conversions:

- `%c` - Prints a single character
- `%s` - Prints a string (as defined by the common C convention)
- `%p` - Prints a void * pointer in hexadecimal format
- `%d` - Prints a decimal (base 10) number
- `%i` - Prints an integer in base 10
- `%u` - Prints an unsigned decimal (base 10) number
- `%x` - Prints a number in hexadecimal (base 16) lowercase format
- `%X` - Prints a number in hexadecimal (base 16) uppercase format
- `%%` - Prints a percent sign

### Important Notes
- Buffer management of the original printf() should not be implemented
- The function will be compared against the original printf()
- The library must be created using the `ar` command (libtool is forbidden)
- The libftprintf.a must be created at the root of the repository

## Bonus Features

The bonus part will only be evaluated if the mandatory part is perfect. Available bonus features:

### Flag Management
- Manage any combination of the following flags: '-0.' and the field minimum width under all conversions
- Manage all the following flags: '# +' (Yes, one of them is a space)

## Compilation

The project must compile with the flags: `-Wall -Wextra -Werror`

## Submission Guidelines

- Submit your work to your assigned git repository
- Only the work in the git repository will be graded
- The project must follow the Norm
- Functions should not quit unexpectedly
- All heap allocated memory space must be properly freed
- If using libft, copy its sources and Makefile in a libft folder

## Note

Once this assignment is passed, you will be allowed to add your ft_printf() to your libft for use in future school C projects.

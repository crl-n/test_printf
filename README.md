# test_printf
A simple, easy-to-use and easily customizable set of unit tests for ft_printf.

## Use
The repo should be cloned into the same folder that the ft_printf folder resides in. To run the tests, simply use the Makefile to build the project and then run the test_printf executable.
If the Makefile displays errors, it is likely that you have to modify the Makefile so that the paths to libft and ft_printf are correct.

You can use the TEST macro to add cases of your own to main.c. You use it as you would use printf itself.
```
TEST("Hello, %s", "World.\n")
```
The macro calls ft_printf and printf with the same arguments and displays the resulting output, the test case and the return values of both functions.

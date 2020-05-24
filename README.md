# :white_check_mark: ft_printf (project 2020)  
## Description  
This project is made in accordance with the requirements of the school of programming 21 (42 school).  
The main task in this project is to implement individual components of the original `printf` function.  
List of conversions that I implemented in the code:  
| Specifier | Description | Example |
|:---------:|:-----------:|:-------:|
| %с | Output any character from an ASCII table | '$' |
| %s | Output an array of characters with a null-terminating character at the end ('\0') | "Hello World!" |
| %p | Output of the pointer address | 0xfff000bd8 |
| %d and %i | Output of an integer in decimal notation | 1488 |
| %u | Output of an unsigned integer in the decimal system | 3000000000 |
| %x | Output an unsigned integer in hexadecimal notation | 15e20a |
| %X | Output an unsigned integer in hexadecimal notation | 15E20A |
| %% | Output of the '%' sign | % |  

List of flags used:  
| Flag | Description |
|:----:|:-----------:|
| - | Left-align text with the specified width |
| (number). | The minimum number of characters to output as a width. If the number has fewer characters, it inserts spaces (or zeros) |
| .(number) | For integer specifiers (d, i, o, u, x, X), precision determines the minimum number of characters to output. If the value is shorter, zeros are output before the number. The value is not truncated, even if it is longer. An accuracy of 0 means that nothing is output for the value 0. |
| *. | The width is not specified in the format string, it is passed separately as an argument that must precede the output number |
| .* | Precision is not specified in the format string, but is passed separately as an argument that must precede the output number |  

## The project tested "PFT"  
![](https://github.com/markveligod/ft_printf/raw/master/img/1.png)  
Link: [click](https://github.com/gavinfielder/pft)  

## Other
Basic commands for compilation:
```
make (make all) - compilation libftprintf.a
make clean - clearing *.o files  
make fclean - clearing *. o files and libraries  
```
  
**Author:** *[Mark Veligod](https://github.com/markveligod)* 

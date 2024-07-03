# EXAM_06_03. Matrix rotation
The russian version of the task can be found in the repository.

## Task
| Exam_06_03 ||
| ------ | ------- |
| Level: | 4. |
| Topics: | Matrices. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

Create a program that rotates a matrix of the 'M x N' size by 90 degrees clockwise. The size of the matrix is specified in the standard input stream-stdin as two positive numbers, followed by 'M * N' integers that describe the matrix row by row. The result of the program should be output to the standard output stream-stdout as a table (there must be a line break after each output row of the final matrix); the elements must be separated by spaces, and there must be no spaces before the line break. There should be no newline break at the end of the response. Check the validity of the entered data. In case of any error, output "n/a".

## Examples

| Input | Output |
| ------ | ------ |
| 2 3<br>1 2 3<br>4 5 6 | 4 1<br>5 2<br>6 3|3 3<br>1 2 3<br>4 5 6<br>7 8 9<br> 7 4 1<br>8 5 2<br> 9 6 3 |

> **Attention:** We kindly remind you that the procedure for testing your program includes an analysis of the code style. Please look in the "materials /" folder. Also, be sure to check your program for memory leaks.
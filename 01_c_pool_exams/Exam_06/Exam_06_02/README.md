# EXAM_06_02. Swapping rows
The russian version of the task can be found in the repository.

## Task
| Exam_06_02 ||
| ------ | ------- |
| Level: | 4. |
| Topics: | Matrices. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

Create a program that swaps rows that contain the first occurrences of the minimum and the maximum elements of the matrix, in a matrix of the 'M x N' size. The size of the matrix is specified in the standard input streamä€"stdin as two positive numbers, followed by "M * N' integers that describe the matrix row by row. The result of swapping should be output to the standard output streamâ€"stdout as a table (there must be a line break after each output row of the final matrix); the elements must be separated by spaces, and there must be no spaces before the line break. There should be no newline break at the end of the response. Check the validity of the entered data. In case of any error, output "n/a".

## Examples

| Input | Output |
| ------ | ------ |
| 4 3<br>1 2 3<br>4 5 6<br>7 8 9<br>10 11 12 | 10 11 12<br>4 5 6<br>7 8 9<br>1 2 3 |

> **Attention:** We kindly remind you that the procedure for testing your program includes an analysis of the code style. Please look in the "materials /" folder. Also, be sure to check your program for memory leaks.
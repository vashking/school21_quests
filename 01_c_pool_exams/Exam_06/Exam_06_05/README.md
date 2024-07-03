# EXAM_06_05. Squares of numbers on a spiral
The russian version of the task can be found in the repository.

## Task
| Exam_06_05 ||
| ------ | ------- |
| Level: | 5. |
| Topics: | Matrices. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

Write a program that fills a square matrix 'N x N' in a spiral, counterclockwise, starting from the upper left corner with squares of numbers from '0' to N^2 - 1'. The order of the matrix N is specified on the standard input stream-stdin as a positive nonzero number. Output the resulting matrix to the standard output stream-stdout as a table (after each outputted line of the resulting matrix, a line break must be performed), the elements must be separated by spaces, and there must be no space characters before the newlines. There should be no newline break at the end of the response. Check the validity of the entered data. In case of any error, output "n/ a".

## Examples

| Input | Output |
| ------ | ------ |
| 2 | 0 9<br> 1 4|
| 3 | 0 49 36<br> 1 64 25<br> 4 9 16 |


> **Attention:** We kindly remind you that the procedure for testing your program includes an analysis of the code style. Please look in the "materials /" folder. Also, be sure to check your program for memory leaks.
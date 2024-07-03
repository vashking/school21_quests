# EXAM_05_04. Removing repetitions
The russian version of the task can be found in the repository.

## Task
| Exam_05_04 ||
| ------ | ------- |
| Level: | 3. |
| Topics: | Dynamic arrays. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

Write a program that removes repetetive elements in a sequence of non-negative integers. the sequence is specified on the standard input stream-stdin, the elements of the sequence are separated by spaces, the end of the sequence is the number -1, which denotes the end of the sequence and is not an element of it. Print the elements of the resulting sequence, separated by a space, to the standard output stream-stdout. There should  be no newline break at the end of the response. Check the validity of the entered data. In case of any error, output "n/a".

> **Note:** The order of the elements in the resulting sequence must match the order of the first occurrences of the corresponding numbers in the original sequence.

> There can be any size of the sequence.

## Examples

| Input | Output |
| ------ | ------ |
| 1 1 2 2 3 -1 | 1 2 3 |
| 1 2 1 3 1 4 -1 | 1 2 3 4 |
| -1 | |

> **Attention:** We kindly remind you that the procedure for testing your program includes an analysis of the code style. Please look in the "materials /" folder. Also, be sure to check your program for memory leaks.
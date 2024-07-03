# EXAM_01_04. Fixing Errors №4
The russian version of the task can be found in the repository.

## Task
| Exam_01_04 ||
| ------ | ------- |
| Level: | 1 |
| Topics: | Basic data types, declaring variables, assignment operator. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

An error occurred when writing the program. It is necessary to correct syntactic, stylistic, and logical errors without changing the operation of the program. There should be no newline break at the end of the response.

```c
#include <stdio.h>

int main(void)
{
    int left = 2, int right = 1;

    scanf("%d %d", &left, &right);
    printf("%d", left * right);

    return 0;
}
```

## Examples

| Input | Output |
| ------ | ------ |
| 2 2 | 4 |
| -4 4 | -16 |


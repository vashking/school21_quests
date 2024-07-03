# EXAM_02_02. Incorrect work of program №2
The russian version of the task can be found in the repository.

## Task
| Exam_02_02 ||
| ------ | ------- |
| Level: | 1. |
| Topics: | Data input/ouput. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

It is necessary to correct syntactic, stylistic and logical errors without changing the operationg of the program. There should be no newline break at the end of the response.

```c
#include <stdio.h>

int main(void)
{
    int x = -21;

    scanf("%d", x);
    printf("%03d", x);

    return 0;
}
```

## Examples

| Input | Output |
| ------ | ------ |
| 0 | 00000 |
| 1 | 00001 |
| -12 | -0012 |
| 555555 | 555555 |



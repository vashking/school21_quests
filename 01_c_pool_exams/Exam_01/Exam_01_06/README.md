# EXAM_01_06. Исправление ошибок №6

## Задание
| Exam_01_06 | |
| ------ | ------- |
| Уровень: | 1 |
| Темы: | Базовые типы данных, объявление переменных, оператор присваивания. |
| Директория для решения: | src/ |
| Файлы решения: | main.c |
| Входные данные: | Стадартный поток ввода (stdin) |
| Выходные данные: | Стадартный поток вывода (stdout) |

При написании программы была допущена ошибка. Необходимо исправить синтаксические, стилевые и логические ошибки, не изменяя работу программы. В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>

int main(void)
{
    int value = 1;
    double pi = "3.141";

    scanf("%d", &value);
    printf("%.2f", value * pi);

    return 0;
}
```

## Примеры

| Входные данные | Результат работы |
| ------ | ------ |
| 0 | 0.0 |
| 2 | 6.28 |

> **Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку "materials/". Также обязательно проверяйте вашу программу на утечки памяти.
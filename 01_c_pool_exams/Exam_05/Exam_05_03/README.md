# EXAM_05_03. Вывод последовательности

## Задание
| Exam_05_03 | |
| ------ | ------- |
| Уровень: | 3 |
| Темы: | Динамические массивы. |
| Директория для решения: | src/ |
| Файлы решения: | main.c |
| Входные данные: | Стадартный поток ввода (stdin) |
| Выходные данные: | Стадартный поток вывода (stdout) |

Написать программу, производящую вывод элементов последовательности `X - (X_1, X_2, X3, ..., X_n)` в следующем порядке `X_1 x_n X_2 X_{n-1} ...`. Последовательность `X` состоит из целых неотрицательных чисел и задается на стандартном потоке ввода stdin, элементы последовательности разделены между собой пробелами, концом последовательности является число -1, которое обозначает конец последовательности и не является ее элементом. В конце ответа не должно быть переноса на новую строку. Проверить на валидность введеные данные. В случае любой ошибки выводить "n/a".

> **Примечание:** За последним выведенным элементом не должно следовать пробела.

> Последовательность может быть любого размера

## Примеры

| Входные данные | Результат работы |
| ------ | ------ |
| 1 2 3 -1 | 1 3 2 |
| 1 2 3 4 5 6 -1 | 1 6 2 5 3 4 |

> **Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку "materials/". Также обязательно проверяйте вашу программу на утечки памяти.
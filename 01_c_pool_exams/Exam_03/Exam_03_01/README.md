# EXAM_03_01. 

## Задание
| Exam_03_01 | |
| ------ | ------- |
| Уровень: | 2 |
| Темы: | Типы данных, переменные, выражения, логические операции и математические функции. |
| Директория для решения: | src/ |
| Файлы решения: | main.c |
| Входные данные: | Стадартный поток ввода (stdin) |
| Выходные данные: | Стадартный поток вывода (stdout) |

Написать программу, вычисляющую массу шара в килограммах, состоящего полностью из платины. Радиус шара (в метрах, вещественное число) задается на стандартном потоке ввода stdin, а плотность платины составляет 21500 $`кг/м^3`$. Результат вычисления округлить до целого числа и вывести на стандартный поток вывода stdout. Проверить на валидность введеные данные. В случае любой ошибки выводить "n/a"

> **Примечание:** Формула объема шара: `V = (4 / 3) * pi * R^3` \
> **Примечание:** Формула объема шара: `P = m / V` \
> **Примечание:** В этом задании важна точность, поэтому советуем использовать константу `M_PI` (содержащую число пи) и функцию `double round (double x);` из библиотеки <math.h>, а так же `double` вместо `float`

> Вывод должен выглядеть таким образом - `printf("%.0lf", result);`

## Примеры

| Входные данные | Результат работы |
| ------ | ------ |
| 1 | 90059 |
| 10 | 90058989 |

> **Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку "materials/". Также обязательно проверяйте вашу программу на утечки памяти.
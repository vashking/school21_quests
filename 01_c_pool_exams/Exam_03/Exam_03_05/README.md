# EXAM_03_05. Логическое выражение

## Задание
| Exam_03_05 | |
| ------ | ------- |
| Уровень: | 2 |
| Темы: | Типы данных, переменные, выражения, логические операции и математические функции. |
| Директория для решения: | src/ |
| Файлы решения: | main.c |
| Входные данные: | Стадартный поток ввода (stdin) |
| Выходные данные: | Стадартный поток вывода (stdout) |

На стандартный поток ввода stdin поступают числа x, y, z, каждое из которых может принимать одно из двух значений (0 и 1). Необзодимо вывести на стандартный поток вывода stdout единицу, если значение следующего выражения истинно: x and (z or y), в противном случае вывести ноль. В конце ответа не должно быть переноса на новую строку. Проверить на валидность введенные данные. В случае любой ошибки выводить "n/a".

## Примеры

| Входные данные | Результат работы |
| ------ | ------ |
| 1 1 1 | 1 |
| 0 0 0 | 0 |

> **Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку "materials/". Также обязательно проверяйте вашу программу на утечки памяти.
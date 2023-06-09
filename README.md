# SmartCalc v1.0

Реализация SmartCalc v1.0.


## Introduction

В данном проекте Вам предстоит реализовать на языке программирования Си с использованием структурного подхода расширенную версию обычного калькулятора, который можно найти в стандартных приложениях каждой операционной системы. Помимо базовых арифметических операций, как плюс-минус и умножить-поделить, Вам необходимо дополнить калькулятор возможностью вычисления арифметических выражений с учетом приоритетов, а так же некоторыми математическими функциями (синус, косинус, логарифм и т.д.). Помимо вычисления выражений калькулятор так же должен поддерживать использование переменной _x_ и построение графика соответствующей функции. В качестве дополнительных улучшений можно будет рассмотреть кредитный и депозитный калькулятор.


## Information

### Польская прямая и обратная нотации

Несмотря на безусловное удобство работы с классической формой записи выражений при ручном счёте, при написании программ запросы чаще всего формируются в формате `что делать -> с какими данными совершать операции`. Так, примерно в 1920 Польский логик Ян Лукасевич изобрел префиксную нотацию (в последствии также называемую польской нотацией или прямой польской нотацией) с целью упрощения пропозиционной логики.

Рассмотрим способы написания выражений:

Выражение, написанное в классической (инфиксной) нотации:

>2 / (3 + 2) * 5

Выражение, написанное в польской (префиксной) нотации:

>\* (/ 2 (+ 3 2)) 5

Как правило скобки между операциями с одинаковым приоритетом опускаются и итоговая запись выглядит следующим образом:

>\* / 2 (+ 3 2) 5

Пример выражения, написанного в обратной польской (бесскобочной) нотации:

> 2 3 2 + / 5 *

### Алгоритм Дейкстры

Эдсгер Дейкстра изобрёл алгоритм для преобразования выражений (в том числе функций) из инфиксной в обратную польскую нотацию. Алгоритм получил название «сортировочная станция», за сходство его операций с происходящим на железнодорожных сортировочных станциях. 

>Перед рассмотрением самого алгоритма сделаем небольшую ремарку и введём понятие лексемы. Лексемой будет называться простейшая единица морфологического разбора выражения. Так, разбитое на лексемы выражение 2 / (3 + 2) * 5 (пробелы добавлены для более удобного восприятия и не несут семантического смысла), будет выглядеть следующим образом: [2], [/], [(], [3], [+], [2], [)], [*], [5], где [2, 3, 5] - числовые лексемы, [/, (, +, ), *] - лексемы-операции.

Алгоритм сортировочной станции основан на стеке. В преобразовании участвуют две текстовых переменных: входная и выходная строки. В процессе преобразования используется стек, хранящий ещё не добавленные к выходной строке операции. Преобразующая программа последовательно считывает лексемы из входной строки, выполняя на каждом шаге некоторые действия, зависящие от того, какая лексема была считана.

#### Реализация алгоритма

Пока в исходной строке есть необработанные лексемы, считываем очередную:

Если лексема:
- Число - добавляем в строку вывода.
- Функция или открывающая скобка - помещаем в стек.
- Разделитель аргументов функции (например, запятая):         
    - Перекладываем операторы из стека в выходную очередь пока лексемой на вершине стека не станет открывающая скобка. Если в стеке не окажется открывающей скобки - в выражении допущена ошибка.
- Оператор (O1):
    - Пока присутствует на вершине стека лексема-оператор (O2) чей приоритет выше приоритета O1, либо при равенстве приоритетов O1 является левоассоциативным:
        - Перекладываем O2 из стека в выходную очередь.
    - Помещаем O1 в стек.
- Закрывающая скобка:
    - Пока лексема на вершине стека не станет открывающей скобкой, перекладываем лексемы-операторы из стека в выходную очередь.
    - Удаляем из стека открывающую скобку.
    - Если лексема на вершине стека — функция, перекладываем её в выходную очередь.
    - Если стек закончился до того, как была встречена открывающая скобка - в выражении содержится ошибка.

Если во входной строке больше не осталось лексем:
- Пока есть операторы в стеке:
    - Если на вершине стека скобка - в выражении допущена ошибка.
    - Перекладываем оператор из стека в выходную очередь.

Конец.



## Реализация SmartCalc v1.0

Необходимо реализовать программу SmartCalc v1.0:

- Программа должна быть разработана на языке Си стандарта C11 с использованием компилятора gcc. Допустимо использование дополнительных библиотек и модулей QT
- Код программы должен находиться в папке src 
- Сборка программы должна быть настроена с помощью Makefile со стандартным набором целей для GNU-программ: all, install, uninstall, clean, dvi, dist, test, gcov_report. Установка должна вестись в любой другой произвольный каталог
- Программа должна быть разработана в соответствии с принципами структурного программирования
- При написании кода необходимо придерживаться Google Style
- Должно быть обеспечено покрытие unit-тестами модулей, связанных с вычислением выражений, с помощью библиотеки Check
- Реализация с графическим пользовательским интерфейсом, на базе любой GUI-библиотеки с API для C89/C99/C11 (GTK+, Nuklear, raygui, microui, libagar, libui, IUP, LCUI, CEF, Qt, etc.)
- На вход программы могут подаваться как целые числа, так и вещественные числа, записанные через точку. По желанию можно обрабатывать ввод чисел в экспоненциальной записи
- Вычисление должно производиться после полного ввода вычисляемого выражения и нажатия на символ `=`
- Вычисление произвольных скобочных арифметических выражений в инфиксной нотации
- Вычисление произвольных скобочных арифметических выражений в инфиксной нотации с подстановкой значения переменной _x_ в виде числа
- Построение графика функции, заданной с помощью выражения в инфиксной нотации с переменной _x_  (с координатными осями, отметкой используемого масштаба и сеткой с адаптивным шагом)
    - Не требуется предоставлять пользователю возможность менять масштаб
- Область определения и область значения функций ограничиваются по крайней мере числами от -1000000 до 1000000
    - Для построения графиков функции необходимо дополнительно указывать отображаемые область определения и область значения
- Проверяемая точность дробной части - минимум 7 знаков после запятой
- У пользователя должна быть возможность ввода до 255 символов
- Скобочные арифметические выражения в инфиксной нотации должны поддерживать следующие арифметические операции и математические функции:
    - **Арифметические операторы**:

        | Название оператора | Инфиксная нотация <br /> (Классическая) | Префиксная нотация <br /> (Польская нотация) |  Постфиксная нотация <br /> (Обратная польская нотация) |
        | ------ | ------ | ------ | ------ |
        | Скобки | (a + b) | (+ a b) | a b + |
        | Сложение | a + b | + a b | a b + |
        | Вычитание | a - b | - a b | a b - |
        | Умножение | a * b | * a b | a b * |
        | Деление | a / b | / a b | a b \ |
        | Возведение в степень | a ^ b | ^ a b | a b ^ |
        | Остаток от деления | a mod b | mod a b | a b mod |
        | Унарный плюс | +a | +a | a+ |
        | Унарный минус | -a | -a | a- |

        >Обратите внимание, что оператор умножения содержит обязательный знак `*`. Обработка выражения с опущенным знаком `*` является необязательной и остается на усмотрение разработчика

    - **Функции**:
  
        | Описание функции | Функция |   
        | ---------------- | ------- |  
        | Вычисляет косинус | cos(x) |   
        | Вычисляет синус | sin(x) |  
        | Вычисляет тангенс | tan(x) |  
        | Вычисляет арккосинус | acos(x) | 
        | Вычисляет арксинус | asin(x) | 
        | Вычисляет арктангенс | atan(x) |
        | Вычисляет квадратный корень | sqrt(x) |
        | Вычисляет натуральный логарифм | ln(x) | 
        | Вычисляет десятичный логарифм | log(x) |

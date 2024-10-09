
#include <iostream>
#include <list>
#include <algorithm>

/*
Лабораторная работа 6. Массивы.

1. 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
Если в последовательности нет ни одного простого числа, упорядочить последовательность по невозрастанию.
 
2. 	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию первой цифры числа, 
числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа, 
числа с одинаковыми первыми цифрами и  одинаковыми наименьшими цифрами дополнительно упорядочить 
по неубыванию самого числа.
 
3. 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
Найти строку с наименьшей суммой элементов и заменнить все элементы этой строки этой суммой.

4. Сначала введите последовательность. Затем удалите и продублируйте элементы. 
Затем выведите полученную последовательность (каждый элемент по одному разу). 
Используйте в программе только один массив.

Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
Удалить из последовательности числа-палиндромы, а среди оставшихся продублировать простые числа.

*/

int program1()
{
    std::cout << "Task 1" << std::endl;
    const int size = 10;
    int list[size];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        int n;
        std::cin >> n;
        list[i] = n;
    }

    for (int x : list)
    {
        if (x % 1 != 0 && x % x != 0)
        {
            std::sort(list, list + sizeof(list), std::greater<int>());
            // greater это функция срввнения, которая возвращает true, если первое число больше второго.
        }

        std::cout << x << " ";
    }

    return 0;
}

int program2()
{
    std::cout << "Task 2" << std::endl;
    const int size = 10;
    int list[size];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        int n;
        std::cin >> n;
        list[i] = n;
    }

    for (int i = 0; i < size; i++)
    {
        if (list[i] <= 9)
        {

        }   
        else
        {

        } 
    }
    

    return 0;
}

int program3()
{
    
    return 0;
}

int program4()
{
    
    return 0;
}

int main()
{
    std::cout << "Select number of Task: ";
    unsigned int select;
    std::cin >> select;

    switch(select)
    {
        case 1:
            program1();
            break;
        case 2:
            program2();
            break;
        case 3:
            program3();
            break;
        case 4:
            program4();
            break;
        default:
            std::cout << "wrong number" << std::endl;
    }

    return 0;
}
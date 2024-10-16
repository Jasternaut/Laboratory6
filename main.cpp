
#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

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

bool is_prime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}

int program1()
{
    std::cout << "Task 1" << std::endl;
    const int list_size = 10;
    int list[list_size];
    int count = 0;
    for (int i = 0; i < list_size; i++)
    {
        int n;
        std::cin >> n;
        list[i] = n;
    }

    bool has_prime = false;
    for (auto n : list) {
        if (is_prime(n)) {
            has_prime = true;
            break;
        }
    }

    // Если последовательность не содержит простых чисел, сортируем её по убыванию
    if (!has_prime) 
    {
        std::sort(list, list + list_size, std::greater<int>());
    }

    std::cout << "Result: ";
    for (int x : list)
    {
        std::cout << x << " ";
    }

    return 0;
}

int program2()
{
    std::cout << "Task 2" << std::endl;
    const int size = 10;
    int list[size];

    for (int i = 0; i < size; i++)
    {
        int num;
        std::cin >> num;
        list[i] = num;
    }

    // упорядочивание по возрастанию первой цифры числа
    for (int x : list)
    {
        if (x <= 9) // если число меньше 10
        {
            x = (x * 10) % 10;
        }   
        else // если число больше 10
        {
            while (x /= 10)
            {
                x = x % 10;
            }
        }
        
        
    }
    std::sort(list, list + sizeof(list), std::greater<int>());

    for (int x : list)
    {
        std::cout << x << " " << std::endl;
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
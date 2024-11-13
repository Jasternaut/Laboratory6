
#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

/*
Лабораторная работа 6. Массивы.

1. 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
Если в последовательности нет ни одного простого числа, упорядочить последовательность по невозрастанию.
[готово]
 
2. 	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию первой цифры числа, 
числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа, 
числа с одинаковыми первыми цифрами и  одинаковыми наименьшими цифрами дополнительно упорядочить 
по неубыванию самого числа.
[готово]
 
3. 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
Найти строку с наименьшей суммой элементов и заменнить все элементы этой строки этой суммой.
[готово]

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

bool compare(int a, int b)
{
    int firsta = 0, firstb = 0;
    int a1 = a, b1 = b;
    while (a1)
    {
        firsta = a1 % 10;
        a1 /= 10;
    }
    while (b1)
    {
        firstb = b1 % 10;
        b1 /= 10;
    }
    if (firsta < firstb) // возрастание первой цифры
        return true;
    if (firsta > firstb)// возрастание первой цифры
        return false;

    if (a % 10 < b % 10) // возрастание последней цифры
        return true;
    if (a % 10 > b % 10) // возрастание последней цифры
        return false;
    return a < b;
}

int program2()
{
    std::cout << "Task 2" << std::endl;
    const int size = 10;
    int list[size];

    // Ввод чисел последовательности
    for (int i = 0; i < size; i++)
    {
        int num;
        std::cin >> num;
        list[i] = num;
    }

    std::sort(list, list + 10, compare);

    // Вывод ответа
    std::cout << "Result: ";
    for (int x : list)
    {
        std::cout << x << " ";
    }

    return 0;
}

int program3()
{
    const int i = 3;
    const int j = 3;
    int matrix[i][j];
  
    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            int x;
            std::cin >> x;
            matrix[a][b] = x;
        }
    }

    // поиск строки с наибольшей суммой
    int max_sum = 0;
    int row = 0;
    for (int a = 0; a<i; a++)
    {
        int sum = 0;
        for (int b = 0; b<j; b++)
        {
            sum += matrix[a][b];
        }
        if (sum >= max_sum)
        {
            max_sum = sum;
            row = a;
        }
    }

    std::cout << std::endl;

    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            std::cout << matrix[a][b] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Max sum is " << max_sum << std::endl;
    std::cout << "Max sum row is " << row << std::endl;
    std::cout << "New matrix is:" << std::endl;

    for (int b = 0; b < j; b++)
    {
        matrix[row][b] = max_sum;
    }

    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            std::cout << matrix[a][b] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

int program4()
{
    const int N_Max = 20000;
    int mas[N_Max];

    std::cout << "[204] Initialized massive with size " << N_Max << std::endl;
    std::cout << "[205] Input massive number count: ";
    int n;
    std::cin >> n;

    std::cout << "[209] In massive will be " << n << " numbers." << std::endl;
    std::cout << "[210] Input 6 numbers: " << std::endl;

    for (int i = 0; i < n; i++)
        std::cin >> mas[i];
    
    std::cout << "[214] Added numbers to massive" << std::endl;

    for (int i = 0; i < n; i++)
    {
        // проверка на палиндромы
        int x = mas[i];
        int y = 0;
        while(x > 0)
        {
            y = y*10 + x%10;
            x/=10;
        }
        
        if(x == y)
        {
            std::cout << "[229] " << x << " is palindrome" << std::endl;

            for (int j = i; j<n-1;j++)
            {
                std::cout << "[233] " << mas[j] << " will be " << mas[j+1] << std::endl;
                mas[j] = mas[j+1];
            }               
            i--;
            n--;
        }
    }

    // дублирование
    for (int i = 0; i < n && n < N_Max; i++)
    {
        if (is_prime(mas[i]))
        {
            std::cout << "[246] " << mas[i] << " is prime" << std::endl;
            for (int j = n; j>i; j--)
            {
                std::cout << "[249] " << mas[j] << " will be " << mas[j-1] << std::endl;
                mas[j] = mas[j-1];
            }
                
            i++;
            n++;
        }
        else
        {
            
        }
    }
    
    std::cout << "Result is: ";

    for (int num : mas)
    {
        std::cout << num << " ";
    }

    return 0;
}


int main()
{
    std::cout << "Select number of Task from 1 to 4: ";
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
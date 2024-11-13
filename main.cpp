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

// Проверка на простое число
bool is_prime(int number){

    for(int i=2; i*i <= number; i++)
    {
        if (number%i==0) return false;
    }
    return true;
}

// Пункт 1
int program1()
{
    std::cout << "Task 1" << std::endl;
    const int list_size = 10000;
    int list[list_size];
    int count = 0;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> list[i];
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

    std::cout << "[O] Result: ";
    for (int x : list)
    {
        std::cout << x << " ";
    }

    return 0;
}

// Сравнение двух цифр
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

// Пункт 2
int program2()
{
    std::cout << "Task 2" << std::endl;
    const int size = 10000;
    int list[size];

    int n;
    std::cin >> n;

    // Ввод чисел последовательности
    for (int i = 0; i < size; i++)
    {
        std::cin >> list[i];
    }

    std::sort(list, list + 10, compare);

    // Вывод ответа
    std::cout << "[O] Result: ";
    for (int x : list)
    {
        std::cout << x << " ";
    }

    return 0;
}

int program3()
{
    std::cout << "Task 3" << std::endl;
    const int i = 100;
    const int j = 100;
    int matrix[i][j];
    std::cout << "[O] Matrix initialized" << std::endl;

    std::cout << "[I] Input i count: ";
    int i_input;
    std::cin >> i_input;

    std::cout << "[I] Input j count: ";
    int j_input;
    std::cin >> j_input;
  
    for (int a = 0; a < i_input; a++)
    {
        for (int b = 0; b < j_input; b++)
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

    std::cout << "[O] Max sum is " << max_sum << std::endl;
    std::cout << "[O] Max sum row is " << row << std::endl;
    std::cout << "[O] New matrix is:" << std::endl;

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
    std::cout << "Task 4" << std::endl;
    const int N_Max = 20000;
    int mas[N_Max];

    std::cout << "[I] Input massive number count: ";
    int n;
    std::cin >> n;

    std::cout << "[I] Input " << n << " numbers: " << std::endl;

    for (int i = 0; i < n; i++)
        std::cin >> mas[i];
    
    std::cout << "[O] Added numbers to massive" << std::endl;

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

        if(mas[i] == y)
        {
            std::cout << "[O] " << mas[i] << " is palindrome" << std::endl;

            for (int j = i; j<n-1;j++)
                mas[j] = mas[j+1];                          
            i--;
            n--;
        }
    }

    // дублирование
    for (int i = 0; i < n; i++)
    {
        if (is_prime(mas[i]))
        {
            for (int j = n; j>i; j--)
                mas[j] = mas[j-1];               
            i++;
            n++;
        }
    }
    
    std::cout << "[O] Result is: ";

    for (int i = 0; i<n; i++)
    {
        std::cout << mas[i] << " ";
    }

    return 0;
}


int main()
{
    std::cout << "[I] Select number of Task from 1 to 4: ";
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
            std::cout << "[Error] Wrong number" << std::endl;
    }

    return 0;
}
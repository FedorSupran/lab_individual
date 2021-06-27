#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <cmath>
/*
* Индивидуальное задание
* Автор: Супран Федор Константинович
* Группа: ПИ2-2
*/

/*
* Одна функция будет разделять массив на числа меньше нуля и числа больше нуля, 
* то есть в левой части массива положительные элементы, а в правой отрицательные. 
*/
void func1(double* arr, int size)
{
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            if (arr[i] > arr[j]) 
                std::swap(arr[i], arr[j]);
}
/*
* Вторая функция будет заменять все дробные части чисел в массиве на аргумент, 
* которые подается в функцию.
*/
void func2(double* arr, int size, int fract)
{
    int count = 0;
    int temp = fract;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    double dFract = fract * pow(0.1, count);

    for (size_t i = 0; i < size; i++)
    {
        if (int(arr[i]) < 0)
            arr[i] = int(arr[i]) - dFract;
        else
            arr[i] = int(arr[i]) + dFract;
    }
        
}
/*
* Третья функция будет выводить четыре числа парами, первая пара: те два числа из 
* массива, чьё произведения максимально, вторая пара: те два числа из массива,
* чьё произведение минимальной.
*/
void func3(double* arr, int size)
{
    double min = arr[0] * arr[1], max = arr[0] * arr[1];
    int minI = 0, minJ = 1, maxI = 0, maxJ = 1;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[i] * arr[j] < min)
            {
                min = arr[i] * arr[j];
                minI = i; minJ = j;
            }
            if (arr[i] * arr[j] > max)
            {
                max = arr[i] * arr[j];
                maxI = i; maxJ = j;
            }    
        }
    }
    std::cout << "Первая пара (максимальное произведение): " << arr[maxI] << " " << arr[maxJ] << std::endl;
    std::cout << "Вторая пара (минимальное произведение): " << arr[minI] << " " << arr[minJ] << std::endl;
}
/*
* Четвертая функция нужна для того, чтобы произвольным образом менять взаимное 
* расположение элементов. То есть при её запуске элементы в массиве случайным 
* образом перетасовываются.
*/
void func4(double* arr, int size)
{
    std::shuffle(arr, arr+size, std::default_random_engine(rand()));
}
void printArray(double* arr, int size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}
int main()
{
    srand(time(NULL));
	setlocale(LC_ALL, "ru");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    std::cout << "Заполните массив: ";
    double* arr = new double[size];
    for (size_t i = 0; i < size; i++)
        std::cin >> arr[i];

    // Test func1
    std::cout << "Функция 1: \n";
    func1(arr, size);
    printArray(arr, size);
    std::cout << std::endl << std::endl;

    //Test func2
    std::cout << "Функция 2: \n";
    int fract;
    std::cout << "Введите значение дробной части: ";
    std::cin >> fract;
    func2(arr, size, fract);
    printArray(arr, size);
    std::cout << std::endl << std::endl;

    //Test func3
    std::cout << "Функция 3: \n";
    func3(arr, size);
    std::cout << std::endl;

    //Test func4
    std::cout << "Функция 4: \n";
    func4(arr, size);
    printArray(arr, size);

	return 0;
}
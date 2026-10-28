#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування масиву
void Create(int* t, const int size, const int Low, const int High, int i)
{
    t[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(t, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву
void Print(int* t, const int size, int i)
{
    cout << setw(5) << t[i];

    if (i < size - 1)
        Print(t, size, i + 1);
    else
        cout << endl;
}

// Перевірка умови
bool Check(const int x)
{
    return x <= 0 && x % 5 != 0;
}

// Рекурсивний підрахунок кількості елементів
int Count(int* t, const int size, int i)
{
    if (i < size)
    {
        if (Check(t[i]))
            return 1 + Count(t, size, i + 1);
        else
            return Count(t, size, i + 1);
    }
    else
        return 0;
}

// Рекурсивне обчислення суми
int Sum(int* t, const int size, int i)
{
    if (i < size)
    {
        if (Check(t[i]))
            return t[i] + Sum(t, size, i + 1);
        else
            return Sum(t, size, i + 1);
    }
    else
        return 0;
}

// Рекурсивна заміна елементів нулями
void Replace(int* t, const int size, int i)
{
    if (i < size)
    {
        if (Check(t[i]))
            t[i] = 0;

        Replace(t, size, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int size = 22;
    int t[size];

    int Low = -20;
    int High = 37;

    Create(t, size, Low, High, 0);

    cout << "Original array:" << endl;
    Print(t, size, 0);

    int k = Count(t, size, 0);
    int s = Sum(t, size, 0);

    cout << "Count = " << k << endl;
    cout << "Sum = " << s << endl;

    Replace(t, size, 0);

    cout << "Modified array:" << endl;
    Print(t, size, 0);

    return 0;
}
// lab 6.4 (iter).cpp 

#include <iostream>
#include <iomanip>

using namespace std;

void Create(int*& a, const int size, int Min, int Max);
void findMaxAbs(int* list, const int size, int& indexMax);
void Sum(int* list, const int size, int& sumEl);
void Sort(int* list, const int size, int left, int right);
void Merge(int* list, const int size, int* listA, const int sizeListA, int* listB, const int sizeListB);
void Print(int* list, const int size);

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    cout << "Iтерацiйний спосiб" << endl;
    cout << endl;

    srand((unsigned)time(NULL));

    //srand(1); // для перевірки правильності способів

    int n, leftLimit, rightLimit;
    cout << "N: "; cin >> n;
    cout << "Left limit: "; cin >> leftLimit;
    cout << "Right limit: "; cin >> rightLimit;

    int* a;

    int Min = -10;
    int Max = 10;
    int MaxItemI = 0;
    int sumEl = 0;

    Create(a, n, Min, Max);
    cout << "Before:"; Print(a, n);

    findMaxAbs(a, n, MaxItemI);
    Sum(a, n, sumEl);
    Sort(a, n, leftLimit, rightLimit);

    cout << "After: "; Print(a, n); cout << endl;
    cout << "Max element (№): " << MaxItemI + 1 << endl;
    cout << "Sum elements (№): " << sumEl << endl;

    delete[] a;
}



void Create(int*& a, const int size, int Min, int Max)
{
    a = new int[size]; // виділили пам'ять
    for (int i = 0; i < size; i++)
        a[i] = (Max - Min) * rand() / RAND_MAX + Min; // де Min - ліва межа, а Max - права
}

void findMaxAbs(int* list, const int size, int& indexMax)
{
    for (int i = 0; i < size; i++)
        if (abs(list[i]) > abs(list[indexMax]))
            indexMax = i;
}

void Sum(int* list, const int size, int& sumEl)
{
    bool summing = false;
    for (int i = 0; i < size; i++)
    {

        if (list[i] > 0 && !summing) {
            summing = true;
        }
        if (summing)
            sumEl += list[i];
    }
}

void Merge(int* list, const int size, int* listA, const int sizeListA, int* listB, const int sizeListB) {
    int indexA = 0, indexB = 0;
    for (int i = 0; i < size; i++) {
        if (indexA < sizeListA) {
            list[i] = listA[indexA];
            indexA++;
            continue;
        }
        list[i] = listB[indexB];
        indexB++;
    }
}

void Sort(int* list, const int size, int left, int right) {
    int* inLimit = new int[size];
    int* outLimit = new int[size];

    int j = 0, k = 0;

    for (int i = 0; i < size; i++) {
        if (list[i] >= left && list[i] <= right) {
            inLimit[j] = list[i];
            j++;
        }
        else {
            outLimit[k] = list[i];
            k++;
        }
    }

    Merge(list, size, inLimit, j, outLimit, k);

    delete[] inLimit;
    delete[] outLimit;
}

void Print(int* list, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << list[i];
    cout << endl;
}
#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale.h>
#include <Windows.h>
#include <exception>

using namespace std;

struct Processing1 : public exception
{
    const char * what() const throw()
    {
        return "g";
    }
};

struct Processing2 : public exception
{
public:
    const char* what() const throw()
    {
        return "t";
    }
};

struct Processing3 final : public exception
{
public:
    const char* what() const throw()
    {
        return "r";
    }
};

class Matrix
{
private:
    int matrica1[3][3]; // создаем матрицу 1
    int matrica2[3][3]; // создаем матрицу 2
    int *matrix, size = 0;
public:
    void del_matrix()
    {
        bool y = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrica1[i][j] == matrica2[i][j])
                {
                    y = false;
                }
            }
        }
        if (y == true)
        {
            throw Processing1();
        }
    }

    void wrongConjuction(int n, int cmatrica[3][3]) // метод "неправльной" конъюнкции
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrica1[i][j] == 1 && matrica2[i][j] == 1)
                {
                    cmatrica[i][j] = 0;
                }
                else
                {
                    throw Processing2();
                }
                cout << cmatrica[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void add(int n) // добавление чисел в матрицу (я просто без понятия, что еще можно сделать с конъюкцией)
    {
        int amatrica1[3][3]{};
        int amatrica2[3][3]{};
        n = 5;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                amatrica1[i][j] = matrica1[i][j];
                amatrica2[i][j] = matrica2[i][j];
                amatrica1[0][2] = n;
                amatrica2[0][2] = n;
                cout << setw(11) << amatrica1[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << setw(15) << amatrica2[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    Matrix operator += (int n) // перегрузка оператора +=
    {
        for (int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if (matrica1[i][j] == n && matrica2[i][j] == n)
                {
                    return *this;
                }
            }
        }
        del_matrix();
        return *this;
    }

    Matrix operator << (Matrix &matrix) //перегрузка оператора <<
    {
        add(5);
        return *this;
    }

    Matrix operator && (Matrix r) //перегрузка оператора &&
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrica2[i][j] != matrica1[i][j])
                {
                    throw Processing3();
                }
            }
        }
    }

    Matrix() //конструктор по умолчанию
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrica1[i][j] = 0;
                matrica2[i][j] = 0;
            }
        }
    }

    Matrix(Matrix& Matrix1, Matrix& Matrix2)
    {
        matrix = (int*)malloc(Matrix1.size * sizeof(int));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrica1[i][j] = Matrix1.matrica1[i][j];
                matrica2[i][j] = Matrix2.matrica2[i][j];
            }
        }
    }

    Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int m9) // конструктор с параметрами
    {
        matrica1[0][0] = n1;
        matrica1[0][1] = n2;
        matrica1[0][2] = n3;
        matrica1[1][0] = n4;
        matrica1[1][1] = n5;
        matrica1[1][2] = n6;
        matrica1[2][0] = n7;
        matrica1[2][1] = n8;
        matrica1[2][2] = n9;

        matrica2[0][0] = m1;
        matrica2[0][1] = m2;
        matrica2[0][2] = m3;
        matrica2[1][0] = m4;
        matrica2[1][1] = m5;
        matrica2[1][2] = m6;
        matrica2[2][0] = m7;
        matrica2[2][1] = m8;
        matrica2[2][2] = m9;
    }

    void printMatrix() // метод вывода матриц 
    {
        cout << "Матрица 1" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrica1[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "Матрица 2" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrica2[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void Conjunction() // метод конъюнкции
    {
        bool pmatrica[3][3]{};

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrica1[i][j] == 1 && matrica2[i][j] == 1)
                {
                    pmatrica[i][j] = true;
                }
                else
                {
                    pmatrica[i][j] = false;
                }
                cout.setf(ios::boolalpha); // вывод в виде булевых параметров (true, false)
                cout << pmatrica[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    ~Matrix(){} // деструктор
};

int main()
{
    setlocale(LC_ALL, "rus");

    bool g = true;
    int t;

    Matrix matrixprint1(1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1);
    Matrix matrixprintp;
    Matrix matrixprintp2;
    Matrix matrixprintp3 = matrixprintp2;

    while (g)
    {
        g = false;
        cout << "MENU" << endl;
        cout << "1) Просмотр конструктора и деструктора в действии" << endl;
        cout << "2) Конъюнкция матриц" << endl;
        cout << "3) Проверка перегрузок и исключений" << endl;
        cout << "Для выхода - любой знак" << endl << endl;
        cout << "Выберите пункт: ";
        cin >> t;

        switch (t)
        {
        case 1:
        {
            matrixprint1.printMatrix();
            matrixprintp.printMatrix();

            g = true;
            break;
        }
        case 2:
        {
            Matrix conjuction(1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1);
            conjuction.Conjunction();

            g = true;
            break;
        }
        case 3:
        {
            matrixprintp2 = matrixprintp;
            matrixprintp2 += 5;
            /*matrixprintp2.printMatrix();*/
            matrixprintp3 += 1;
            matrixprintp3 += 2;
            matrixprintp3 += 3;
            /*matrixprintp3.printMatrix();*/

            try // блоки try and catch для проверки пользовательских исключений
            {
                cout << "Не найден элемент, который вы пытаетесь вбить" << endl;
                matrixprintp2 += 8;
            }
            catch (Processing1 e1)
            {
                cout << e1.what() << endl;
            }
            cout << endl;

            try
            {
                Matrix test(1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1);
                test.add(5);
                
            }
            catch (Processing2 e2)
            {
                cout << e2.what() << endl;
            }
            cout << endl;

            try
            {
                cout << "Вы присваиваете значения матрицы себе самой" << endl;
                matrixprintp3 = matrixprintp3;
            }
            catch (Processing3 e3)
            {
                cout << e3.what() << endl;
            }
            cout << endl;

            g = true;
            break;
        }
        }
    }
}

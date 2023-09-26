#include <cstdlib>
using namespace std;
#include <iostream>
template <class T = int>

class Matrix
{
    T** arr;
    int rows;
    int cols;
public:
    Matrix();
    Matrix(int numRows, int numCols);
    ~Matrix();

    Matrix(const Matrix<T>&);
    Matrix(Matrix<T>&);
    Matrix<T>& operator=(Matrix<T>&& obj);

    void RandInit();
    void UserInit();
    void SetRows(int n);
    void SetCols(int n);
    void Print();

    Matrix<T>operator+(const Matrix<T>& obj);
    Matrix<T>operator-(const Matrix<T>& obj);
    Matrix<T>operator/(const Matrix<T>& obj);
    Matrix<T>operator*(const Matrix<T>& obj);

    void FindMax();
    void FindMin();

};
template<class T>
Matrix<T>::Matrix()
{
    arr = nullptr;
    rows = 0;
    cols = 0;
}
template<class T>
Matrix<T>::Matrix(int numRows, int numCols)
{
    arr = new T * [numRows];
    for (int i = 0; i < numRows; ++i)
    {
        arr[i] = new T[numCols];
    }
    rows = numRows;
    cols = numCols;
}
template<class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
template<class T>
Matrix<T>::Matrix(Matrix<T>& obj)
{
    rows = obj.rows;
    cols = obj.cols;
    arr = new T * [rows];

    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new T[cols];
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            arr[i][j] = obj.arr[i][j];
        }
    }
}
template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj) 
{
    rows = obj.rows;
    cols = obj.cols;

    arr = new T * [rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new T[cols];
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            arr[i][j] = obj.arr[i][j];
        }
    }
}
template<class T>
Matrix<T>& Matrix<T>::operator=( Matrix<T>&& obj)
{
    if (this != &obj) 
    {
        for (int i = 0; i < rows; ++i) 
        {
            delete[] arr[i];
        }
        delete[] arr;

        rows = obj.rows;
        cols = obj.cols;
        arr = obj.arr;

        obj.rows = 0;
        obj.cols = 0;
        obj.arr = nullptr;
    }
    return *this;
}
template<class T>
void Matrix<T>::RandInit()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = rand() % 10;
        }
    }
}
template<class T>
void Matrix<T>::UserInit()
{
    int n;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> n;
            arr[i][j] = n;
        }
    }
}
template<class T>
void Matrix<T>::Print()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "[" << arr[i][j] << "] ";
        }
        cout << endl;
    }
    cout << endl;
}
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        return Matrix<T>();
    }

    Matrix<T> res(rows, cols);

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            res.arr[i][j] = arr[i][j] + obj.arr[i][j];
        }
    }

    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        return Matrix<T>();
    }

    Matrix<T> res(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            res.arr[i][j] = arr[i][j] - obj.arr[i][j];
        }
    }

    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        return Matrix<T>();
    }

    Matrix<T> res(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            res.arr[i][j] = arr[i][j] / obj.arr[i][j];
        }
    }

    return res;
}
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        return Matrix<T>();
    }
    
    Matrix<T> res(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            res.arr[i][j] = arr[i][j] * obj.arr[i][j];
        }
    }

    return res;
}
template<class T>
void Matrix<T>::FindMax()
{
    T maxEl = arr[0][0];

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (arr[i][j] > maxEl) 
            {
                maxEl = arr[i][j];
            }
        }
    }
    cout << maxEl;
}
template<class T>
void Matrix<T>::FindMin()
{
    T minEl = arr[0][0];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (arr[i][j] < minEl)
            {
                minEl = arr[i][j];
            }
        }
    }
    cout << minEl;
}
template<class T>
inline void Matrix<T>::SetRows(int n)
{
    rows = n;
}
template<class T>
inline void Matrix<T>::SetCols(int n)
{
    cols = n;
}

int main()
{
    srand(time(0));

    cout << "First matrix: " << endl;
    Matrix<int> m1(2, 2);
    m1.RandInit();
    m1.Print();

    cout << "Second matrix: " << endl;
    Matrix<int> m2(2, 2);
    m2.RandInit();
    m2.Print();

    cout << "obj + obj" << endl;
    Matrix<int> res = m1 + m2;
    res.Print();

    cout << "obj - obj" << endl;
    res = m1 - m2;
    res.Print();

    cout << "obj / obj" << endl;
    res = m1 / m2;
    res.Print();

    cout << "obj / obj" << endl;
    res = m1 * m2;
    res.Print();

    cout << "Max element: ";
    m1.FindMax();
    cout << "\nMin element: ";
    m1.FindMin();

}
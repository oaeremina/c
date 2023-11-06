#include <iostream>
#include <iomanip>
#include <sstream> 
#include <string>
using namespace std;

int main()

{
    int a, b, i, j, n=2, m=2, m1[2][2],  m2[2][2],  m3[2][2],  m4[2][2];
    char opr;
    do
    {
        cout << "Введите два числа: ";
     while (!(cin >> a >> b) || (cin.peek() != '\n'))
     {
        cin.clear();
     while (cin.get() != '\n');
        cout << "Ошибка: Вы ввели не число! Попробуйте еще раз :)" << endl;
     }
    
        cout << "Выберите операцию: +  -  * /  1(сложение матриц)  2(разность матриц) ";
        cin >> opr;
        cout << endl;

    switch (opr){
        case '+':
           cout << a << " " << opr << " " << b << " = ";
           cout << a + b << endl;
           break;
        case'-':
           cout << a << " " << opr << " " << b << " = ";
           cout << a - b << endl;
           break;
        case'*':
           cout << a << " " << opr << " " << b << " = ";
           cout << a * b << endl;
           break;
        case'/':
           cout << a << " " << opr << " " << b << " = ";
        if (b != 0)
            cout << a / b << endl;
        else
            cout << "ERROR \n нельзя делить на 0" << endl;
            break;
        case '1':
             cout << "Введите 4 значения для матрицы: \n";
             for (i=0; i<n; i++)
             for (j=0; j<m; j++)
             while (!(cin >> m1[i][j]) || (cin.peek() != '\n'))
     {
             cin.clear();
             while (cin.get() != '\n');
             cout << "Ошибка: Вы ввели не число! Попробуйте еще раз :)" << endl; }
             cout << endl;           
          

             cout << "Введите 4 значения для следующей матрицы: \n";
             for (i=0; i<n; i++)
             for (j=0; j<m; j++)
             while (!(cin >> m2[i][j]) || (cin.peek() != '\n'))
     {
             cin.clear();
             while (cin.get() != '\n');
             cout << "Ошибка: Вы ввели не число! Попробуйте еще раз :)" << endl; }
             cout << endl;
          

            for (i = 0; i < n; i++) {
              for (j = 0; j < m; j++) {
	        m3[i][j] = m1[i][j] + m2[i][j];
              }
	         cout << endl;
            }
         
            for (i = 0; i < n; i++) {
                 for (j = 0; j < m; j++) {
	        cout << m3[i][j] << "\t";
              }
	          cout << endl;
            }
            cout << endl;
           break;
           
        case '2':
             cout << "введите значения для матрицы, в которой 2 строки и 2 столбца \n";
             for (i=0; i<n; i++)
             for (j=0; j<m; j++)
             while (!(cin >> m1[i][j]) || (cin.peek() != '\n'))
     {
             cin.clear();
             while (cin.get() != '\n');
             cout << "Ошибка: Вы ввели не число! Попробуйте еще раз :)" << endl; }
             cout << endl;
          

             cout << "введите значения для матрицы, в которой 2 строки и 2 столбца \n";
             for (i=0; i<n; i++)
             for (j=0; j<m; j++)
             while (!(cin >> m2[i][j]) || (cin.peek() != '\n'))
     {
             cin.clear();
             while (cin.get() != '\n');
             cout << "Ошибка: Вы ввели не число! Попробуйте еще раз :)" << endl; }
             cout << endl;
          
            for (i = 0; i < n; i++) {
              for (j = 0; j < m; j++) {
	        m4[i][j] = m1[i][j] - m2[i][j];
              }
	         cout << endl;
            }
            cout << endl;
           
            for (i = 0; i < n; i++) {
                 for (j = 0; j < m; j++) {
	        cout << m4[i][j] << "\t";
              }
	          cout << endl;
            }
            cout << endl;
            break;
           
        default:
           cout << "нет такой операции" << endl;
         
    }
        int contin;
        cout << "\nНажмите 1, чтобы продолжить...\n";
        cin >> contin;
    if (contin == 1){
    }
    else 
        break;
        
     }while(opr);
        
return 0;
} 
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <cmath>
#include <thread>
#include <Windows.h>
#include <vector>
#include <fstream>

#include <algorithm>

#include <string>

#include <typeinfo>

#include <exception>



using namespace std;







void dz2_1()



{



    double h, R, r, l;



    cout << "Введите данные" << endl;



    cout << "Введи высоту конуса, больший радиус, меньший радиус" << endl;



    cin >> h >> R >> r;



    l = sqrt(h * h + (R - r) * (R - r));



    if ((h <= 0) or (R <= 0) or (r <= 0) or (l <= 0) or (r >= R)) {



        cout << "Некорректные данные" << endl;



    }



    else {



        cout << "Образующая: " << l << endl;



        cout << "Объем равен: " << 3.14 * h * (R * R + R * r + r * r) / 3 << endl;



        cout << "Площадь равна: " << 3.14 * (R * R + (R + r) * l + r * r) << endl;



    }



}







void dz2_2()



{



    double a, x;



    cout << "Введите числа a и x" << endl;



    cin >> a >> x;



    if (abs(x) < 1) {



        if (x == 0) {



            cout << "Некорректные данные" << endl;



        }



        else {



            cout << "Результат выражения равен: ";



            cout << a * log(abs(x)) << endl;



        }



    }



    else {



        if (a - x * x < 0) {



            cout << "Некорректные данные" << endl;



        }



        else {



            cout << "Результат выражения равен: ";



            cout << sqrt(a - x * x) << endl;



        }



    }



}







void dz2_3()



{



    double x, y, b;



    cout << "Введите числа x y b" << endl;



    cin >> x >> y >> b;



    if ((b - y <= 0) or (b - x < 0)) {



        cout << "Некорректные данные" << endl;



    }



    else {



        cout << "Функция z = " << log(b - y) * sqrt(b - x) << endl;



    }



}







void dz2_4()



{



    cout << "С какого числа начать?" << endl;



    double n;



    int i;



    cin >> n;



    if (n <= 0) {



        cout << "Некорректные данные" << endl;



    }



    else {



        for (i = 0; i < 10; i++) {



            cout << n + i << " ";



        }



    }



    cout << endl;



}







void dz2_5()



{



    cout << "Ща таблицу составлю смари" << endl;



    cout << "x  y" << endl;



    double x = -4;



    int i;



    for (i = 0; i < 17; i++) {



        if (x == 1) {



            cout << "-  -" << endl;



        }



        else {



            cout << x << "  " << (x * x - 2 * x + 2) / (x - 1) << endl;



        }



        x = x + 0.5;



    }



}



bool CustomIsDigits(string Value) {

    int q, i, countmin, counttoch;

    q = Value.size();
    for (i = 0; i < q; i++) {

        if ((Value[i] >= 48 && Value[i] <= 57) || Value[i] == 45 || Value[i] == 44) {

            continue;

        }

        else {

            return false;

        }

    }

    countmin = count(Value.begin(), Value.end(), '-');
    counttoch = count(Value.begin(), Value.end(), '.');

    if (countmin > 1 || counttoch > 1) {

        return false;

    }

    if (countmin == 1 && Value[0] != 45) {

        return false;

    }

    if (counttoch == 1) {

        if (Value[0] == 44) {

            return false;

        }

        if (Value[q - 1] == 44) {

            return false;

        }

        if (Value[q - 1] == 44) {

            return false;

        }

        if (Value[0] == 44) {

            return false;

        }

    }

    return true;

}



void dz3_1()

{

    double S, p, n, r;

    cout << "Помогу тебе с кредитом" << endl;

    cout << "Введи S p и n" << endl;

    cin >> S >> p >> n;

    if (CustomIsDigits(to_string(S)) && CustomIsDigits(to_string(p)) && CustomIsDigits(to_string(n))) {

        if (p == 0) {

            cout << S / 12 / n;

        }

        else {

            r = p / 100;

            cout << "Месячная выплата составит: " << (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

        }

    }

    else {

        cout << "Переделывай";

    }

}







void dz3_2() {

    double S, m, n, r, eps, d;

    eps = 0.0000000000000001;

    d = 100;

    cout << "Не знаешь процент по кредиту? Ща найду!" << endl;

    cout << "Веди данные по кредиту(S, m, n)" << endl;

    cin >> S >> m >> n;

    for (double p = 0, step = 10; p <= 100 + step; p += step) {

        r = p / 100;

        d = m - (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

        if (d < 0) {

            p -= step;

            step /= 10;

        }

        if (fabs(d) <= eps) {

            cout << p << endl;

            break;

        }

    }

}







void dz3_3() {

    string line;

    ofstream f1;

    ifstream f2;

    f1.open("myfile.txt");

    f1 << "я48апа45454гей5454544ава432ло6л43д";

    f1.close();

    f2.open("myfile.txt");

    if (f2.is_open()) {

        while (getline(f2, line)) {

            cout << line << endl;

        }

    }

    else {

        cout << "Файл не найден";

    }

}







void dz3_4() {

    int i;

    ifstream f;

    string numbers = "0123456789", buf, line;

    f.open("myfile.txt");

    while (getline(f, line)) {

        for (i = 0; size(line); i++) {

            if (numbers.find(line[i]) < 100000) {

                buf += line[i];

            }

            else if (buf != "") {

                cout << buf << " ";

                buf = "";

            }

        }

    }

}



void dz3_5() {

    string s;

    int i, j, ns;

    cin >> s;

    for (i = 0; i < s.size() - 1; i++) {

        for (j = 0; j < s.size(); j++) {

            if ((s[j] >= 97 && s[j + 1] >= 97) || (s[j] < 97 && s[j + 1] < 97)) {

                if ((s[j] > s[j + 1])) {

                    ns = s[j];

                    s[j] = s[j + 1];

                    s[j + 1] = ns;

                }

            }

            else if (s[j] >= 97) {

                if (s[j] - 32 >= s[j + 1]) {

                    ns = s[j];

                    s[j] = s[j + 1];

                    s[j + 1] = ns;

                }

            }

            else if (s[j + 1] >= 97) {

                if ((s[j] > s[j + 1] - 32)) {

                    ns = s[j];

                    s[j] = s[j + 1];

                    s[j + 1] = ns;

                }

            }

        }

    }

    cout << s;

}



void dz4_1() {
    ofstream f1;
    ifstream f2;
    string s, buf = "", a;
    double sm = 0;
    bool t = true;
    f1.open("numeral.txt");
    for (int i = 0; i < 10; i++) {
        cin >> a;
        if (CustomIsDigits(a)) {
            f1 << a << " ";
        }
        else {
            t = false;
            cout << "Неверные данные";
            break;
        }
    }
    f1.close();
    if (t) {
        f2.open("numeral.txt");
        while (getline(f2, s)) {
            for (int i = 0; i < size(s); i++) {
                if (s[i] != ' ') {
                    buf += s[i];
                }
                else {
                    sm += stod(buf);
                    buf = "";
                }
            }
        }
        cout << sm;
    }
    f2.close();
}

int k(double x) {
    if (x == 0) {

        return 0;

    }

    else if (x < 0) {

        return -1;

    }

    else {

        return 1;

    }
}

void dz4_2() {

    double x;

    cin >> x;

    cout << k(x);

}



void circle() {

    double r;

    cout << "Введите радиус круга" << endl;

    cin >> r;

    if (r <= 0)

        cout << "Такого круга не существует" << endl;

    else cout << 3.14159 * r * r << endl;

}



void triangle() {

    double a, b, c, p;

    cout << "Ведите стороны треугольника" << endl;

    cin >> a >> b >> c;

    if ((a + b <= c) || (c + b <= a) || (a + c <= b) || (a <= 0) || (b <= 0) || (c <= 0)) {

        cout << "Такого треугольника не существует" << endl;

    }

    else {

        p = (a + b + c) / 2;

        cout << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;

    }

}



void rectangle() {

    double a, b;

    cout << "Ведите стороны прямоугольника" << endl;

    cin >> a >> b;

    if (a <= 0 || b <= 0) {

        cout << "Такого прямоугольника не существует" << endl;

    }

    else {

        cout << a * b << endl;

    }

}



void dz4_3() {

    int name;

    cout << "Какое количество углов имеет фигура?" << endl;

    cin >> name;

    switch (name) {

    case 0:

        circle();

        break;

    case 3:

        triangle();

        break;

    case 4:

        rectangle();

        break;

    default:

        cout << "Некорректные даные" << endl;

    }

}



void dz4_4() {
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int width = 90;
    int height = 60;
    SetConsoleTextAttribute(hconsole, 255);
    for (int i = 0; i < height / 3; i++) {
        for (int j = 0; j < width; j++) {
            cout << "#";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hconsole, 17);
    for (int i = 0; i < height / 3; i++) {
        for (int j = 0; j < width; j++) {
            cout << "#";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hconsole, 4 * 17);
    for (int i = 0; i < height / 3; i++) {
        for (int j = 0; j < width; j++) {
            cout << "#";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hconsole, 0);
}

void dz4_5() {
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    int a;
    cin >> a;
    for (int x = 100; x <= 100 + 1000; x++)
        SetPixel(hDC, x, 300 + 250, RGB(255, 255, 255));
    for (int y = 300; y <= 300 + 500; y++)
        SetPixel(hDC, 100 + 500, y, RGB(255, 255, 255));
    for (float x = -500.; x <= 500.; x+=0.01) {
        SetPixel(hDC, (int) x + 600, (int) (sin(x / a) * 100 + 550), RGB(255, 255, 255));
    }
}

int fromRoman(string n) {
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int tmp = 0;
    int res = 0;
    for (char c : n) {
        int k = m[c];
        if (k < tmp) {
            res += tmp;
            tmp = k;
        }
        else if (k > tmp) {
            if (tmp == 0)
                tmp = k;
            else {
                res += k - tmp;
                tmp = 0;
            }
        }
        else {
            res += tmp + k;
            tmp = 0;
        }
    }
    return res + tmp;
}

string toRoman(int x) {
    string res = "";
    int n = x;
    int i = 12;
    int arab[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string roman[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    while (n > 0) {
        while (arab[i] > n) {
            i--;
        }
        res += roman[i];
        n -= arab[i];
    }
    return res;
}

void dz4_6() {
    cout << "Введите число для расшифровки" << endl;
    string Rome;
    cin >> Rome;
    int n = fromRoman(Rome);
    if (toRoman(n) == Rome)
        cout << n;
    else
        cout << "Неверное число в римской записи";
}

void dz4_7_1() {
    int Si = 0, i, m, c;
    cout << "Введите значения m, i, c для генерирования" << endl;
    cin >> m >> i >> c;
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        Si = (m * Si + i) % c;
        cout << Si << endl;
    }
}

void dz4_8() {
    double sellers[3][4];
    double good[4][2];
    double result[3][2];
    double a = 0;
    double mxv = 0, mnv = 999999999999999, mxk = 0, mnk = 999999999999, smv = 0, smk = 0;
    int indmxv = 0, indmnv = 0, indmxk = 0, indmnk = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
        }
    }
    cout << "Введите данные о продавйах" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a;
            sellers[i][j] = a;
        }
    }
    cout << "Введите данные о товарах" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a;
            good[i][j] = a;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int f = 0; f < 4; f++) {
                result[i][j] += sellers[i][f] * good[f][j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        smv += result[i][0];
        smv += result[i][1];
        if (result[i][1] > mxv) {
            mxv = result[i][0];
            indmxv = i + 1;
        }
        if (result[i][1] < mnv) {
            mnv = result[i][0];
            indmnv = i + 1;
        }
        if (result[i][1] > mxk) {
            mxk = result[i][1];
            indmxk = i + 1;
        }
        if (result[i][1] < mnk) {
            mnk = result[i][1];
            indmnk = i + 1;
        }
    }
    cout << indmxv << " продавец получил больше всего денег" << endl;
    cout << indmnv << " продавец получил меньше всего денег" << endl;
    cout << indmxk << " продавец получил больше всего комиссионных" << endl;
    cout << indmnk << " продавец получил меньше всего комиссионных" << endl;
    cout << "Общая сумма денег: " << smv << endl;
    cout << "Общая сумма комиссионных: " << smk << endl;
    cout << "Всего денег прошло через продавов: " << smk + smv << endl;
}

void dz4_9() {
    int osn = 0, osnk;
    string number, num = "";
    int ch = 0;
    string buf = "";
    cout << "Введите число, его основание и основание, в которое надо перевести число" << endl;
    cin >> number >> osn >> osnk;
    int raz = number.size() - 1;
    for (char c : number) {
        if (c < 58)
            num = num + c + " ";
        else
            switch (c) {
                case 'A':
                    num += "10 ";
                    break;
                case 'B':
                    num += "11 ";
                    break;
                case 'C':
                    num += "12 ";
                    break;
                case 'D':
                    num += "13 ";
                    break;
                case 'E':
                    num += "14 ";
                    break;
                case 'F':
                    num += "15 ";
                    break;
            }
    }
    if (osn != 10) {
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != ' ') {
                buf += num[i];
            }
            else {
                ch += stoi(buf) * pow(osn, raz);
                buf = "";
                raz--;
            }
        }
    }
    else ch = stoi(number);
    number = "";
    while (ch > 0) {
        switch (ch % osnk) {
            case 0:
                number += '0';
                break;
            case 1:
                number += '1';
                break;
            case 2:
                number += '2';
                break;
            case 3:
                number += '3';
                break;
            case 4:
                number += '4';
                break;
            case 5:
                number += '5';
                break;
            case 6:
                number += '6';
                break;
            case 7:
                number += '7';
                break;
            case 8:
                number += '8';
                break;
            case 9:
                number += '9';
                break;
            case 10:
                number += 'A';
                break;
            case 11:
                number += 'B';
                break;
            case 12:
                number += 'C';
                break;
            case 13:
                number += 'D';
                break;
            case 14:
                number += 'E';
                break;
            case 15:
                number += 'F';
                break;
        }
        ch /= osnk;
    }
    for (int i = number.size() - 1; i > -1; i--)
        cout << number[i];
}

void dz5_1() {
    int a, b;
    cout << "Ведите числа для нахождения НОД:" << endl;
    cin >> a >> b;
    while (a != 0 and b != 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    cout << a + b << endl;
}

void dz5_2() {
    int n, m, j;
    cout << "До какого числа найти простые числа?" << endl;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    a[1] = 0;
    m = 2;
    while (m < n) {
        if (a[m] != 0) {
            j = m * 2;
            while (j < n) {
                a[j] = 0;
                j += m;
            }
             m++;
        }
        else
            m++;
    }
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            cout << a[i] << " ";
}

bool f(char c, string a) {
    for (char b : a)
        if (b == c)
            return true;
    return false;
}

void dz5_3_23() {
    ofstream f1;
    string line, alphabit = "bcdfghjklmnpqrstvwxz", b;
    int mx = 0;
    map <char, int> m;
    f1.open("file1.txt");
    if (f1.is_open())
        f1 << ";;;;;;;;bbb;;;;aaa;;jkdshfgjksdfjgbsSDKLJFGNKSDLJFGNDSFJKGfffNJK";
    f1.close();
    ifstream f2 ("file1.txt");
    if (f2.is_open())
        while (getline(f2, line)) {
            for (char c : line) {
                c = tolower(c);
                m[c]++;
                if (m[c] > mx && f(c, alphabit)) {
                    mx = m[c];
                    b = c;
                }
            }
        }
    f2.close();
    cout << b;
}

void dz5_3_17() {
    string line, words = "", s;
    ofstream f1;
    int n = 0;
    f1.open("file2.txt");
    if (f1.is_open())
        f1 << "dsjgn sdjkfby uydfsgv sdaokfk ysdgfvyu sdnfj sydgvuy dslknflk yusfgvbuy";
    f1.close();
    ifstream f2;
    f2.open("file2.txt");
    while (getline(f2, line)) {
        words += (line + " ");
    }
    f2.close();
    string lst[9999];
    for (char c : words) {
        if (c != ' ') {
            s += c;
        }
        else {
            lst[n] = s;
            n++;
            s = "";
        }
    }
    sort(lst, lst + n);
    for (int i = 0; i < n; i++)
        cout << lst[i] << " ";
}

int to10(char c) {
    string num = "0123456789ABCDEF";
    for (int i = 0; i < num.length(); i++) {
        if (c == num[i])
            return i;
    }
}

int from10(int c) {
    string num = "0123456789ABCDEF";
    return num[c];
}

void dz5_4_23() {
    int n, raz, num10 = 0;
    string num3, num6, a;
    cin >> n;
    string* a3 = new string[n];
    string* b6 = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> a;
        a3[i] = a;
    }
    for (int i = 0; i < n; i++) {
        num3 = a3[i];
        num6 = "";
        num10 = 0;
        raz = num3.length() - 1;
        for (char c : num3) {
            num10 += (to10(c) * pow(3, raz));
            raz--;
        }
        while (num10 > 0) {
            num6 += from10(num10 % 6);
            num10 /= 6;
        }
        reverse(num6.begin(), num6.end());
        b6[i] = num6;
    }
    for (int i = 0; i < n; i++)
        cout << b6[i] << " ";
}

double grade(double a, int n) {
    if (n == 0)
        return 1;
    for (int i = 0; i < n - 1; i++)
        a *= a;
    return a;
}

void dz5_4_17() {
    double E, y = 0;
    int n = 1;
    cin >> E;
    while (1 / grade(3, n) >= E) {
        y += (1 / grade(3, n) * grade(cos(grade(3, n - 1)), 3));
        n++;
    }
    cout << y;
}

int sm(int a[]) {
    int s = 0;
    for (int i = 0; i < 3; i++)
        s += a[i];
    return s;
}

void dz5_5_23() {
    int result[10][3], a, b, s;
    string countries[10]{"получила Австрия", "получила Германия", "получила Канада", "получил Китай", "получила Корея", "получила Норвегия", "получила Россия", "получил США", "получила Финляндия", "получила Япония"};
    ofstream f;
    f.open("file.xls");
    for (int i = 0; i < 10; i++) {
        b = 7;
        cout << "Сколько медалей " << countries[i] << endl;
        for (int j = 0; j < 3; j++) {
            cin >> a;
            result[i][j] = a * b;
            b--;
        }
    }
    for (int i = 1; i < 10; i++)
        for (int j = i; j > 0 && (sm(result[j - 1]) < sm(result[j])); j--) {
            swap(result[j], result[j - 1]);
            swap(countries[j], countries[j - 1]);
        }
    f << "\tСтрана\t" << "Золото\t" << "Серебро\t" << "Бронза\t" << "Всего\t" << "Очков" << endl;
    for (int i = 0; i < 10; i++) {
        if (i != 5 && i != 8)
            f << (i + 1) << "\t" << countries[i].substr(9, countries[i].length()) << "\t";
        else 
            f << (i + 1) << "\t" << countries[i].substr(8, countries[i].length()) << "\t";
        s = 0;
        b = 7;
        for (int j = 0; j < 3; j++) {
            f << result[i][j] / b << "\t";
            s += result[i][j] / b;
            b--;
        }
        f << s << "\t" << sm(result[i]) << endl;
    }
    f.close();
}

void dz5_5_51() {
    int n, m, a, s;
    cin >> n >> m;
    int** mas = new int * [n];
    for (int i = 0; i < n; i++)
        mas[i] = new int[m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> a;
            mas[i][j] = a;
        }
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < m; j++) {
            s += mas[i][j];
            cout << mas[i][j];
            if (j != m - 1)
                cout << " + ";
            else
                cout << " ";
        }
        cout << "=" << " " << s << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    //dz2_1();
    //dz2_2();
    //dz2_3();
    //dz2_4();
    //dz2_5();
    //dz3_1();
    //dz3_2();
    //dz3_3();
    //dz3_4();
    //dz3_5();
    //dz4_1(); Через запятаю мать твою!!!!!!!
    //dz4_2();
    //dz4_3();
    //dz4_4();
    //dz4_5();
    //dz4_6();
    //dz4_7();
    //dz4_8();
    //dz4_9();
    //dz5_1();
    //dz5_2();
    //dz5_3_23();
    //dz5_3_17();
    //dz5_4_23();
    //dz5_4_17();
    //dz5_5_23();
    //dz5_5_51();
    return 0;
}

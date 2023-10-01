#include <iostream>
#include <stack>
#include <string>

using namespace std;

// fungsi untuk mengubah desimal ke biner menggunakan stack
void biner(int n)
{
    stack<int> s;
    while (n > 0)
    {
        int rem = n % 2;
        s.push(rem);
        n /= 2;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

// fungsi untuk mengubah desimal ke oktal menggunakan stack
void oktal(int n)
{
    stack<int> s;
    while (n > 0)
    {
        int rem = n % 8;
        s.push(rem);
        n /= 8;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

// fungsi untuk mengubah desimal ke heksadesimal menggunakan stack
void hexa(int n)
{
    stack<char> s;
    while (n > 0)
    {
        int rem = n % 16;
        if (rem < 10)
        {
            s.push(rem + '0');
        }
        else
        {
            s.push(rem - 10 + 'A');
        }
        n /= 16;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

// Fungsi untuk membalik kalimat menggunakan stack
string reverseSentence(const string &kalimat)
{
    stack<char> s;

    // Memasukkan setiap karakter ke dalam stack
    for (char c : kalimat)
    {
        s.push(c);
    }

    string hasil = "";

    // Mengeluarkan karakter dari stack untuk membalik kalimat
    while (!s.empty())
    {
        hasil += s.top();
        s.pop();
    }

    return hasil;
}

// Fungsi untuk mengecek apakah suatu kata adalah palindrom atau bukan
bool isPalindrome(const string &kata)
{
    stack<char> s;

    // Memasukkan setiap karakter ke dalam stack
    for (char c : kata)
    {
        s.push(c);
    }

    string reversed = "";

    // Mengeluarkan karakter dari stack untuk membalik kata
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    // Membandingkan kata asli dengan kata yang sudah dibalik
    if (kata == reversed)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Fungsi untuk mengecek apakah suatu karakter adalah operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}

// Fungsi untuk menentukan prioritas operator
int getPriority(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

// Fungsi untuk konversi notasi infix ke postfix
string infixToPostfix(const string &infix)
{
    stack<char> s;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(c))
        {
            while (!s.empty() && getPriority(c) <= getPriority(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Fungsi untuk melakukan operasi pada operand dengan dua angka dari stack
int performOperation(char operation, int operand1, int operand2)
{
    if (operation == '+')
    {
        return operand1 + operand2;
    }
    else if (operation == '-')
    {
        return operand1 - operand2;
    }
    else if (operation == '*')
    {
        return operand1 * operand2;
    }
    else if (operation == '/')
    {
        if (operand2 != 0)
        {
            return operand1 / operand2;
        }
        else
        {
            throw "Error: Pembagian dengan nol tidak valid.";
        }
    }
    throw "Error: Operator tidak valid.";
}

// Fungsi untuk evaluasi notasi postfix
int evaluatePostfix(const string &postfix)
{
    stack<int> s;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else if (isOperator(c))
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            int result = performOperation(c, operand1, operand2);
            s.push(result);
        }
    }

    if (!s.empty())
    {
        return s.top();
    }

    throw "Error: Notasi postfix tidak valid.";
}

int main()
{
    int n, pilihan;
    string kalimat, infix;

    cout << "1. Konversi Desimal ke Biner, Octal, dan Hexadecimal" << endl;
    cout << "2. Membalik kalimat dan mengecek apakah kalimat adalah palindrom" << endl;
    cout << "3. Konversi notasi infix ke postfix" << endl;
    cout << "4. Evaluasi notasi postfix" << endl;
    cout << "Pilih: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
    {
        cout << "masukan bilangan desimal: ";
        cin >> n;
        cout << "Binary: ";
        biner(n);
        cout << endl;
        cout << "Octal: ";
        oktal(n);
        cout << endl;
        cout << "Hexadecimal: ";
        hexa(n);
        cout << endl;
    }

    break;

    case 2:
    {
        cout << "Masukkan kalimat: ";
        cin.ignore();
        getline(cin, kalimat);
        string reversed = reverseSentence(kalimat);
        cout << "Kalimat yang dibalik: " << reversed << endl;
        if (isPalindrome(kalimat))
        {
            cout << "Kalimat adalah palindrom" << endl;
        }
        else
        {
            cout << "Kalimat bukan palindrom" << endl;
        }
    }

    break;

    case 3:
    {
        cout << "Masukkan notasi infix: ";
        cin.ignore();
        getline(cin, infix);
        string postfix = infixToPostfix(infix);
        cout << "Notasi postfix: " << postfix << endl;
    }
    break;

    case 4:
    {
        cout << "Masukkan notasi postfix: ";
        cin.ignore();
        getline(cin, infix);
        int result = evaluatePostfix(infix);
        cout << "Hasil evaluasi: " << result << endl;
    }
    break;

    default:
        cout << "Pilihan tidak tersedia" << endl;
        break;
    }
    return 0;
}
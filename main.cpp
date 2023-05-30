#include "string.h"
#include <iostream>
using std::cout;
using std::cin;
using std::copy;
using std::fill;
using std::swap;
using std::endl;
using std::ostream;
using std::istream;

class SowlString {
private:
    size_t s_size;
    char* s_str = nullptr;

public:

    SowlString() = default;

    SowlString(int c, size_t size) = delete;

    SowlString(char c, size_t size) : s_size(size), s_str(new char[size+1])
    {
        fill(s_str, s_str + s_size, c);
        for(int i =0; i < s_size; i++) s_str[i] = c;
        s_str[s_size] = 0;
    }

    SowlString(char* str) : s_size(strlen(str)), s_str(new char[s_size+1])
    {;
        copy(str, str+s_size, s_str);
        s_str[s_size] = 0;
    }

    SowlString(const SowlString& other) : SowlString(other.s_str){}

    SowlString& operator=(SowlString temp)
    {
        swap(s_size, temp.s_size);
        swap(s_str, temp.s_str);
        return *this;
    }

    char& operator[](size_t pos)
    {
        return s_str[pos];
    }

    char& at(size_t pos){
        if(pos >= s_size)
        {
            cout << "out_of_range";
        }
        else return this->s_str[pos];
    }

    int find(SowlString what)
    {
        for(int i = 0; i < s_size - what.length() + 1; i++)
        {
            bool ok = true;
            for (int j = 0; j < what.length(); j++)
                if (s_str[i + j] != what.at(j))
                {
                    j = what.length();
                    ok = false;
                }
            if (ok) return i;
        }
        return -1;
    }

    friend bool operator<(const SowlString &str1, const SowlString &str2)
    {
        return (std::strcmp(str1.s_str, str2.s_str) < 0);
    }

    friend bool operator>(const SowlString &st1, const SowlString &st2)
    {
        return st2 < st1;
    }

    friend bool operator==(const SowlString &str1, const SowlString &str2)
    {
        return (std::strcmp(str1.s_str, str2.s_str) == 0);
    }

    friend ostream& operator<<(ostream& os, const SowlString& str)
    {
        os << str.s_str;
        return os;
    }

    friend istream& operator>>(istream& is, SowlString& str)
    {
        char temp[256];
        is.get(temp, 256);
        if (is) str = temp;
        while (is && is.get() != '\n')
            continue;
        return is;
    }


    size_t length() const
    {
        return s_size;
    }

    char* c_str() const
    {
        return s_str;
    }

    void Print() const
    {
        for (int i = 0; i < s_size; i++)
            cout << s_str[i];
        cout << endl;
    }

    ~SowlString() {
        if(s_str != nullptr)
            delete[] s_str;
    }
};

void f(const SowlString& s)
{
    s.Print();
}

int main()
{
    SowlString s1("Hi, World");
    SowlString s2("test");
    SowlString s3("teso");
    s3 = s2 = s1;
    cout << s2.at(200) << endl;
    cout << s1[4] << " -> " << 'L' << endl;
    s1[4] = 'L';

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    SowlString s4 = "World";
    cout << s3.find(s4) << endl;

    cout << s2.length()<< " " << s2.c_str()<< endl;

    cin >> s3;
    s3.Print();
    return 0;
}
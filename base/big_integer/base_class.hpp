#include <iostream>
#include <vector>
#include <cstring>

#define MAX_INTEGER_LENGTH 50
#define MAX_DECIMAL_LENGTH 50
#define END_ON_BASE 10

typedef int length_type;
typedef char digit_type;

class big_integer{

    // private:
public:
    bool is_negetive=false;
    length_type integer_length=0;
    std::vector <digit_type> integer_part={};

public:
    big_integer();
    big_integer(const int &number);
    big_integer(const big_integer &number);
    big_integer(const std::string &number);
    big_integer(const char *number);
    ~big_integer();
    void operator=(const int &number);
    void operator=(const big_integer &number);
    void operator=(const std::string &number);
    void operator=(const char *number);
    friend std::istream &operator>>(std::istream &in,big_integer &number);
    friend std::ostream &operator<<(std::ostream &out,big_integer &number);
    bool operator==(const big_integer &number);
    bool operator!=(const big_integer &number);
    bool operator>(const big_integer &number);
    bool operator>=(const big_integer &number);
    bool operator<(const big_integer &number);
    bool operator<=(const big_integer &number);
    big_integer operator++();
    big_integer operator--();
    big_integer operator+(const big_integer &number);
    big_integer operator+(const int &number);
    big_integer operator+=(const big_integer &number);
    big_integer operator+=(const int &number);
    // high_accur operator-(const high_accur &number);
    // high_accur operator*(const high_accur &number);
    // high_accur operator/(const high_accur &number);

private:
    void add_high_accur(const big_integer &number1,const big_integer &number2);
    void add_int(const big_integer &number,const int &number1);
    void subtraction(big_integer &number1,big_integer &number2);
    void multiplication(big_integer &number1,big_integer &number2);
    void division(big_integer &number1,big_integer &number2);

};


#include "declaration/input_and_output.cpp"
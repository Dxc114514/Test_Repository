#include <bits/stdc++.h>

#define END_ON_BASE 10

typedef int length_type;
typedef unsigned char digit_type;

class big_integer {

  public:
    bool positivity;
    length_type integer_length;
    std::vector<digit_type> integer_part;

  public:
    big_integer();
    big_integer(const int &number);
    big_integer(const char *number);
    big_integer(const std::string &number);
    big_integer(const big_integer &number);

    void operator=(const int &number);
    void operator=(const big_integer &number);
    void operator=(const std::string &number);
    void operator=(const char *number);

    friend std::istream &operator>>(std::istream &in, big_integer &number);
    friend std::ostream &operator<<(std::ostream &out, big_integer &number);

    bool operator==(const big_integer &number);
    bool operator!=(const big_integer &number);
    bool operator>(const big_integer &number);
    bool operator>=(const big_integer &number);
    bool operator<(const big_integer &number);
    bool operator<=(const big_integer &number);

    big_integer operator++();
    big_integer operator+(const int &number);
    big_integer operator+=(const int &number);
    big_integer operator+(const big_integer &number);
    big_integer operator+=(const big_integer &number);

    // high_accur operator-(const high_accur &number);
    // high_accur operator*(const high_accur &number);
    // high_accur operator/(const high_accur &number);

  private:
    void recaculate_length(const length_type &max_length);

    void add_int(const big_integer &number, const int &number1);
    void add_high_accur(const big_integer &number1, const big_integer &number2);

    // void subtraction(big_integer &number1,big_integer &number2);
    // void multiplication(big_integer &number1,big_integer &number2);
    // void division(big_integer &number1,big_integer &number2);

};


#include "declaration/io.cpp"

#include "declaration/comparision_operator.cpp"


/// @brief construct an empty number
BigInteger::BigInteger() {
    this->positivity = false;
    this->integerLength = 0;
    this->integerPart.clear();
    return;
}



/// @brief construct a number from a integer
/// @param number the number to be equaled
BigInteger::BigInteger(const int &number) {
    this->positivity = false;
    this->integerLength = 0;
    this->integerPart.clear();
    int tmp_number = number;
    if (tmp_number < 0) {
        this->positivity = true;
        tmp_number = -tmp_number;
    }
    while (tmp_number > 0) {
        this->integerPart.push_back(tmp_number % END_ON_BASE);
        this->integerLength++;
        tmp_number /= END_ON_BASE;
    }
    return;
}



/// @brief construct a number from a BigInteger
/// @param number the number to be copied
BigInteger::BigInteger(const BigInteger &number) {
    this->positivity = number.positivity;
    this->integerLength = number.integerLength;
    this->integerPart = number.integerPart;
}



/// @brief construct a number from std::string
/// @param number the number to be equaled
BigInteger::BigInteger(const std::string &number) {
    this->positivity = false;
    this->integerLength = 0;
    this->integerPart.clear();
    int i = number.length() - 1, end = 0;
    // if is negetive number
    if (number[0] == '-') end++, this->positivity = true;
    int tmp = 0;
    for (; i >= end; i--) {
        if ((tmp = this->transCharToDec(number[i])) != digit_type(-1)) {
            this->integerPart.push_back(tmp);
            this->integerLength++;
        } else {
            throw(BigIntegerException("illegal input"));
        }
    }
}



/// @brief construct a number from char array
/// @param number the number to be equaled
BigInteger::BigInteger(const char *&number) {
    this->positivity = false;
    this->integerLength = 0;
    this->integerPart.clear();
    int i = strlen(number) - 1, end = 0;
    // if is negetive number
    if (number[0] == '-') end++, this->positivity = true;
    int tmp = 0;
    for (; i >= end; i--) {
        if ((tmp = this->transCharToDec(number[i])) != digit_type(-1)) {
            this->integerPart.push_back(tmp);
            this->integerLength++;
        } else {
            throw(BigIntegerException("illegal input"));
        }
    }
}



/// @brief constrcut a number from std::string
/// @param number the number to be equaled
void BigInteger::operator=(const int &number) {
    this->positivity = false;
    this->integerLength = 0;
    this->integerPart.clear();
    int tmp_number = number;
    if (tmp_number < 0) {
        this->positivity = true;
        tmp_number = -tmp_number;
    }
    while (tmp_number > 0) {
        this->integerPart.push_back(tmp_number % END_ON_BASE);
        this->integerLength++;
        tmp_number /= END_ON_BASE;
    }
    return;
}



/// @brief construct a number from BigInteger
/// @param number the number to be copied
void BigInteger::operator=(const BigInteger &number) {
    this->positivity = number.positivity;
    this->integerLength = number.integerLength;
    this->integerPart = number.integerPart;
    return;
}



/// @brief construct a number from std::string
/// @param number the number to be equaled
void BigInteger::operator=(const std::string &number) {
    this->positivity = false;
    this->integerLength = 0;
    this->integerPart.clear();
    int i = number.length() - 1, end = 0;
    // if is negetive number
    if (number[0] == '-') end++, this->positivity = true;
    int tmp = 0;
    for (; i >= end; i--) {
        if ((tmp = this->transCharToDec(number[i])) != digit_type(-1)) {
            this->integerPart.push_back(tmp);
            this->integerLength++;
        } else {
            throw(BigIntegerException("illegal input"));
        }
    }
}



/// @brief construct a number from char array
/// @param number the number to be equaled
void BigInteger::operator=(const char *&number) {
    this->positivity = false;
    this->integerLength = 0;
    this->integerPart.clear();
    int i = strlen(number) - 1, end = 0;
    // if is negetive number
    if (number[0] == '-') end++, this->positivity = true;
    int tmp = 0;
    for (; i >= end; i--) {
        if ((tmp = this->transCharToDec(number[i])) != digit_type(-1)) {
            this->integerPart.push_back(tmp);
            this->integerLength++;
        } else {
            throw(BigIntegerException("illegal input"));
        }
    }
    return;
}



/// @brief the override of std::istream so that can use cin >>
/// @param in the std::istream parameter
/// @param number the BigIteger number need to be inputed
/// @return an std::istream parameter
std::istream &operator>>(std::istream &in, BigInteger &number) {
    std::string tmpString;
    in >> tmpString;
    number = tmpString;
    return in;
}



/// @brief the override of std::ostream so that can use cout <<
/// @param out std::ostream parameter
/// @param number the BigIteger number need to be inputed
/// @return an std::ostream parameter
std::ostream &operator<<(std::ostream &out, BigInteger &number) {
    if (number.positivity == true) {
        out << "-";
    }
    for (int i = number.integerLength - 1; i >= 0; i--) {
        out << int(number.integerPart[i]);
    }
    return out;
}

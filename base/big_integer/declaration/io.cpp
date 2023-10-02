
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
    int tmp_number = number;
    if (tmp_number < 0) {
        this->positivity = true;
        tmp_number = -tmp_number;
    }
    while (tmp_number > 0) {
        this->integerPart.push_back(tmp_number % END_ON_BASE);
        tmp_number /= END_ON_BASE;
    }
    this->integerLength = this->integerPart.size();
    return;
}


/// @brief construct a number from a BigInteger
/// @param number the number to be copied
BigInteger::BigInteger(const BigInteger &number) {
    this->positivity = number.positivity;
    this->integerLength = number.integerLength;
    this->integerPart = number.integerPart;
}



BigInteger::BigInteger(const std::string &number) {
    if (number.empty()) {   
        this->positivity = false;
        this->integerLength = 0;
        this->integerPart.clear();
    }
    int i = this->integerLength - 1, end = 0;
    // if is negetive number
    if (number[0] == '-') i++, end++;
    for (; i >= end; i--) {
        if (isdigit(number[i])) {
            this->integerPart.push_back(number[i] - '0');
        } else if (isupper(number[i])) {
            this->integerPart.push_back(number[i] - 'A' + 10);
        } else if (islower(number[i])) {
            this->integerPart.push_back(number[i] - 'a' + 10);
        } else {
            throw(BigIntegerException("illegal input"));
        }
    }
}


void BigInteger::operator=(const int &number) {
    int tmp_number = number;
    while (tmp_number > 0) {
        this->integerPart.push_back(tmp_number % END_ON_BASE);
        tmp_number /= END_ON_BASE;
    }
    this->integerLength = this->integerPart.size();
    return;
}

void BigInteger::operator=(const BigInteger &number) {
    this->positivity = number.positivity;
    this->integerLength = number.integerLength;
    this->integerPart = number.integerPart;
    return;
}



std::istream &operator>>(std::istream &in, BigInteger &number) {
    std::string tmp_string;
    in >> tmp_string;
    number = tmp_string;
    return in;
}

std::ostream &operator<<(std::ostream &out, BigInteger &number) {
    if (number.positivity == true) {
        std::cout << '-';
    }
    for (int i = number.integerLength - 1; i >= 0; i--) {
        std::cout << int(number.integerPart[i]);
    }
    return out;
}
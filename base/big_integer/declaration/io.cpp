
big_integer::big_integer() {
    this->is_negetive = false;
    this->integer_length = 0;
    this->integer_part.empty();
    return;
}

big_integer::big_integer(const int &number) {
    int tmp_number = number;
    if (tmp_number <= 0) {
        this->positivity = -1;
        tmp_number = -tmp_number;
    }
    while (tmp_number > 0) {
        this->integer_part.push_back(tmp_number % END_ON_BASE);
        tmp_number /= END_ON_BASE;
    }
    this->integer_length = this->integer_part.size();
    return;
}

big_integer::big_integer(const big_integer &number) {
    this->is_negetive = number.is_negetive;
    this->integer_length = number.integer_length;
    this->integer_part = number.integer_part;
}

big_integer::big_integer(const std::string &number) {
    if (isdigit(number[0])) {
        this->integer_length = number.length();
        for (int i = this->integer_length - 1; i >= 0; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            }
        }
    } else if (number[0] == '-') {
        this->is_negetive = true;
        this->integer_length = number.length() - 1;
        for (int i = this->integer_length; i >= 1; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            }
        }
    }
    return;
}

big_integer::big_integer(const char *number) {
    if (isdigit(number[0])) {
        this->integer_length = strlen(number);
        for (int i = this->integer_length - 1; i >= 0; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            }
        }
    } else if (number[0] == '-') {
        this->is_negetive = true;
        this->integer_length = strlen(number) - 1;
        for (int i = this->integer_length; i >= 1; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            }
        }
    }
    return;
}

void big_integer::operator=(const int &number) {
    int tmp_number = number;
    while (tmp_number > 0) {
        this->integer_part.push_back(tmp_number % END_ON_BASE);
        tmp_number /= END_ON_BASE;
    }
    this->integer_length = this->integer_part.size();
    return;
}

void big_integer::operator=(const big_integer &number) {
    this->is_negetive = number.is_negetive;
    this->integer_length = number.integer_length;
    this->integer_part = number.integer_part;
}

void big_integer::operator=(const std::string &number) {
    if (isdigit(number[0])) {
        this->integer_length = number.length();
        for (int i = this->integer_length - 1; i >= 0; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            }
        }
    } else if (number[0] == '-') {
        this->is_negetive = true;
        this->integer_length = number.length() - 1;
        for (int i = this->integer_length; i >= 1; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            }
        }
    }
    return;
}

void big_integer::operator=(const char *number) {
    if (isdigit(number[0])) {
        this->integer_length = strlen(number);
        for (int i = this->integer_length - 1; i >= 0; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            } else {
                throw "illegal_input";
            }
        }
    } else if (number[0] == '-') {
        this->is_negetive = true;
        this->integer_length = strlen(number) - 1;
        for (int i = this->integer_length; i >= 1; i--) {
            if (isdigit(number[i])) {
                this->integer_part.push_back(number[i] - '0');
            } else if (isupper(number[i])) {
                this->integer_part.push_back(number[i] - 'A' + 10);
            } else if (islower(number[i])) {
                this->integer_part.push_back(number[i] - 'a' + 10);
            } else {
                throw "illegal_input";
            }
        }
    } else {
        throw "illegal_input";
    }
    return;
}

std::istream &operator>>(std::istream &in, big_integer &number) {
    std::string tmp_string;
    in >> tmp_string;
    number = tmp_string;
    return in;
}

std::ostream &operator<<(std::ostream &out, big_integer &number) {
    if (number.is_negetive) {
        printf("-");
    }
    for (int i = number.integer_length - 1; i >= 0; i--) {
        printf("%d", number.integer_part[i]);
    }
    return out;
}
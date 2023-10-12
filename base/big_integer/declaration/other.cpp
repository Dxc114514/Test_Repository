



digit_type BigInteger::transCharToDec(const char &tmp_char) {
    if (isdigit(tmp_char)) {
        return int(tmp_char - '0');
    } else if (isupper(tmp_char)) {
        return int(tmp_char - 'A' + 10);
    } else if (islower(tmp_char)) {
        return int(tmp_char - 'a' + 10);
    }
    return -1;
}





// namespace StdBigInteger
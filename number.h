#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// binary 2^64 - 1
class Number
{
private:
    uint8_t signum;
    std::vector<uint32_t> mag;
    std::vector<uint32_t> scale;

public:
    Number();
    Number(int value) : Number(std::to_string(value)){};
    Number(long value) : Number(std::to_string(value)){};
    Number(long long value) : Number(std::to_string(value)){};
    Number(float value) : Number(std::to_string(value)){};
    Number(double value) : Number(std::to_string(value)){};
    Number(std::string value);

    Number operator+(const Number &B);
    Number operator-(const Number &B);
    Number operator*(const Number &B);
    Number operator/(const Number &B);
    Number operator%(const Number &B);

    Number operator^(const Number &B);
    Number operator&(const Number &B);
    Number operator|(const Number &B);

    Number operator~();
    Number operator>>();
    Number operator<<();

    Number operator++();
    Number operator++(int);
    Number operator--();
    Number operator--(int);

    Number operator+();
    Number operator-();

    bool operator&&(const Number &v);
    bool operator||(const Number &v);
    bool operator<(const Number &v);
    bool operator<=(const Number &v);
    bool operator>(const Number &v);
    bool operator>=(const Number &v);
    bool operator!=(const Number &v);
    bool operator==(const Number &v);

    bool operator!();

    Number &opetaror<<=();
    Number &opetaror>>=();

    Number &opetaror=(const int &v);
    Number &opetaror=(const long &v);
    Number &opetaror=(const long long &v);
    Number &opetaror=(const float &v);
    Number &opetaror=(const double &v);
    Number &opetaror=(const std::string &v);

    Number &opetaror+=(const Number &v);
    Number &opetaror+=(const int &v);
    Number &opetaror+=(const long &v);
    Number &opetaror+=(const long long &v);
    Number &opetaror+=(const float &v);
    Number &opetaror+=(const double &v);
    Number &opetaror+=(const std::string &v);

    Number &opetaror-=(const Number &v);
    Number &opetaror-=(const int &v);
    Number &opetaror-=(const long &v);
    Number &opetaror-=(const long long &v);
    Number &opetaror-=(const float &v);
    Number &opetaror-=(const double &v);
    Number &opetaror-=(const std::string &v);

    Number &opetaror*=(const Number &v);
    Number &opetaror*=(const int &v);
    Number &opetaror*=(const long &v);
    Number &opetaror*=(const long long &v);
    Number &opetaror*=(const float &v);
    Number &opetaror*=(const double &v);
    Number &opetaror*=(const std::string &v);

    Number &opetaror/=(const Number &v);
    Number &opetaror/=(const int &v);
    Number &opetaror/=(const long &v);
    Number &opetaror/=(const long long &v);
    Number &opetaror/=(const float &v);
    Number &opetaror/=(const double &v);
    Number &opetaror/=(const std::string &v);

    Number &opetaror%=(const Number &v);
    Number &opetaror%=(const int &v);
    Number &opetaror%=(const long &v);
    Number &opetaror%=(const long long &v);
    Number &opetaror%=(const float &v);
    Number &opetaror%=(const double &v);
    Number &opetaror%=(const std::string &v);

    Number &opetaror^=(const Number &v);
    Number &opetaror^=(const int &v);
    Number &opetaror^=(const long &v);
    Number &opetaror^=(const long long &v);
    Number &opetaror^=(const float &v);
    Number &opetaror^=(const double &v);
    Number &opetaror^=(const std::string &v);

    Number &opetaror&=(const Number &v);
    Number &opetaror&=(const int &v);
    Number &opetaror&=(const long &v);
    Number &opetaror&=(const long long &v);
    Number &opetaror&=(const float &v);
    Number &opetaror&=(const double &v);
    Number &opetaror&=(const std::string &v);

    Number &opetaror|=(const Number &v);
    Number &opetaror|=(const int &v);
    Number &opetaror|=(const long &v);
    Number &opetaror|=(const long long &v);
    Number &opetaror|=(const float &v);
    Number &opetaror|=(const double &v);
    Number &opetaror|=(const std::string &v);

    operator int();
    operator long();
    operator long long();
    operator float();
    operator double();
    operator std::string();

    friend std::ostream &operator<<(std::ostream &output, const Number &N);
    friend std::istream &operator>>(std::istream &input, Number &N);
};
Number::Number()
{
    signum = 0;
    mag.push_back(0);
    scale.push_back(0);
}
Number::Number(std::string value)
{
    int cursor = 0, numDigits;
    const int len = value.length();

    if (len == 0)
        throw "Zero length BigInteger";

    // Check for at most one leading sign
    int sign = 1;
    int nindex = value.find_last_of('-');
    int pindex = value.find_last_of('+');
    if (nindex >= 0) {
        if (nindex != 0 || pindex >= 0) {
            throw "Illegal embedded sign character";
        }
        sign = -1;
        cursor = 1;
    } else if (pindex >= 0) {
        if (pindex != 0) {
            throw "Illegal embedded sign character";
        }
        cursor = 1;
    }
    if (cursor == len)
        throw "Zero length BigInteger";

    // Skip leading zeros and compute number of digits in magnitude
    while (cursor < len &&
           Character.digit(val.charAt(cursor), radix) == 0) {
        cursor++;
    }

    if (cursor == len) {
        signum = 0;
        mag.push_back(0);
//        scale.push_back(0);
        return;
    }

    numDigits = len - cursor;
    signum = sign;

    // Pre-allocate array of expected size. May be too large but can
    // never be too small. Typically exact.
    long numBits = ((numDigits * bitsPerDigit[radix]) >>> 10) + 1;
    if (numBits + 31 >= (1L << 32)) {
        reportOverflow();
    }
    int numWords = (int) (numBits + 31) >>> 5;
    int[] magnitude = new int[numWords];

    // Process first (potentially short) digit group
    int firstGroupLen = numDigits % digitsPerInt[radix];
    if (firstGroupLen == 0)
        firstGroupLen = digitsPerInt[radix];
    String group = val.substring(cursor, cursor += firstGroupLen);
    magnitude[numWords - 1] = Integer.parseInt(group, radix);
    if (magnitude[numWords - 1] < 0)
        throw new NumberFormatException("Illegal digit");

    // Process remaining digit groups
    int superRadix = intRadix[radix];
    int groupVal = 0;
    while (cursor < len) {
        group = val.substring(cursor, cursor += digitsPerInt[radix]);
        groupVal = Integer.parseInt(group, radix);
        if (groupVal < 0)
            throw new NumberFormatException("Illegal digit");
        destructiveMulAdd(magnitude, superRadix, groupVal);
    }
    // Required for cases where the array was overallocated.
    mag = trustedStripLeadingZeroInts(magnitude);
    if (mag.length >= MAX_MAG_LENGTH) {
        checkRange();
    }
}
Number Number::operator+(const Number &B)
{

}
Number Number::operator-(const Number &B)
{
}
Number Number::operator*(const Number &B)
{
}
Number Number::operator/(const Number &B)
{
}
std::ostream &operator<<(std::ostream &output, const Number &N)
{

    return output;
}
std::istream &operator>>(std::istream &input, Number &N)
{
    std::string value;

    return input;
}

class Expression
{
};
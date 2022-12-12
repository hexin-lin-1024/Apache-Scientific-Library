#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// binary 2^64 - 1
class Number
{
private:
    uint8_t signum;
    std::vector<uint64_t> mag;
    std::vector<uint64_t> scale;

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
    bool operator<=>(const Number &v);
    bool operator>(const Number &v);
    bool operator>=(const Number &v);
    bool operator!=(const Number &v);
    bool operator==(const Number &v);

    bool operator!();

    Number &opetaror <<= ();
    Number &opetaror >>= ();

    Number &opetaror = (const int &v);
    Number &opetaror = (const long &v);
    Number &opetaror = (const long long &v);
    Number &opetaror = (const float &v);
    Number &opetaror = (const double &v);
    Number &opetaror = (const std::string &v);

    Number &opetaror += (const Number &v);
    Number &opetaror += (const int &v);
    Number &opetaror += (const long &v);
    Number &opetaror += (const long long &v);
    Number &opetaror += (const float &v);
    Number &opetaror += (const double &v);
    Number &opetaror += (const std::string &v);

    Number &opetaror -= (const Number &v);
    Number &opetaror -= (const int &v);
    Number &opetaror -= (const long &v);
    Number &opetaror -= (const long long &v);
    Number &opetaror -= (const float &v);
    Number &opetaror -= (const double &v);
    Number &opetaror -= (const std::string &v);

    Number &opetaror *= (const Number &v);
    Number &opetaror *= (const int &v);
    Number &opetaror *= (const long &v);
    Number &opetaror *= (const long long &v);
    Number &opetaror *= (const float &v);
    Number &opetaror *= (const double &v);
    Number &opetaror *= (const std::string &v);

    Number &opetaror /= (const Number &v);
    Number &opetaror /= (const int &v);
    Number &opetaror /= (const long &v);
    Number &opetaror /= (const long long &v);
    Number &opetaror /= (const float &v);
    Number &opetaror /= (const double &v);
    Number &opetaror /= (const std::string &v);

    Number &opetaror %= (const Number &v);
    Number &opetaror %= (const int &v);
    Number &opetaror %= (const long &v);
    Number &opetaror %= (const long long &v);
    Number &opetaror %= (const float &v);
    Number &opetaror %= (const double &v);
    Number &opetaror %= (const std::string &v);

    Number &opetaror ^= (const Number &v);
    Number &opetaror ^= (const int &v);
    Number &opetaror ^= (const long &v);
    Number &opetaror ^= (const long long &v);
    Number &opetaror ^= (const float &v);
    Number &opetaror ^= (const double &v);
    Number &opetaror ^= (const std::string &v);

    Number &opetaror &= (const Number &v);
    Number &opetaror &= (const int &v);
    Number &opetaror &= (const long &v);
    Number &opetaror &= (const long long &v);
    Number &opetaror &= (const float &v);
    Number &opetaror &= (const double &v);
    Number &opetaror &= (const std::string &v);

    Number &opetaror |= (const Number &v);
    Number &opetaror |= (const int &v);
    Number &opetaror |= (const long &v);
    Number &opetaror |= (const long long &v);
    Number &opetaror |= (const float &v);
    Number &opetaror |= (const double &v);
    Number &opetaror |= (const std::string &v);

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
}
Number::Number(std::string value)
{
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
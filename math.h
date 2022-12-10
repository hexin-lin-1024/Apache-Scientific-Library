#include <iostream>
#include <vector>
#include <string>
class Number
{
public:
    std::vector<int> v;

    Number();
    Number(int value) : Number(std::to_string(value)){};
    Number(std::string value);

    Number operator+(const Number &B);

    friend std::ostream &operator<<(std::ostream &output, const Number &N)
    {
        for (int i = 0; i < N.v.size(); i++)
        {
            output << N.v[i];
        }
        return output;
    }

    friend std::istream &operator>>(std::istream &input, Number &N)
    {
        std::string value;
        input >> value;
        N.v.clear();
        for (int i = 0; i < value.length(); i++)
        {
            N.v.push_back(value[i] - 48);
        }
        return input;
    }
};
Number::Number()
{
    v.push_back(0);
}
Number::Number(std::string value)
{
    for (int i = 0; i < value.length(); i++)
    {
        v.push_back(value[i] - 48);
    }
}

Number Number::operator+(const Number &B)
{
    // for (int i = 0; i < value.length(); i++)
    // {
    //     v.push_back(value[i] - 48);
    // }
    Number A;
    A.v[0] = this->v[0] + B.v[0];
    return A;
}
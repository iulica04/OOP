#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    Complex result(real, imag);
    return result;
}

Complex& Complex::operator++()
{
    ++real_data;
    ++imag_data;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex old = *this;
    operator++();
    return old;
}

Complex& Complex::operator--()
{
    --real_data;
    --imag_data;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex old = *this;
    operator--();
    return old;
}

Complex operator+(const Complex& l, const Complex& r)
{
    Complex result(l.real() + r.real(), l.imag() + r.imag());
    return result;
}

Complex operator+(const Complex& l, double r)
{
    Complex q(r, 0);
    return l + q;
}

Complex operator+(double l, const Complex& r)
{
    return r + l;;
}

Complex operator-(const Complex& l, const Complex& r)
{
    Complex result(l.real() - r.real(), l.imag() - r.imag());
    return result;
}

Complex operator-(const Complex& l, double r)
{
    Complex q(r, 0);
    return l - q;
}

Complex operator-(double l, const Complex& r)
{
    return r + l;
}

Complex operator*(const Complex& l, const Complex& r)
{
    Complex result = Complex(l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag() + l.imag() * r.real());
    return result;
}

Complex operator*(const Complex& l, double r)
{
    Complex q(r, 0);
    return l * q;
}

Complex operator*(double l, const Complex& r)
{
    return r * l;
}

Complex operator-(const Complex& obj)
{
    double value = -1;
    return  value * obj;
}

bool operator==(const Complex& l, const Complex& r)
{
    Complex result = l - r;
    if (result.real() == 0 && result.imag() == 0)
        return true;
    else
        return false;

}

bool operator!=(const Complex& l, const Complex& r)
{
    return !(l == r);
}


std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if (complex.imag() > 0)
    {
        out << complex.real() << " + " << complex.imag() << 'i';
        return out;
    }
    else
        if (complex.imag() < 0)
        {
            out << complex.real() << " - " << (-1) * complex.imag() << 'i';
            return out;
        }
        else
            if (complex.imag() == 0)
            {
                out << complex.real();
                return out;
            }
            else
                if (complex.real() == 0)
                {
                    out << complex.imag() << 'i';
                    return out;
                }
}



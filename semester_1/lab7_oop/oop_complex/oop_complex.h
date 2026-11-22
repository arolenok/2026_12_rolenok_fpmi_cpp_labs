#pragma once

#include <cmath>
#include <iostream>

class Complex {
private:
    double re_;
    double im_;

public:
    Complex();
    Complex(double re, double im = 0.0);
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    Complex operator+() const;
    Complex operator-() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex operator+(const double& other) const;
    Complex operator-(const double& other) const;
    Complex operator*(const double& other) const;
    Complex operator/(const double& other) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex& operator+=(const double& other);
    Complex& operator-=(const double& other);
    Complex& operator*=(const double& other);
    Complex& operator/=(const double& other);

    double Real() const;
    double Imag() const;
    double Abs() const;

    void Real(double re);
    void Imag(double im);
};

std::ostream& operator<<(std::ostream& out, const Complex& c);
std::istream& operator>>(std::istream& in, Complex& c);
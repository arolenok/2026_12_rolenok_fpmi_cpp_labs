#include "oop_complex.h"

Complex::Complex() {
    re_ = 0.0;
    im_ = 0.0;
}

Complex::Complex(double re, double im) {
    re_ = re;
    im_ = im;
}

Complex::Complex(const Complex &other) {
    re_ = other.re_;
    im_ = other.im_;
}

Complex &Complex::operator=(const Complex &other) {
    re_ = other.re_;
    im_ = other.im_;
    return *this;
}



bool Complex::operator==(const Complex &other) const {
    return (im_ == other.im_ && re_ == other.re_);
}

bool Complex::operator!=(const Complex &other) const {
    return (!(*this == other));
}



Complex Complex::operator+() const {
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-re_, -im_);
}


Complex Complex::operator+(const Complex &other) const {
    return Complex(re_ + other.re_, im_ + other.im_);
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(re_ - other.re_, im_ - other.im_);
}

Complex Complex::operator*(const Complex &other) const {
    return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + other.re_ * im_);
}

Complex Complex::operator/(const Complex &other) const {
    const double denominator = other.re_ * other.re_ + other.im_ * other.im_;
    return Complex((re_ * other.re_ + im_ * other.im_)/denominator,(other.re_ * im_ - re_ * other.im_)/denominator);
}



Complex Complex::operator+(const double &other) const {
    return Complex(re_ + other, im_);
}

Complex Complex::operator-(const double &other) const {
    return Complex(re_ - other, im_);
}

Complex Complex::operator*(const double &other) const {
    return Complex(re_ * other, im_ * other);
}

Complex Complex::operator/(const double &other) const {
    return Complex(re_ / other, im_ / other);
}


Complex& Complex::operator+=(const Complex &other) {
    im_ += other.im_;
    re_ += other.re_;
    return *this;
}

Complex& Complex::operator-=(const Complex &other) {
    im_ -= other.im_;
    re_ -= other.re_;
    return *this;
}

Complex& Complex::operator*=(const Complex &other) {
    Complex result = *this * other;
    im_ = result.im_;
    re_ = result.re_;
    return *this;
}

Complex& Complex::operator/=(const Complex &other) {
    Complex result = *this / other;
    im_ = result.im_;
    re_ = result.re_;
    return *this;
}


Complex& Complex::operator+=(const double &other) {
    re_ += other;
    return *this;
}

Complex& Complex::operator-=(const double &other) {
    re_ -= other;
    return *this;
}

Complex& Complex::operator*=(const double &other) {
    re_ *= other;
    im_ *= other;
    return *this;
}

Complex& Complex::operator/=(const double &other) {
    re_ /= other;
    im_ /= other;
    return *this;
}




double Complex::Real() const {
    return re_;
}

double Complex::Imag() const {
    return im_;
}

double Complex::Abs() const {
    return std::sqrt(re_ * re_ + im_ * im_);
}



void Complex::Real(const double re) {
    re_ = re;
}

void Complex::Imag(const double im) {
    im_ = im;
}



std::ostream& operator<<(std::ostream& out, const Complex& c) {
    const double re = c.Real();
    const double im = c.Imag();

    if (im == 0) {
        return out << re;
    }

    if (re != 0) {
        out << re;
        if (im > 0) {
            out << '+';
        }
    }

    if (im == -1) {
        out << '-';
    } else if (im != 1) {
        out << im;
    }

    return out << 'i';
}

std::istream &operator>>(std::istream &in, Complex &c) {
    double re;
    double im;

    if (in >> re >> im) {
        c = Complex(re, im);
    }

    return in;
}

#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>
#include <random>

// Абстрактный базовый класс кривых
class Curve {
public:
    virtual ~Curve() {}

    virtual double radius() const = 0; // Возвращает радиус кривой
    virtual double x(double t) const = 0;
    virtual double y(double t) const = 0;
    virtual double z(double t) const = 0;

    virtual double dx(double t) const = 0;
    virtual double dy(double t) const = 0;
    virtual double dz(double t) const = 0;

};

// Класс круга
class Circle : public Curve {
public:
    Circle(double radius) : radius_(radius) {}

    double radius() const override { return radius_; }

    double x(double t) const override { return radius_ * std::cos(t); }
    double y(double t) const override { return radius_ * std::sin(t); }
    double z(double t) const override { return 0; }

    double dx(double t) const override { return -radius_ * std::sin(t); }
    double dy(double t) const override { return radius_ * std::cos(t); }
    double dz(double t) const override { return 0; }

private:
    double radius_;
};

// Класс эллипса
class Ellipse : public Curve {
public:
    Ellipse(double a, double b) : a_(a), b_(b) {}

    double radius() const override { return (a_, b_) / 2; }
    double x(double t) const override { return a_ * std::cos(t); }
    double y(double t) const override { return b_ * std::sin(t); }
    double z(double t) const override { return 0; }

    double dx(double t) const override { return -a_ * std::sin(t); }
    double dy(double t) const override { return b_ * std::cos(t); }
    double dz(double t) const override { return 0; }

private:
    double a_;
    double b_;
};

// Класс трехмерной спирали
class Helix : public Curve {
public:
    Helix(double radius, double step) : radius_(radius), step_(step) {}

    double radius() const override { return radius_; }
    double x(double t) const override { return radius_ * std::cos(t); }
    double y(double t) const override { return radius_ * std::sin(t); }
    double z(double t) const override { return step_ * t / (2 * M_PI); }

    double dx(double t) const override { return -radius_ * std::sin(t); }
    double dy(double t) const override { return radius_ * std::cos(t); }
    double dz(double t) const override { return step_ / (2 * M_PI); }

private:
    double radius_;
    double step_;
};


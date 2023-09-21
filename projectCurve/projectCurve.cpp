// projectCurve.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "projectCurve.h"

int main()
{
    std::vector<std::unique_ptr<Curve>> curves;
    for (int i = 0; i < 10; ++i) {
        double radius = rand() % 10 + 1;
        double a = rand() % 10 + 1;
        double b = rand() % 10 + 1;
        double step = rand() % 10 + 1;
        int type = std::rand() % 3;

        if (type == 0) {
            curves.emplace_back(new Circle(radius));
        }
        else if (type == 1) {
            curves.emplace_back(new Ellipse(a, b));
        }
        else {
            curves.emplace_back(new Helix(radius, step));
        }
    }

    std::cout << "All curves at t = PI/4:" << std::endl;
    for (const auto& curve : curves) {
        std::cout << "x= " << curve->x(M_PI / 4) << ", y= " << curve->y(M_PI / 4) << ", z= " << curve->z(M_PI / 4) << ", dx= "
            << curve->dx(M_PI / 4) << ", dy= " << curve->dy(M_PI / 4) << ", dz= " << curve->dz(M_PI / 4) << std::endl;
    }

    std::vector<const Circle*> circles;
    for (const auto& curve : curves) {
        if (dynamic_cast<const Circle*>(curve.get())) {
            circles.push_back(static_cast<const Circle*>(curve.get()));
        }
    }

    std::sort(circles.begin(), circles.end(), [](const Circle* c1, const Circle* c2) {
        return c1->radius() < c2->radius();
        });

    std::cout << "Sorted circles by radius:" << std::endl;
    for (const auto& circle : circles) {
        std::cout << "Radius: " << circle->radius() << std::endl;
    }

    double totalRadius = 0.0;

    for (int i = 0; i < circles.size(); ++i)
        totalRadius += circles[i]->radius();

    std::cout << "Total radius sum: " << totalRadius << std::endl;

    return 0;
}
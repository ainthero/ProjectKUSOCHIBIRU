//
// Created by ainthero on 21.09.20.
//
#pragma once

#include <cmath>

struct point {
    double x, y;


    point operator+(point p) const;

    point operator-(point p) const;

    double operator%(point p) const;

    double operator*(point p) const;

    point operator*(double k) const;
};

struct line {
    double a, b, c;

    line(double a, double b, double c);

    line(point p, point q);

    line() = default;
};


double point_distance(point p1, point p2);

line line_eq(point p1, point p2);


double v_length(point p1);


double angle(point p1, point p2);

double angle(point p12, point p1, point p2);


point v_normal(line l1);
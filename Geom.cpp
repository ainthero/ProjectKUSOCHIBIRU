//
// Created by ainthero on 21.09.20.
//
#include "Geom.h"


double point_distance(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

line line_eq(point p1, point p2) {
    double A = p2.y - p1.y;
    double B = p1.x - p2.x;
    double C = p1.y * (p2.x - p1.x) - p1.x * (p2.y - p1.y);
    return line{A, B, C};
}

double v_length(point p1) {
    return point_distance(p1, point{0, 0});
}

double angle(point p1, point p2) {
    return acos(p1 * p2 / (v_length(p1) * v_length(p2)));
}

double angle(point p12, point p1, point p2) {
    p1 = p1 - p12;
    p2 = p2 - p12;
    return atan2(p1 % p2, p1 * p2);
}

point v_normal(line l1) {
    return point{l1.a, l1.b};
}

point point::operator+(point p) const {
    return point{x + p.x, y + p.y};
}

point point::operator-(point p) const {
    return point{x - p.x, y - p.y};
}

double point::operator%(point p) const {
    return x * p.y - y * p.x;
}

double point::operator*(point p) const {
    return x * p.x + y * p.y;
}

point point::operator*(double k) const {
    return point{x * k, y * k};
}

line::line(double a, double b, double c) : a(a), b(b), c(c) {}

line::line(point p, point q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
}

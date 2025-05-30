#include "ControlPoint.h"
#include <cmath>

ControlPoint::ControlPoint() : m_x(0), m_y(0) {}

ControlPoint::ControlPoint(const std::string& name, double x, double y)
    : m_name(name), m_x(x), m_y(y) {
}

std::string ControlPoint::GetName() const { return m_name; }
double ControlPoint::GetX() const { return m_x; }
double ControlPoint::GetY() const { return m_y; }

double ControlPoint::DistanceTo(double x, double y) const
{
    return sqrt(pow(m_x - x, 2) + pow(m_y - y, 2));
}
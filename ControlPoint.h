// ControlPoint.h
#pragma once
#include <string>

class ControlPoint
{
public:
    ControlPoint();
    ControlPoint(const std::string& name, double x, double y);

    std::string GetName() const;
    double GetX() const;
    double GetY() const;

    double DistanceTo(double x, double y) const;

private:
    std::string m_name;  // ����
    double m_x;          // X����
    double m_y;          // Y����
};

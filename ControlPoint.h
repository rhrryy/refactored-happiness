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
    std::string m_name;  // 点名
    double m_x;          // X坐标
    double m_y;          // Y坐标
};

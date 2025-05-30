// ControlPointManager.h
#pragma once
#include <vector>
#include "ControlPoint.h"

class ControlPointManager
{
public:
    bool LoadFromFile(const std::string& filePath);
    const std::vector<ControlPoint>& GetPoints() const;
    const ControlPoint* FindPointByName(const std::string& name) const;
    const ControlPoint* FindNearestPoint(double x, double y) const;

private:
    std::vector<ControlPoint> m_points;  // 存储所有控制点
};

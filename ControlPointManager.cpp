#include "ControlPointManager.h"
#include <fstream>
#include <sstream>

bool ControlPointManager::LoadFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
        return false;

    int count;
    file >> count;

    m_points.clear();
    m_points.reserve(count);

    std::string line;
    std::getline(file, line); // 读取第一行剩余部分

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name;
        double x, y;

        if (iss >> name >> x >> y)
        {
            m_points.emplace_back(name, x, y);
        }
    }

    return true;
}

const std::vector<ControlPoint>& ControlPointManager::GetPoints() const
{
    return m_points;
}

const ControlPoint* ControlPointManager::FindPointByName(const std::string& name) const
{
    for (const auto& point : m_points)
    {
        if (point.GetName() == name)
            return &point;
    }
    return nullptr;
}

const ControlPoint* ControlPointManager::FindNearestPoint(double x, double y) const
{
    if (m_points.empty())
        return nullptr;

    const ControlPoint* nearest = &m_points[0];
    double minDistance = nearest->DistanceTo(x, y);

    for (const auto& point : m_points)
    {
        double distance = point.DistanceTo(x, y);
        if (distance < minDistance)
        {
            minDistance = distance;
            nearest = &point;
        }
    }

    return nearest;
}
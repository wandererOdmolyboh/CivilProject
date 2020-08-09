#pragma once

#include <cmath>
#include <vector>
#include "Point2d.h"
#include <algorithm>
#include "EnumEntityType.h"

void find_Rect(const std::vector<Point2d>& p, std::vector <double> &rez);

Point2d min(const std::vector<Point2d>& p);

Point2d max(const std::vector<Point2d>& p);

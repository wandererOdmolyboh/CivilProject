#include "FindBoundigBox.h"

std::vector<double> find_point_Rect(const Point2d& point0, 
  const Point2d& point1, double h, const int side);

void find_dist_point(const std::vector<Point2d>& p, const std::vector<int> &vector_index,
  std::vector<double> &vector_value, const Point2d &p1, const Point2d &p2);

void find_point_rect(std::vector <double> &rez, const std::vector<int> &vector_index,
  std::vector<double> &vector_value, const Point2d &p1,
  const Point2d &p2, const int64_t id, const int flag);

void find_Rect(const std::vector<Point2d>& p, std::vector <double> &rez)
{
  Point2d p1(min(p));
  Point2d p2(max(p));
  std::vector<int> left_vector_index;
  std::vector<int> right_vector_index;
  std::vector<double> left_vector_value;
  std::vector<double> right_vector_value;

  double D = 0;

  for (size_t i = 0; i < p.size(); i++)
  {
    D = (p.at(i).x() - p1.x()) * (p2.y() - p1.y()) - (p.at(i).y() - p1.y()) * (p2.x() - p1.x());
    if (D < 0)
      left_vector_index.push_back(i);
    if (D > 0)
      right_vector_index.push_back(i);
  }

  find_dist_point(p, right_vector_index, right_vector_value, p1, p2);
  find_dist_point(p, left_vector_index, left_vector_value, p1, p2);
  auto it1 = std::max_element(right_vector_value.begin(), right_vector_value.end());
  auto it2 = std::max_element(left_vector_value.begin(), left_vector_value.end());
  auto id1 = std::distance(right_vector_value.begin(), it1);
  auto id2 = std::distance(left_vector_value.begin(), it2);
  find_point_rect(rez, left_vector_index, left_vector_value, p1, p2, id2, -1);
  find_point_rect(rez, right_vector_index, right_vector_value, p1, p2, id1, 1);
}


Point2d min(const std::vector<Point2d>& p)
{
  double xx = 0;
  double yy = 0;
  for (size_t i = 0; i < p.size(); i++)
  {
    if (xx > p.at(i).x())
      xx = p.at(i).x();
    if (yy > p.at(i).y())
      yy = p.at(i).y();
  }
  Point2d a(xx, yy);
  return a;
}

Point2d max(const std::vector<Point2d>& p)
{
  double xx = 0;
  double yy = 0;
  for (size_t i = 0; i < p.size(); i++)
  {
    if (xx < p.at(i).x())
      xx = p.at(i).x();
    if (yy < p.at(i).y())
      yy = p.at(i).y();
  }
  Point2d a(xx, yy);
  return a;
}



void find_dist_point(const std::vector<Point2d>& p, const std::vector<int> &vector_index,
  std::vector<double> &vector_value,const Point2d &p1, const Point2d &p2)
{
  for (size_t i = 0; i < vector_index.size(); i++)
  {
    vector_value.push_back(
      abs((p2.y() - p1.y()) * p.at(vector_index.at(i)).x()
        - (p2.x() - p1.x()) * p.at(vector_index.at(i)).y()
        + p2.x() * p1.y()
        - p2.y() * p1.x()
      )
      /
      sqrt(
        pow((p2.y() - p1.y()), 2)
        +
        pow((p2.x() - p1.x()), 2)

      )
    );
  }
}

void find_point_rect(std::vector <double> &rez, const std::vector<int> &vector_index,
   std::vector<double> &vector_value, const Point2d &p1, 
  const Point2d &p2, const int64_t id,const int flag)
{
  if (vector_index.size() == 0)
  {
    rez.push_back(p1.x());
    rez.push_back(p1.y());
    rez.push_back(p2.x());
    rez.push_back(p2.y());
  }
  else
  {
    vector_value = find_point_Rect(p1, p2, vector_value.at(id), flag);
    for (size_t i = 0; i < vector_value.size(); i++)
    {
      rez.push_back(vector_value.at(i));
    }
  }
}

std::vector<double> find_point_Rect(const Point2d& point0,const Point2d& point1,
  double h, const int side)
{
  std::vector<double>  described;
  if (side == 1)
    h *= (-1);
  double length = sqrt(pow((point0.x() - point1.x()), 2) + pow((point0.y() - point1.y()), 2));
  described.push_back(point1.x() + h * (point0.y() - point1.y()) / length);
  described.push_back(point1.y() - h * (point0.x() - point1.x()) / length);
  described.push_back(point0.x() + h * (point0.y() - point1.y()) / length);
  described.push_back(point0.y() - h * (point0.x() - point1.x()) / length);
  return  (described);
}
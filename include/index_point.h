#pragma once

class IndexPoint {
public:
  IndexPoint(){};
  IndexPoint(const int &new_idx, const float &new_x, const float &new_y,
             const float &new_z);

  const bool outputInfo(const int &info_level = 0);

public:
  int idx;
  float x;
  float y;
  float z;
};

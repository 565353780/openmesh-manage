#pragma once

class IndexPoint {
public:
  IndexPoint(){};
  IndexPoint(const int &idx, const float &x, const float &y, const float &z);

  const bool outputInfo(const int &info_level = 0);

  const int idx() { return idx_; }
  const float x() { return x_; };
  const float y() { return y_; };
  const float z() { return z_; };

private:
  int idx_;
  float x_;
  float y_;
  float z_;
};

#ifndef TRACKING_HPP
#define TRACKING_HPP

#include <nlohmann/json.hpp>
#include <string>

class Tracking {
public:
  void printTrackingInfo(const nlohmann::json &data);
};

#endif // TRACKING_HPP

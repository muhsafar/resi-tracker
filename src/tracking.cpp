#include "tracking.hpp"
#include <iostream>

void Tracking::printTrackingInfo(const nlohmann::json &data) {
  if (data["status"] == 200) {
    std::cout << "Tracking Information:" << std::endl;
    std::cout << "AWB: " << data["data"]["summary"]["awb"] << std::endl;
    std::cout << "Courier: " << data["data"]["summary"]["courier"] << std::endl;
    std::cout << "Service: " << data["data"]["summary"]["service"] << std::endl;
    std::cout << "Status: " << data["data"]["summary"]["status"] << std::endl;
    std::cout << "Date: " << data["data"]["summary"]["date"] << std::endl;
    std::cout << "Amount: " << data["data"]["summary"]["amount"] << std::endl;
    std::cout << "Weight: " << data["data"]["summary"]["weight"] << std::endl;

    std::cout << "History:" << std::endl;
    for (const auto &event : data["data"]["history"]) {
      std::cout << "Date: " << event["date"] << std::endl;
      std::cout << "Description: " << event["desc"] << std::endl;
      std::cout << "Location: " << event["location"] << std::endl;
      std::cout << "---------------------------------" << std::endl;
    }
  } else {
    std::cerr << "Failed to track package: " << data["message"] << std::endl;
  }
}

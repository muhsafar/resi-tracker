#include "api_client.hpp"
#include "courier.hpp"
#include "tracking.hpp"
#include <iostream>

int main() {
  std::string api_key =
      "142e651ab843c99afe6634f96b9fa4f8f82917cbde5a41379fdb68cd89e14dcc";
  APIClient api_client(api_key);

  std::cout << "Available Couriers: " << std::endl;
  auto couriers = Courier::getAvailableCouriers();
  for (size_t i = 0; i < couriers.size(); ++i) {
    std::cout << i + 1 << ". " << couriers[i] << std::endl;
  }

  std::cout << "Select Courier (Enter number): ";
  size_t choice;
  std::cin >> choice;
  if (choice < 1 || choice > couriers.size()) {
    std::cerr << "Invalid choice." << std::endl;
    return 1;
  }

  std::string selected_courier = couriers[choice - 1];

  std::cout << "Enter Tracking Number: ";
  std::string tracking_number;
  std::cin >> tracking_number;

  auto tracking_data =
      api_client.trackPackage(selected_courier, tracking_number);

  Tracking tracker;
  tracker.printTrackingInfo(tracking_data);

  return 0;
}

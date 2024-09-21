#ifndef API_CLIENT_HPP
#define API_CLIENT_HPP

#include <nlohmann/json.hpp>
#include <string>

class APIClient {
public:
  APIClient(const std::string &api_key);
  nlohmann::json trackPackage(const std::string &courier,
                              const std::string &awb);

private:
  std::string api_key;
  std::string base_url;
};

#endif // API_CLIENT_HPP

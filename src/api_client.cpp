#include "api_client.hpp"
#include <curl/curl.h>
#include <iostream>

// Helper function for handling cURL responses
size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     std::string *s) {
  s->append(static_cast<char *>(contents), size * nmemb);
  return size * nmemb;
}

APIClient::APIClient(const std::string &api_key)
    : api_key(api_key), base_url("https://api.binderbyte.com/v1/track") {}

nlohmann::json APIClient::trackPackage(const std::string &courier,
                                       const std::string &awb) {
  std::string url =
      base_url + "?api_key=" + api_key + "&courier=" + courier + "&awb=" + awb;
  CURL *curl;
  CURLcode res;
  std::string response_string;
  std::string header_string;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();

  return nlohmann::json::parse(response_string);
}

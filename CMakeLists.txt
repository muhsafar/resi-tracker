cmake_minimum_required(VERSION 3.10)
project(TrackingApp)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Directories
include_directories(include)

# Executable
add_executable(TrackingApp
    src/main.cpp
    src/api_client.cpp
    src/courier.cpp
    src/tracking.cpp
)

# Link Libraries (e.g., for HTTP requests and JSON parsing)
# Assuming you have a library like cURL and JSON for Modern C++ (nlohmann/json)
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

target_link_libraries(TrackingApp
    CURL::libcurl
    nlohmann_json::nlohmann_json
)

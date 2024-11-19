cmake_minimum_required(VERSION 3.24)
project(ClockPlusPlus)


message("----MW: Building Project ----")

find_package(tinyxml2 CONFIG REQUIRED)
find_package(pugixml CONFIG REQUIRED)
find_package(Raylib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 
	tinyxml2::tinyxml2
	pugixml::shared
	pugixml::pugixml
	raylib
)
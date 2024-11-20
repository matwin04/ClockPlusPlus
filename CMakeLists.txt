cmake_minimum_required(VERSION 3.24)
project(ClockPlusPlus)


message("----MW: Building Project ----")


find_package(Raylib)
find_package(ftxui CONFIG REQUIRED)
find_package(pugixml REQUIRED)
message("All packages have been found")


add_executable(${PROJECT_NAME} main.cpp "calendarEvent.h" "calendarEvent.cpp" "agenda.h" "agenda.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE 
	raylib
	pugixml::shared
	pugixml::pugixml
	ftxui::dom
	ftxui::screen
	ftxui::component

)
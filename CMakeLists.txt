# Minimum version and project setup
cmake_minimum_required(VERSION 3.24)
project(ClockPlusPlus)

# Add your source files
set(SOURCES
    main.cpp
    CalendarEvent.cpp
    Agenda.cpp
)

set(HEADERS
    CalendarEvent.h
    Agenda.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Find required libraries
find_package(pugixml CONFIG REQUIRED)
find_package(ftxui CONFIG REQUIRED)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE pugixml ftxui::screen ftxui::dom ftxui::component)

# Set output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Specify the path to the calendar.xml file
set(CALENDAR_XML ${CMAKE_SOURCE_DIR}/calendar.xml)

# Copy calendar.xml to the output directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CALENDAR_XML} $<TARGET_FILE_DIR:ClockPlusPlus>
    COMMENT "Copying calendar.xml to the output directory"
)
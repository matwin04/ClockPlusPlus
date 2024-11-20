#include <iostream>
#include <pugixml.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/dom/elements.hpp>
#include <memory>
#include "calendarEvent.h"
#include "agenda.h"

using namespace std;
using namespace pugi;
using namespace ftxui;

agenda parseCalendar(const string& filePath) {
	agenda agenda(100);

	xml_document doc;
	if (!doc.load_file(filePath.c_str())) {
		cerr << "Failed to load xml file" << filePath << endl;
		return agenda;
	}

	//parse XML and populate agenda
	for (auto year : doc.child("calendar").children("year")) {
		for (auto month : year.children("month")) {
			for (auto day : month.children("day")) {
				int id = stoi(day.attribute("id").value());
				string date = year.attribute("value").value();
				date += "-" + string(month.attribute("name").value());
				date += "-" + string(day.attribute("date").value());
				string time = day.child("time").text().get();
				string location = day.child("location").text().get();
				string startTime = day.child("startTime").text().get();
				string endTime = day.child("endTime").text().get();
				string category = day.child("category").text().get();
				string event = day.child("event").text().get();

				agenda.addEvent(calendarEvent(id, date, time, location, startTime, endTime, category, event));
			}
		}
	}
	return agenda;
}

void displayAgenda(const agenda& agenda) {
    // Create rows for the FTXUI table
    std::vector<std::vector<std::string>> rows;
    rows.push_back({ "ID", "Date", "Time", "Location", "Start", "End", "Category", "Event" }); // Header

    for (int i = 0; i < agenda.getEventCount(); ++i) {
        const calendarEvent& event = agenda.getEvents()[i];
        rows.push_back({
            std::to_string(event.getId()),
            event.getDate(),
            event.getTime(),
            event.getLocation(),
            event.getStartTime(),
            event.getEndTime(),
            event.getCategory(),
            event.getEvent()
            });
    }

    // Create the table and render it into an Element
    ftxui::Table table = ftxui::Table(rows);
    auto tableElement = table.Render() | ftxui::border | ftxui::color(ftxui::Color::Yellow);

    // Use FTXUI's Renderer to display the table
    auto screen = ftxui::ScreenInteractive::FitComponent();
    auto component = ftxui::Renderer([tableElement]() -> ftxui::Element {
        return tableElement;
        });

    // Start the FTXUI loop
    screen.Loop(component);
}

int main() {
	cout << "Hello World\n";
	string filePath = "calendar.xml";

	//Parse the inital agenda
	agenda agenda = parseCalendar(filePath);
	displayAgenda(agenda);

	calendarEvent newEvent(3, "2024-12-25", "6:00 PM", "Home", "18:00", "20:00", "Holiday", "Christmas Dinner");
    agenda.addEvent(newEvent);


    // Delete an event by ID
    

    // Display the updated agenda
    cout << "\nUpdated agenda:\n";
    displayAgenda(agenda);

    return 0;


	return 0;
}
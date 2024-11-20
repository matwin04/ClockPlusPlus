#pragma once

#include "agenda.h"
#include "calendarEvent.h"
#include <memory>

class agenda {
private:
	std::unique_ptr<calendarEvent[]> events;
	int eventCount;
	int maxEvents;
public:
	//Constructor 
	agenda(int maxEvents);

	//Add Edit and Delete
	bool addEvent(const calendarEvent& event);
	bool delteEvent(int id);
	bool editEvent(int id, const calendarEvent& updatedEvent);

	//Getters
	calendarEvent* getEvents() const;
	int getEventCount() const;
	calendarEvent* findEventsById(int id);
	
};



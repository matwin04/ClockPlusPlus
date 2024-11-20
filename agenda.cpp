#include "agenda.h"
#include <iostream>
//Constructor
agenda::agenda(int maxEvents) : eventCount(0), maxEvents(maxEvents) {
	events = std::make_unique<calendarEvent[]>(maxEvents);
}

bool agenda::addEvent(const calendarEvent& event) {
	if (eventCount < maxEvents) {
		events[eventCount++] = event;
		return true;
	}
	return false;
}

//Delete Event
bool agenda::delteEvent(int id) {
	for (int i = 0; i < eventCount; ++i) {
		if (events[i].getId() == id) {
			//Shift remaining events
			for (int j = i;j < eventCount - 1;++j) {
				events[j] = events[j + i];
			}
			--eventCount;
			return true;
		}
	}
	return false;
}

//Edit Event
bool agenda::editEvent(int id, const calendarEvent& updatedEvent) {
	for (int i = 0; i < eventCount; ++i) {
		if (events[i].getId() == id) {
			events[i] = updatedEvent;
			return true;
		}
	}
	return false;
}

// Get Events
calendarEvent* agenda::getEvents() const { return events.get(); }

// Get Event Count 
int agenda::getEventCount() const { return eventCount; }

//Find event by ID
calendarEvent* agenda::findEventsById(int id) {
	for (int i = 0; i < eventCount; ++i) {
		if (events[i].getId() == id) {
			return &events[i];
		}
	}
	return nullptr;
}
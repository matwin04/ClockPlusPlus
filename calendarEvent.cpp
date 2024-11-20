#include "calendarEvent.h"

calendarEvent::calendarEvent() : id(-1)
{
}

calendarEvent::calendarEvent(
	int id,
	const std::string& date,
	const std::string& time,
	const std::string& location,
	const std::string& startTime,
	const std::string& endTime,
	const std::string& category,
	const std::string& event)
	: id(id),
	date(date),
	time(time),
	location(location),
	startTime(startTime),
	endTime(endTime),
	category(category),
	event(event) {}

//Getters
int calendarEvent::getId() const {
	return 0;
}

const std::string& calendarEvent::getDate() const {
	return date;
}

const std::string& calendarEvent::getTime() const {
	return time;
}

const std::string& calendarEvent::getLocation() const {
	// TODO: insert return statement here
	return location;
}

const std::string& calendarEvent::getStartTime() const {
	return startTime;
}

const std::string& calendarEvent::getEndTime() const {
	return endTime;
}
const std::string& calendarEvent::getCategory() const {
	return category;
}
const std::string& calendarEvent::getEvent() const { return event; }
//Setters
void calendarEvent::setId(int newId) { id = newId; }
void calendarEvent::setDate(const std::string& newDate) { date = newDate; }
void calendarEvent::setTime(const std::string& newTime) { time = newTime; }
void calendarEvent::setLocation(const std::string& newLocation) { location = newLocation; }
void calendarEvent::setStartTime(const std::string& newStartTime) { startTime = newStartTime; }
void calendarEvent::setEndTime(const std::string& newEndTime) { endTime = newEndTime; }
void calendarEvent::setCategory(const std::string& newCategory) { category = newCategory; }
void calendarEvent::setEvent(const std::string& newEvent) { event = newEvent; }
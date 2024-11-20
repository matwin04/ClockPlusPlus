#pragma once
#include <string>
class calendarEvent {
private:
	int id;
	std::string date;
	std::string time;
	std::string location;
	std::string startTime;
	std::string endTime;
	std::string category;
	std::string event;
public:
	calendarEvent();
	calendarEvent(
		int id,
		const std::string& date,
		const std::string& time,
		const std::string& location,
		const std::string& startTime,
		const std::string& endTime,
		const std::string& category,
		const std::string& event
	);
	//Get Event Id
	int getId() const;

	//Set Event Id 
	void setId(int newId);

	//Get event details
	const std::string& getDate() const;
	const std::string& getTime() const;
	const std::string& getLocation() const;
	const std::string& getStartTime() const;
	const std::string& getEndTime() const;
	const std::string& getCategory() const;
	const std::string& getEvent() const;

	//Set event details
	void setDate(const std::string& newDate);
	void setTime(const std::string& newTime);
	void setLocation(const std::string& newLocation);
	void setStartTime(const std::string& newStartTime);
	void setEndTime(const std::string& newEndTime);
	void setCategory(const std::string& newCategory);
	void setEvent(const std::string& newEvent);
};

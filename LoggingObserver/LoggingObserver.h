#pragma once

#include <ostream>
#include <list>
#include <string>

class ILoggable;
class Subject;
class Observer;
class LogObserver;

class ILoggable {
public:
	virtual ~ILoggable();

	virtual std::string stringToLog() = 0;

	friend std::ostream& operator<<(std::ostream&, const ILoggable&);
};

class Subject {
public:
	Subject();
	Subject(const Subject&);
	~Subject();

	virtual void attach(Observer*);
	virtual void detach(Observer*);
	virtual void notify(ILoggable*);

	Subject& operator=(const Subject&);
	friend std::ostream& operator<<(std::ostream&, const Subject&);
private:
	std::list<Observer*>* _observers;
};

class Observer {
public:
	Observer();
	Observer(const Observer&);
	~Observer();
	
	virtual void update(ILoggable*) = 0;

	Observer& operator=(const Observer&);
	friend std::ostream& operator<<(std::ostream&, const Observer&);
};

class LogObserver : public Observer {
public:
	LogObserver();
	LogObserver(const LogObserver&);
	~LogObserver();

	void update(ILoggable*);
	LogObserver& operator=(const LogObserver&);
	friend std::ostream& operator<<(std::ostream&, const LogObserver&);
};
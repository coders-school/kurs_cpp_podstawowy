#ifndef TIME_H
#define TIME_H

#include <vector>

// Class resposible for time elapsed during game
class Time {
public:
    class Observer {
	public:
        virtual void NextDay() = 0;
		virtual ~Observer() = default;
    };

	using ObserverIT = std::vector<Observer*>::iterator;

	Time() = default;
    virtual ~Time() = default;
    virtual void AddObserver(Observer* obs);
    virtual void RemoveObserver(Observer* obs);
    virtual size_t GetElpasedTime() const { return time_elapsed_; }
    virtual Time& operator++();

private:
	ObserverIT GetObserverIt(Observer* obs);
    size_t time_elapsed_ {1};
    std::vector<Observer*> observers_;
};

#endif // TIME_H
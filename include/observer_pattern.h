#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H
#include <string>
#include <iostream>

class IObserver
{
   public:
    virtual ~IObserver() {}
    virtual void Update(const std::string &message_from_subject) = 0;
};
class ISubject
{
   public:
    virtual ~ISubject() {}
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

void ClientCode();

#endif
#include <iostream>
#include <list>
#include <string>
#include "../include/observer_pattern.h"

class Subject : public ISubject
{
   public:
    virtual ~Subject() { std::cout << "Goodbye, I was the Subject.\n"; }
    void Attach(IObserver *observer) override
    {
        list_observer_.push_back(observer);
    }
    void Detach(IObserver *observer) override
    {
        list_observer_.remove(observer);
    }
    void Notify()
    {
        std::list<IObserver *>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while (iterator != list_observer_.end())
        {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }
    void HowManyObserver()
    {
        std::cout << "There are " << list_observer_.size()
                  << " observers in the list.\n";
    }
    void CreateMessage(std::string message = "Empty")
    {
        this->message_ = message;
        Notify();
    }

   private:
    std::list<IObserver *> list_observer_;
    std::string message_;
};
class Observer : public IObserver
{
   public:
    Observer(Subject &subject) : subject_(subject)
    {
        this->subject_.Attach(this);
        std::cout << "Hi, I'm Observer \" " << ++Observer::static_number_
                  << "\".\n";
        this->number_ = Observer::static_number_;
    }
    virtual ~Observer()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->number_
                  << "\".\n";
    }
    void Update(const std::string &message_from_subject) override
    {
        message_from_subject_ = message_from_subject;
    }
    void RemoveMeFromTheList()
    {
        subject_.Detach(this);
        std::cout << "Observer \"" << number_ << "\"removed from the list/\n";
    }
    void PrintInfor()
    {
        std::cout << "Observer \" " << this->number_
                  << "\" : a new message is available" << this->>
            message_from_subject_;
    }

   private:
    std::string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number_;
};

int Observer::static_number_ = 0;

void ClientCode()
{
    Subject *subject = new Subject();
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;

    subject->CreateMessage("Hello world!");
    obser
}


#include "../include/observer_pattern.h"

class Observer;
class ISubject;
void Subject::Attach(IObserver *observer)
{
    list_observer_.push_back(observer);
}
void Subject::Detach(IObserver *observer) { list_observer_.remove(observer); }
void Subject::Notify()
{
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    std::cout << "There are " << list_observer_.size()
              << " observers in the list.\n";
    while (iterator != list_observer_.end())
    {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void Subject::CreateMessage(std::string message)
{
    this->message_ = message;
    Notify();
}

Observer::Observer(Subject &subject) : subject_(subject)
{
    this->subject_.Attach(this);
    std::cout << "Hi, I'm Observer \" " << ++Observer::static_number_
              << "\".\n";
    this->number_ = Observer::static_number_;
}

void Observer::Update(const std::string &message_from_subject)
{
    message_from_subject_ = message_from_subject;
    PrintInfor();
}
void Observer::RemoveMeFromTheList()
{
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\"removed from the list /\n ";
}
void Observer::PrintInfor()
{
    std::cout << "Observer \" " << this->number_
              << "\" : a new message is available --> "
              << this->message_from_subject_ << std::endl;
}

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
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new Observer(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject);

    subject->CreateMessage("My new car is great! ");
    observer5->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();
    observer4->RemoveMeFromTheList();

    delete observer1;
    delete observer2;
    delete observer3;
    delete observer4;
    delete observer5;
}

// void WeatherData::Attach(IObserver *observer) {
// observer_.push_back(observer); } void WeatherData::Detach(IObserver
// *observer) { observer_.remove(observer); } void WeatherData::Notify()
// {
//     std::list<IObserver *>::iterator iterator = observer_.begin();
//     // std::cout << "There are " << observer_.size() << " observers in the
//     // list\n";
//     std::cout << this->message_;
//     while (iterator != observer_.end())
//     {
//         (*iterator)->Update1();
//         iterator++;
//     }
// }
// void WeatherData::setTemperature(float temperature)
// {
//     temperature_ = temperature;
//     this->message_ = "Temperature is changed\n";
//     Notify();
// }
// void WeatherData::setHumidity(float humidity)
// {
//     humidity_ = humidity;
//     this->message_ = "Humidity is changed\n";
//     Notify();
// }
// // void TemperatureDisplay::Update1() { ; }
// void ClientCodeWeather()
// {
//     WeatherData *weatherdata = new WeatherData();
//     weatherdata->setTemperature(12);
//     weatherdata->setHumidity(50);
//     TemperatureDisplay temperature_celsius(weatherdata, false);
// }

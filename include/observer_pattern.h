#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H
#include <string>
#include <iostream>
#include <list>

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
class Subject : public ISubject
{
   public:
    virtual ~Subject() { std::cout << "Goodbye, I was the Subject.\n"; }
    void Attach(IObserver *observer) override;
    void Detach(IObserver *observer) override;
    void Notify();
    // void HowManyObserver();
    void CreateMessage(std::string message = "Empty");

   private:
    std::list<IObserver *> list_observer_;
    std::string message_;
};
class Observer : public IObserver
{
   public:
    Observer(Subject &subject);
    virtual ~Observer()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->number_
                  << "\".\n";
    }
    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfor();

   private:
    std::string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number_;
};
void ClientCode();

// build a weather monitoring application
// class WeatherData : public ISubject
// {
//    public:
//     virtual ~WeatherData() { std::cout << "Goodby, I was the WeatherData.\n";
//     } void Attach(IObserver *observer) override; void Detach(IObserver
//     *observer) override; void Notify() override; void setTemperature(float
//     temperature); void setHumidity(float humidity);

//    private:
//     float temperature_;
//     float humidity_;
//     std::list<IObserver *> observer_;
//     std::string message_;
// };
// class TemperatureDisplay : public IObserver
// {
//    public:
//     TemperatureDisplay(WeatherData *weather_data, bool is_fahrenheit)
//         : weather_data_(weather_data), is_fahrenheit_(is_fahrenheit)
//     {
//     }

//     void Update1() override;

//    private:
//     WeatherData *weather_data_;
//     bool is_fahrenheit_;
// };

// // class HumidityDisplay : public IObserver
// // {
// //    public:
// //     HumidityDisplay(WeatherData *weatherdata) : weather_data_(weatherdata)
// {}
// //     void Update1();

// //    private:
// //     std::string message_from_subject_;

// //     WeatherData *weather_data_;
// // };
// // class Alarm : public IObserver
// // {
// //    public:
// //     Alarm(WeatherData *weatherdata, float threshold)
// //         : weather_data_(weatherdata), threshold_(threshold)
// //     {
// //     }
// //     void Update();

// //    private:
// //     WeatherData *weather_data_;
// //     std::string message_from_subject_;
// //     float threshold_;
// // };

// void ClientCodeWeather();
#endif
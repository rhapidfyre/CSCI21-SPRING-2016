#include "temperature.h"

Temperature::Temperature()
{
    // Set Kelvin to 0 by default.
    kelvin_ = 0;
}
Temperature::Temperature(double kelvin)
{
    kelvin_ = kelvin;
}
Temperature::Temperature(double temp, char unit)
{
    // If temp is Fahrenheit, complete conversion, store as Kelvin
    if(unit == 'F' || unit == 'f')
    {
        kelvin_ = (5.0 * (temp - 32 ) / 9) + 273.15;
    }
    // If temp is Celsius, complete conversion, store as Kelvin
    else if(unit == 'C' || unit == 'c')
    {
        kelvin_ = temp + 273.15;
    }
    // Otherwise, assume temp is Kelvin
    else
    {
        kelvin_ = temp;
    }
}
// The following Sets are self-explanatory
void Temperature::SetTempFromKelvin(double kelvin)
{
    kelvin_ = kelvin;
}
void Temperature::SetTempFromCelsius(double celsius)
{
    kelvin_ = celsius + 273.15;
}
void Temperature::SetTempFromFahrenheit(double fahrenheit)
{
    kelvin_ = (5.0 * ((fahrenheit - 32) / 9)) + 273.15;
}
double Temperature::GetTempAsKelvin() const
{
    return kelvin_;
}
double Temperature::GetTempAsCelsius() const
{
    // Initialize a temporary variable to do the converstion
    double celsius;
    celsius = kelvin_ - 273.15;
    return celsius;
}
double Temperature::GetTempAsFahrenheit() const
{
    // Temp Var
    double fahrenheit = kelvin_;
    double celsius = GetTempAsCelsius();
    fahrenheit = ((celsius * 9.0) / 5) + 32;
    return fahrenheit;
}
string Temperature::ToString(char unit) const
{
    // Create Stringstream to forge our message
    stringstream ss;
    ss.clear();
    ss.setf(std::ios::fixed);
    // Make each temp reported have 2 decimal places
    ss.precision(2);
    
    if(unit == 'F' || unit == 'f')
    {
        ss << GetTempAsFahrenheit() << " Fahrenheit";
    }
    else if(unit == 'C' || unit == 'c')
    {
        ss << GetTempAsCelsius() << " Celsius";
    }
    else if(unit == 'K' || unit == 'k')
    {
        ss << GetTempAsKelvin() << " Kelvin";
    }
    else
    {
        ss << "Invalid Unit";
    }
    
    // Return streamstring as string
    return ss.str();
}
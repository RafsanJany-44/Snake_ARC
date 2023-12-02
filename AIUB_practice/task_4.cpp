#include <iostream>

class TimeConverter {
public:
    // Method to convert seconds to minutes
    double secondsToMinutes(double seconds) {
        return seconds / 60.0;
    }

    // Method to convert minutes to hours
    double minutesToHours(double minutes) {
        return minutes / 60.0;
    }

    // Method to convert hours to days
    double hoursToDays(double hours) {
        return hours / 24.0;
    }
};

int main() {
    // Create an instance of the TimeConverter class
    TimeConverter converter;

    // Example time conversions
    double seconds = 3600.0;  // 1 hour in seconds
    double minutesResult = converter.secondsToMinutes(seconds);
    double hoursResult = converter.minutesToHours(minutesResult);
    double daysResult = converter.hoursToDays(hoursResult);

    std::cout << seconds << " seconds is equal to " << minutesResult << " minutes.\n";
    std::cout << minutesResult << " minutes is equal to " << hoursResult << " hours.\n";
    std::cout << hoursResult << " hours is equal to " << daysResult << " days.\n";

    return 0;
}

/*
2469. Convert the Temperature
    Kelvin = Celsius + 273.15
    Fahrenheit = Celsius * 1.80 + 32.00
*/
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        std::vector<double> result{celsius + 273.15,celsius * 1.80 + 32.00};
        return result;
    }
};

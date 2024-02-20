#include <iostream>
#include <vector>

class LagrangeInterpolator {
private:
    std::vector<double> x_values;
    std::vector<double> y_values;

public:
    // Constructor
    LagrangeInterpolator(const std::vector<double>& x, const std::vector<double>& y);

    // Lagrange interpolation function
    double interpolate(double x);

private:
    // Helper function to calculate the Lagrange basis polynomial for a given index
    double basis(int index, double x);
};

LagrangeInterpolator::LagrangeInterpolator(const std::vector<double>& x, const std::vector<double>& y)
    : x_values(x), y_values(y) {}

double LagrangeInterpolator::interpolate(double x) {
    double result = 0.0;
    for (int i = 0; i < x_values.size(); ++i) {
        result += y_values[i] * basis(i, x);
    }
    return result;
}

double LagrangeInterpolator::basis(int index, double x) {
    double result = 1.0;
    for (int i = 0; i < int(x_values.size()); ++i) {
        if (i != index) {
            result *= (x - x_values[i]) / (x_values[index] - x_values[i]);
        }
    }
    return result;
}

int main() {
    // Sample data for interpolation
    std::vector<double> x_data = {5, -7, -6, 0};
    std::vector<double> y_data = {1, -23, -54, -954};

    // Create LagrangeInterpolator object with sample data
    LagrangeInterpolator interpolator(x_data, y_data);

    // Interpolate at a specific point
    double interpolate_at = 1;
    double result = interpolator.interpolate(interpolate_at);

    // Display the result
    std::cout << "Interpolated value at x = " << interpolate_at << ": " << result << std::endl;

    return 0;
}

#include <stdio.h> // import required library

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (9.0f / 5.0f) * celsius + 32.0f; // Ensure float literals
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0f / 9.0f) * (fahrenheit - 32.0f); // Ensure float literals
}

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15f; // Ensure float literals
}

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15f; // Ensure float literals
}

// Function to categorize the temperature and provide an advisory
void categorize_temperature(float celsius) {
    // if temperature is below 0
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy jacket.\n");
    // if temperature is between 0 and 10
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    // if temperature is between 10 and 25
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    // if temperature is between 25 and 35
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    // if temperature is above 35
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}

// main function
int main() {
    // variable to store the temperature input
    float temperature;
    // variable to store the scale
    int current_scale, target_scale;

    // Input temperature
    printf("Enter the temperature: ");
    // if input is invalie, error message
    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Input current scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    // if input is invalid, error message
    if (scanf("%d", &current_scale) != 1 || current_scale < 1 || current_scale > 3) {
        printf("Invalid input. Please enter 1, 2, or 3.\n");
        return 1;
    }

    // Input target scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    // if input is invalid, error message
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid input. Please enter 1, 2, or 3.\n");
        return 1;
    }

    // Perform conversion and display results
    float converted_temp; // Variable to store the converted temperature
    if (current_scale == 1 && target_scale == 2) { // If converting from Celsius to Fahrenheit
        converted_temp = celsius_to_fahrenheit(temperature);
        printf("Converted temperature: %.2f°F\n", converted_temp); // Output the converted temperature
    } else if (current_scale == 1 && target_scale == 3) { // If converting from Celsius to Kelvin
        converted_temp = celsius_to_kelvin(temperature);
        printf("Converted temperature: %.2fK\n", converted_temp); // Output the converted temperature
    } else if (current_scale == 2 && target_scale == 1) { // If converting from Fahrenheit to Celsius
        converted_temp = fahrenheit_to_celsius(temperature);
        printf("Converted temperature: %.2f°C\n", converted_temp); // Output the converted temperature
    } else if (current_scale == 2 && target_scale == 3) { // If converting from Fahrenheit to Kelvin
        float celsius = fahrenheit_to_celsius(temperature); // Convert Fahrenheit to Celsius first
        converted_temp = celsius_to_kelvin(celsius); // Then convert Celsius to Kelvin
        printf("Converted temperature: %.2fK\n", converted_temp); // Output the converted temperature
    } else if (current_scale == 3 && target_scale == 1) { // If converting from Kelvin to Celsius
        converted_temp = kelvin_to_celsius(temperature);
        printf("Converted temperature: %.2f°C\n", converted_temp); // Output the converted temperature
    } else if (current_scale == 3 && target_scale == 2) { // If converting from Kelvin to Fahrenheit
        float celsius = kelvin_to_celsius(temperature); // Convert Kelvin to Celsius first
        converted_temp = celsius_to_fahrenheit(celsius); // Then convert Celsius to Fahrenheit
        printf("Converted temperature: %.2f°F\n", converted_temp); // Output the converted temperature
    } else { // If invalid conversion choice (same scale)
        printf("Invalid conversion choice.\n");
        return 1; // Exit with error code 1
    }

    // Categorize temperature and provide weather advisory
    categorize_temperature(converted_temp);

    return 0;
}

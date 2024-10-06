#include <stdio.h>
// Define functions to convert each scale
float celsius_to_kelvin(float c)
{
	return (c + 273.15);
}

float celsius_to_fahrenheit(float c)
{
	return (((9/5.0) * c) + 32);
}

float fahrenheit_to_celsius(float f)
{
	return ((5/9.0)*(f - 32));
}

float fahrenheit_to_kelvin(float f)
{
	// Call other functions instead of finding a new equation
	float c = fahrenheit_to_celsius(f);
	return celsius_to_kelvin(c);
}

float kelvin_to_celsius(float k)
{
	return (k - 273.15);
}

float kelvin_to_fahrenheit(float k)
{
	// Call other functions but opposite 
	float c = kelvin_to_celsius(k);
	return celsius_to_fahrenheit(c);
}

float temp_converter(float temp, int scaleIn, int scaleOut)
{
	// Check the input scale and convert accordingly 
	switch (scaleIn)
	{
		case 1:
			// Convert to scale to the given output, then call their respective functions
			if (scaleOut == 2)
			{
				return celsius_to_fahrenheit(temp);
			}
			else if (scaleOut == 3)
			{
				return celsius_to_kelvin(temp);
			}
		case 2: 
			// Convert to other outputs and call functions
			if (scaleOut == 1)
			{
				return fahrenheit_to_celsius(temp);
			}
			else if (scaleOut == 3)
			{
				return fahrenheit_to_kelvin(temp);
			}
		case 3:
			// Same as previous two cases
			if (scaleOut == 1)
			{
				return kelvin_to_celsius(temp);
			}
			if (scaleOut == 2)
			{
				return kelvin_to_fahrenheit(temp);
			}
	}
	return 0;
}

void weather_man(float tempC)
{
	// Manually check the temperature in celsius and print the corresponding output
	if (tempC < 0)
	{
		printf("Temperature Category: Freezing\n");
		printf("Weather Advisory: Stay warm inside!\n");
	}
	else if (0 <= tempC && tempC  < 10)
	{
		printf("Temperature Category: Cold\n");
		printf("Weather Advisory: Wear a coat!\n");
	}
	else if (10 <= tempC && tempC < 25)
	{
		printf("Temperature Category: Comfortable\n");
		printf("Weather Advisory: Enjoy the nice weather!\n");
	}
	else if (25 <= tempC && tempC < 35)
	{
		printf("Temperature Category: Hot\n");
		printf("Weather Advisory: Stay hydrated!\n");
	}
	else if (35 < tempC) 
	{
		printf("Temperature Category: Extreme Heat\n");
		printf("Weather Advisory: Stay cool!\n");
	}
}

int main()
{
	// Declare variables
	float temp;
	int scaleIn, scaleOut;
	int result;

	// Begin taking input in and continue checking input until given valid values
	while (1)
	{
		printf("Enter a temperature: ");
		// Check to see if the input was a float
		result = scanf("%f", &temp);

		if (result == 1)
		{
			// break the loop if input was valid
			break;
		}
		else
		{
			printf("Invalid Temperature.\n");
			// remove any excess characters in invalid input
			while (getchar() !=  '\n');
		}
	}
	while (1)
	{
		printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
		// Check to see if input is an int
		result = scanf("%d", &scaleIn);
		// Check to make sure input was valid and in bounds
		if (result == 1 && scaleIn <4 && scaleIn >0)
		{
			// break loop if input was valid
			break;
		}
		else
		{
			printf("Invalid scale choice.\n");
			// remove excess characters
			while (getchar() != '\n');
		}
	}
	while (1)
	{
		printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
		// Identical input checking as the former statement
		result = scanf("%d", &scaleOut);
		// Check to make sure input is in bounds
		if (result == 1 && scaleOut <4 && scaleOut >0)
		{
			// end loop if all the last variable is valid
			break;
		}
		else
		{
			printf("Invalid scale choice.\n");
			// run it again
			while (getchar() != '\n');	
		}
	}
	// Check specific invalid input cases
	if (scaleIn == 3 && temp < 0)
	{
		// handle a negative kelvin
		printf("\nKelvin cannot be negative!\n");
	}

	else if (scaleIn == scaleOut)
	{
		// inputs are the same
		printf("\nScale types are the same!\n");
	}

	else
	{
		// Print the converted temperature
		printf("Converted Temperature: %f\n", temp_converter(temp, scaleIn, scaleOut));
		if (scaleIn != 1)
		{
			// Run the function to print weather data if the input scale was not celsius
			weather_man(temp_converter(temp, scaleIn, 1));
		}
		else
		{
			// Run the function for weather data if celsius was given
			weather_man(temp);
		}
	}

}

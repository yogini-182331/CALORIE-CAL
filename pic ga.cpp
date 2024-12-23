#include <stdio.h>
#include <ctype.h>

// Function to calculate BMR based on gender, weight, height, and age
float calculateBMR(char gender, float weight, float height, int age) 
{
    if (gender == 'M' || gender == 'm') {
        // BMR formula for men
        return 88.36 + (13.4 * weight) + (4.8 * height) - (5.7 * age);
    } else if (gender == 'F' || gender == 'f') {
        // BMR formula for women
        return 447.6 + (9.2 * weight) + (3.1 * height) - (4.3 * age);
    } else {
        return -1; // Invalid gender
    }
}

// Function to calculate daily calorie needs based on activity level
float calculateCalories(float bmr, char activityLevel) {
    switch (toupper(activityLevel)) {
        case 'S': return bmr * 1.2;   // Sedentary
        case 'L': return bmr * 1.375; // Lightly active
        case 'M': return bmr * 1.55;  // Moderately active
        case 'V': return bmr * 1.725; // Very active
        case 'E': return bmr * 1.9;   // Extra active
        default: return -1;           // Invalid activity level
    }
}

// Function to validate if input is valid for gender
char validateGender() {
    char gender;
    while (1) {
        printf("Enter your gender (M for Male, F for Female): ");
        scanf(" %c", &gender);
        if (toupper(gender) == 'M' || toupper(gender) == 'F') {
            return gender;
        }
        printf("Invalid gender input. Please enter M or F.\n");
    }
}

// Function to validate if input is valid for activity level
char validateActivityLevel() {
    char activityLevel;
    while (1) {
        printf("Enter your activity level:\n");
        printf("S: Sedentary (little or no exercise)\n");
        printf("L: Lightly active (light exercise 1-3 days/week)\n");
        printf("M: Moderately active (moderate exercise 3-5 days/week)\n");
        printf("V: Very active (hard exercise 6-7 days/week)\n");
        printf("E: Extra active (very hard exercise, physical job): ");
        scanf(" %c", &activityLevel);
        if (toupper(activityLevel) == 'S' || toupper(activityLevel) == 'L' ||
            toupper(activityLevel) == 'M' || toupper(activityLevel) == 'V' || 
            toupper(activityLevel) == 'E') {
            return activityLevel;
        }
        printf("Invalid activity level. Please enter S, L, M, V, or E.\n");
    }
}

// Main function
int main() {
    int numUsers, i;
    
    printf("Welcome to the Calorie Calculator!\n");
    printf("How many users would you like to calculate for? ");
    scanf("%d", &numUsers);

    for (i = 1; i <= numUsers; i++) {
        printf("\nCalculating for User %d:\n", i);

        char gender = validateGender();

        float weight;
        printf("Enter your weight (in kg): ");
        while (scanf("%f", &weight) != 1 || weight <= 0) {
            printf("Invalid input. Please enter a valid weight in kg: ");
            while (getchar() != '\n'); // Clear invalid input
        }

        float height;
        printf("Enter your height (in cm): ");
        while (scanf("%f", &height) != 1 || height <= 0) {
            printf("Invalid input. Please enter a valid height in cm: ");
            while (getchar() != '\n'); // Clear invalid input
        }

        int age;
        printf("Enter your age (in years): ");
        while (scanf("%d", &age) != 1 || age <= 0) {
            printf("Invalid input. Please enter a valid age in years: ");
            while (getchar() != '\n'); // Clear invalid input
        }

        char activityLevel = validateActivityLevel();

        // Calculate BMR and daily calorie needs
        float bmr = calculateBMR(gender, weight, height, age);
        if (bmr == -1) {
            printf("Error in BMR calculation. Please check inputs.\n");
            continue;
        }

        float dailyCalories = calculateCalories(bmr, activityLevel);
        if (dailyCalories == -1) {
            printf("Error in calorie calculation. Please check activity level.\n");
            continue;
        }

        // Display results
        printf("\nResults for User %d:\n", i);
        printf("Your Basal Metabolic Rate (BMR) is: %.2f calories/day\n", bmr);
        printf("Your estimated daily calorie needs are: %.2f calories/day\n", dailyCalories);
    }

    printf("\nThank you for using the Calorie Calculator..\n");
    return 0;
}

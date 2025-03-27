#include <stdio.h> // Include required library

// Function to find possible combinations of scoring
void find_combinations(int score) {
    // Define the scores
    int td = 6, fg = 3, safety = 2, td2pt = 8, tdfg = 7;

    //Print the header
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
    
    // Iterate through all possible counts of TD + 2pt
    for (int i = 0; i <= score / td2pt; i++) {
        // Iterate TD + FG
        for (int j = 0; j <= score / tdfg; j++) {
            // Iterate TD
            for (int k = 0; k <= score / td; k++) {
                // Iterate FG
                for (int l = 0; l <= score / fg; l++) {
                    // Iterate through all possible counts
                    for (int m = 0; m <= score / safety; m++) {
                        // Check if it matches with the target score
                        if (i * td2pt + j * tdfg + k * td + l * fg + m * safety == score) {
                            // Output the combination
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, m);
                        }
                    }
                }
            }
        }
    }
}

// main function
int main() {

    // Variable to store the target score
    int score;

    // Loop to keep prompting the user for a score until a value less than or equal to 1 is entered
    while (1) {
        // Print instruction
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score); // get input from user

        // Exit the loop if score is 0 or 1
        if (score <= 1) {
            break;
        }

        find_combinations(score);  // Call function to find combinations
    }

    return 0;
}

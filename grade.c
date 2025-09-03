#include <stdio.h>

#define MAX_SCORE 100
#define MIN_SCORE 0

void calculateAverage(void);
void gradePoint(float avg);

int main(void)
{
	calculateAverage();
}

void calculateAverage(void)
{
	int numOfStudents;
	int numOfSubject;
	float sum = 0;

	printf("-----------Average Calculator-----------\n\n");
	printf("****************************************\n");
	printf("How many students?: ");
	scanf("%d", &numOfStudents);
	printf("Enter Number of Subjects: ");
	scanf("%d", &numOfSubject);
	printf("----------------Calculate---------------\n\n");
	printf("****************************************\n");

	if (numOfSubject > 0 && numOfStudents > 0) {
		float averages[numOfStudents];

		for (int i = 0; i < numOfStudents; i++) {
			for (int j = 0; j < numOfSubject; j++) {
				float score;
				do {
					printf("Enter score for Student %d, Subject %d: ",
					       i + 1, j + 1);
					scanf("%f", &score);
					if (score < MIN_SCORE || score > MAX_SCORE)
						printf("Invalid input! Score must be between %d and %d.\n",
						       MIN_SCORE, MAX_SCORE);
				} while (score < MIN_SCORE || score > MAX_SCORE);

				sum += score;
			}
			float average = sum / numOfSubject;
			averages[i] = average;
			printf("\n");
			sum = 0.0;
		}

		printf("------------------Result------------------\n");
		printf("#****************************************#\n");
		printf("Student | Average  | Grade\n");
		printf("----------------------------\n");

		for (int i = 0; i < numOfStudents; i++) {
			printf("%d       |   %.2f  |  ", i + 1, averages[i]);
			gradePoint(averages[i]);
			printf("\n");
		}

		/* Find the top student */
		float highestAverage = averages[0];
		int topStudentIndex = 0;

		for (int i = 1; i < numOfStudents; i++) {
			if (averages[i] > highestAverage) {
				highestAverage = averages[i];
				topStudentIndex = i;
			}
		}

		printf("\nTop student is Student %d with an average of %.2f\n",
		       topStudentIndex + 1, highestAverage);
		printf("Their grade is: ");
		gradePoint(highestAverage);

		printf("\n#*****************************************#\n\n");
	} else {
		printf("Invalid number of students or subjects!\n");
		return;
	}

	printf("##******************End******************##\n");
}

void gradePoint(float avg)
{
	if (avg >= 90.0)
		printf(" A");
	else if (avg >= 80.0)
		printf(" B");
	else if (avg >= 70.0)
		printf(" C");
	else if (avg >= 60.0)
		printf(" D");
	else
		printf(" F");
}




/// Students Grades Management System ///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* in our system
we use max number of students is 20 [fixed size]
and max number of subjects is    10  [fixed size]
*/
typedef struct students students; // now we create students data type

struct students
{
    int ID;
    char Name[30];
    char Grade;
    int numberOfSubjects;
    int Scores[10];
    float AvgGrade;
};

/// functions structure

int numOfStudents=0; // initial value (current number of students)
students students_arr[20]; /* here is array to store 20 students ,
in our system we use fixed size array which exist in stack memory
*/
/// Add Function :

void addStudent()
{
    if(numOfStudents>20)
    {
        printf(" you arrive to last student in table :( \n");
    }
    else
    {
        students newStudent; // create student record with  students data type
        printf("Enter student Id : \n");
        scanf("%d",&newStudent.ID);
        printf("Enter student Name : \n");
        scanf("%s",&newStudent.Name);
        printf("Enter number of subjects  : \n");
        scanf("%d",&newStudent.numberOfSubjects);
        for(int i=0; i<newStudent.numberOfSubjects; i++)
        {
            printf("Enter grade of sub[%d]: \n",i+1);
            scanf("%d",&newStudent.Scores[i]);
        }
        calcGrades(&newStudent); // to calculate the avg degree and final result
        students_arr[numOfStudents++]=newStudent; // store student data in array
        printf(" Student record added successfully :) \n");
    }
}

/// update function that update student record based on id that given from user!

void updateStudent()
{
    int id, found = 0; // we use a flag to check if the student is found
    printf("Enter the ID of the student you want to update:\n");
    scanf("%d", &id);

    for (int i = 0; i < numOfStudents; i++)
    {
        if (students_arr[i].ID == id)
        {
            found = 1;
            printf("Updating the scores of %s (ID: %d)\n", students_arr[i].Name, id);

            // Update scores
            for (int j = 0; j < students_arr[i].numberOfSubjects; j++)
            {
                printf("Enter new score for subject %d: ", j + 1);
                scanf("%d", &students_arr[i].Scores[j]);
            }


            calcGrades(&students_arr[i]); // here we will recalculate the degree after udpdate
            printf("Scores updated successfully :) \n");
            break;
        }
    }

    if (!found)
    {
        printf("Student with ID %d not found:( \n", id);
    }
}


/// create calculate function to calculate the scores of grades
/* in this function we will calculate  student avg grade and determine final result*/

void calcGrades(students *stuPtr)/* stuptr is pointer that refer to students data type
 , here it refer to address of students structure*/
{
    int result=0; // initial value of total grade
    for (int i = 0; i < stuPtr->numberOfSubjects; i++)
    {
        result += stuPtr->Scores[i];
    }
    stuPtr->AvgGrade = result / (float)stuPtr->numberOfSubjects;// here we can arrive to AvgGrade using stuptr to store avg degree
    if (stuPtr->AvgGrade >= 90)
    {
        stuPtr->Grade= 'A';
    }
    else if (stuPtr->AvgGrade >= 80)
    {
        stuPtr->Grade= 'B';
    }
    else if (stuPtr->AvgGrade >= 70)
    {
        stuPtr->Grade= 'C';
    }
    else if (stuPtr->AvgGrade >= 60)
    {
        stuPtr->Grade= 'D';
    }
    else
    {
        stuPtr->Grade= 'F';
    }
}


/// display result function

void displayResult()
{
    if(numOfStudents==0)
    {
        printf(" there is no student");
    }
    else
    {
        float totalAvgScore=0;
        int highestAvgscore=0;
        printf("\n---  display records ---\n");
        for(int i=0; i<numOfStudents; i++)
        {
            printf("ID: %d, Name: %s, Average: %.2f, Grade: %c\n",
                   students_arr[i].ID, students_arr[i].Name, students_arr[i].AvgGrade, students_arr[i].Grade);
            totalAvgScore += students_arr[i].AvgGrade;
            if (students_arr[i].AvgGrade > students_arr[highestAvgscore].AvgGrade)
            {
                highestAvgscore = i;
            }
        }

        printf("\n The highest Scorer: %s (ID: %d) with Average %.2f\n",
               students_arr[highestAvgscore].Name, students_arr[highestAvgscore].ID, students_arr[highestAvgscore].AvgGrade);
        printf("Overall Average Score: %.2f\n", totalAvgScore / numOfStudents);

        printf("\n students Who Passed :) \n");
        for (int i = 0; i < numOfStudents; i++)
        {
            if (students_arr[i].Grade!= 'F')
            {
                printf("ID: %d, Name: %s\n", students_arr[i].ID, students_arr[i].Name);
            }
        }
        printf("\n Students Who Failed :( \n");
        for (int i = 0; i < numOfStudents; i++)
        {
            if (students_arr[i].Grade == 'F')
            {
                printf("ID: %d, Name: %s\n",students_arr[i].ID, students_arr[i].Name);
            }
        }

    }
}


int main()
{

    // addStudent();
    int choice;

    do
    {
        printf("\n--- Students Grade Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            updateStudent();
            break;
        case 3:
            displayResult();
            break;
        case 4:
            printf("Exit :: Goodbye:)\n");
            break;
        default:
            printf("invalid choice!!! Plz try again.\n");
        }
    }
    while (choice != 4);
    return 0;
}

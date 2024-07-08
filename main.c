#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int i=0;

struct studentInfo
{
   char firstName[20];
   char lastName[20];
   int rollNumber;
   float Marks;
   int courseId[10];

} sdnt[500];

void addStudent(){
    int n;
    printf("ADD STUDENT DETAILS: \n");
    while (1)
    {        
        printf("1.Add\n");
        printf("2.done\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the first name of the student\n");
            scanf("%s", sdnt[i].firstName);
            printf("Enter the last name of the student\n");
            scanf("%s", sdnt[i].lastName);
            printf("Enter the roll number of the student\n");
            scanf("%d", &sdnt[i].rollNumber);
            printf("Enter the Marks of the student\n");
            scanf("%f", &sdnt[i].Marks);
            printf("Enter the course ID of each course of the student\n");
            for (int j = 0; j < 5; j++)
            {
                scanf("%d", &sdnt[i].courseId[j]);
            }
            i = i + 1;
            break;
        case 2:
            
            return;

        default:
            break;
        }
    }

}

void findByRollNumber()
{
   int temp;
   printf("Enter the roll number of the student\n");
   scanf("%d", &temp);

   printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","ROLL", "FIRSTNAME", "LASTNAME", "MARKS", "COURSE-1", "COURSE-2", "COURSE-3", "COURSE-4", "COURSE-5");

   for (int j = 0; j <= i; j++)
   {

        if (temp == sdnt[j].rollNumber)
        {
            printf("%-20d%-20s%-20s%-20.2f", sdnt[j].rollNumber, sdnt[j].firstName, sdnt[j].lastName, sdnt[j].Marks);

            for (int k= 0; k < 5; k++)
            {
                printf("%-20d", sdnt[j].courseId[k]);
            }
            printf("\n");
        }
   }
   
}

void findByName()
{
    char temp[20];
    printf("Enter the First Name of the Student\n");
    scanf("%s", temp);

    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","ROLL", "FIRSTNAME", "LASTNAME", "MARKS", "COURSE-1", "COURSE-2", "COURSE-3", "COURSE-4", "COURSE-5");

    for (int j = 0; j <= i; j++)
    {
        if (!strcmp(sdnt[j].firstName, temp))
        {
            printf("%-20d%-20s%-20s%-20.2f", sdnt[j].rollNumber, sdnt[j].firstName, sdnt[j].lastName, sdnt[j].Marks);

            for (int k= 0; k < 5; k++)
            {
                printf("%-20d", sdnt[j].courseId[k]);
            }
            printf("\n");
        }
    }

}

void findCourse_Student()
{
    int temp;
    printf("Enter the course ID\n");
    scanf("%d", &temp);

    int c = 0;

    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","ROLL", "FIRSTNAME", "LASTNAME", "MARKS", "COURSE-1", "COURSE-2", "COURSE-3", "COURSE-4", "COURSE-5");
    for (int j = 0; j <= i; j++)
    {
        for (int d = 0; d < 5; d++)
        {
            if (temp == sdnt[j].courseId[d])
            {
                printf("%-20d%-20s%-20s%-20.2f", sdnt[j].rollNumber, sdnt[j].firstName, sdnt[j].lastName, sdnt[j].Marks);

                for (int k= 0; k < 5; k++)
                {
                    printf("%-20d", sdnt[j].courseId[k]);
                }
                printf("\n");
            }
        }
    }
   
}

void totalCount()
{
   printf("The total number of students currently in the system is %d\n", i);
   
}


void deleteStudent()
{
   int temp;
   printf("Enter the roll number of the student\n");
   scanf("%d", &temp);
   for (int j = 0; j <= i; j++)
   {
      if (temp == sdnt[j].rollNumber)
      {
         for (int k = j; k < 499; k++)
         {
            sdnt[k] = sdnt[k + 1];
         }
         i--;
      }
   }
   printf("The entered student's record deleted successfully");
}


void updateStudent()
{
   int temp;
   printf("Enter the roll number of the student\n");
   scanf("%d", &temp);
   for (int j = 0; j < i; j++)
   {
      if (temp == sdnt[j].rollNumber)
      {
         printf("1. First Name\n"
                "2. Last Name\n"
                "3. Roll Number\n"
                "4. CGPA\n"
                "5. Courses\n");
         int c;
         scanf("%d", &c);
         switch(c) {
            case 1:
                printf("Enter the updated first name : ");
                scanf("%s", sdnt[j].firstName);
                break;
            case 2:
                printf("Enter the updated last name : ");
                scanf("%s", sdnt[j].lastName);
                break;
            case 3:
                printf("Enter the updated roll number : ");
                scanf("%d", sdnt[j].rollNumber);
                break;
            case 4:
                printf("Enter the updated CGPA : ");
                scanf("%f", sdnt[j].Marks);
                break;
            case 5:
                printf("Enter the updated list of courses: ");
                for (int k = 0; k < 5; k++)
                {
                    scanf("%d", &sdnt[j].courseId[k]);
                }
               break;
         }
         printf("Records updated successfully");
      }
   }
}

int main()
{

    int taskToPerform;

    printf("\n\n****************************************************************************************************\n");
    printf("****************************************************************************************************\n");
    printf("********   Student Management System    ******\n");
    printf("****************************************************************************************************\n");
    printf("****************************************************************************************************\n\n\n");
    while (1)
    {
        printf("Enter the task that you want to perform\n");
        printf("1. Add a new Student Detail\n");
        printf("2. Find the details of a Student using Roll Number\n");
        printf("3. Find the details of a Student using the First Name\n");
        printf("4. Find the details of Students using the Coursed Id\n");
        printf("5. Find Total number of Students\n");
        printf("6. Delete the details of an Student\n");
        printf("7. Update the details of an Student\n");
        printf("8. Exit\n");
        scanf("%d", &taskToPerform);

        switch (taskToPerform)
        {
        case 1:
            addStudent();
            break;
        case 2:
            findByRollNumber();
            break;
        case 3:
            findByName();
            break;
        case 4:
            findCourse_Student();
            break;
        case 5:
            totalCount();
            break;
        case 6:
            deleteStudent();
            break;
        case 7:
            updateStudent();
            break;
        case 8:
            exit(0);
            break;
        default:
            exit(0);
        }
    }

    return 0;
}

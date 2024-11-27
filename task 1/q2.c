#include <stdio.h>
#include <string.h>
#define MAX_FLOORS 10;






int main() {

    char names[][50] = {"You requested to go to the Zeroth floor\n","You requested to go to the First floor\n","You requested to go to the Second floor\n","You requested to go to the Third floor\n","You requested to go to the Fourth floor\n","You requested to go to the Fifth floor\n","You requested to go to the Sixth floor\n","You requested to go to the Seventh floor\n","You requested to go to the Eighth floor\n","You requested to go to the Ninth floor\n"};
    char floors[] = "0123456789";
    int cur_floor = 0, floor = 0;
    printf("Elevator is currently at floor: 0\n");
    while(floor != -1)
    {
        printf("Enter the floor number you wish to go to (-1 to exit):\n");
        scanf("%d",&floor);
        printf("%s", names[floor]);
        if (floor == cur_floor)
        {
            printf("Arrived at Floor %c\n" ,floors[cur_floor]);
        }
        else if (floor > 9 || floor < -1)
        {
            printf("You requested to go to the Number is out of range.\n");
            printf("Invalid floor number.\n");
        }
        else if (floor == -1)
        {
            printf("You requested to go to the Number is out of range.\n");
            printf("Elevator simulation ended.\n");
        }
        else if (floor > cur_floor)
        {
            while (cur_floor < floor)
            {
                printf("Passing Floor %c\n" , floors[cur_floor]);
                cur_floor++;
            }
            printf("Passing Floor %c\n" , floors[cur_floor]);
            printf("Arrived at Floor %c\n" ,floors[cur_floor]);
        }
        else if (floor < cur_floor)
        {
            while (cur_floor > floor)
            {
                cur_floor--;
                printf("Passing Floor %c\n" , floors[cur_floor]);
            }
            printf("Arrived at Floor %c\n" ,floors[cur_floor]);
        }



    }

    return 0;
}

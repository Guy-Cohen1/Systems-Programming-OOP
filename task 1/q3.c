#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep function
// Define a structure for the smart home state


typedef struct {
    bool lamp1;
    bool lamp2;
    bool lamp3;
    int dimmerALevel; // 0 to 4
    int dimmerBLevel; // 0 to 4
    int temperatureRoomLevel; // 0 to 9
} SmartHomeState;
// Function prototypes
void initializeSmartHome(SmartHomeState *state);
void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int
dimmerB);
void updateTemperature(SmartHomeState *state, int temperature);
void printSmartHomeState(const SmartHomeState *state);
void drawRoom(const SmartHomeState *state);
bool isValidInput(char d);
void getSimCode(int arr[]);



int main() {
    SmartHomeState state;
    int i, simcode[5];
    getSimCode(simcode);//It convert from char digits into integer digits
    for (int i=0; i<5;i++) {
        if (simcode[i]  < 1 || simcode[i] > 5) {
            printf("Invalid input. Please enter digits from 1 to 5 only.\n");
            getSimCode(simcode);
        }
    }
    initializeSmartHome(&state);
    // Simulate different situations
    for (i = 0; i < 5; i++) {
        //update new home state base on the given code (e.g 24553)
        updateLighting(&state, i % simcode[0] == 0, i % simcode[1] == 0, i % simcode[2] == 0, i % simcode[3],
                       (4 - i) % simcode[4]);
        updateTemperature(&state, i);
        printSmartHomeState(&state);
        drawRoom(&state);
        sleep(1); // sleep for 1 second
    }
    return 0;
}
void initializeSmartHome(SmartHomeState *state)
{
    (*state).lamp1 = false;
    (*state).lamp2 = false;
    (*state).lamp3 = false;
    state->dimmerALevel = 0;
    state->dimmerBLevel = 0;
    state->temperatureRoomLevel = 0;
}

void updateLighting(SmartHomeState *state, bool lamp1, bool lamp2, bool lamp3, int dimmerA, int
dimmerB)
/*
      This function update the lighting
*/

{
    (*state).lamp1 = lamp1;
    (*state).lamp2 = lamp2;
    (*state).lamp3 = lamp3;
    state->dimmerALevel = dimmerA;
    state->dimmerBLevel = dimmerB;
}

void updateTemperature(SmartHomeState *state, int temperature)
/*
      This function update the temperature
*/
{
    state->temperatureRoomLevel = temperature;
}

void printSmartHomeState(const SmartHomeState *state)
/*
      This function printing home details
*/{
    printf("Lamps: 1[%s] 2[%s] 3[%s]\n",
           state->lamp1 ? "ON" : "OFF",
           state->lamp2 ? "ON" : "OFF",
           state->lamp3 ? "ON" : "OFF");
    printf("Dimmer Levels: A[%d] B[%d]\n", state->dimmerALevel, state->dimmerBLevel);
    printf("Temperature: %d°C\n", state->temperatureRoomLevel);
}




void getSimCode(int arr[])
//It convert from char digits into integer digits
{
    const char simCode[200];
    printf("Simulation senario code: Enter Five digits without spaces (1-5): \n");
    scanf("%s", simCode); // Replace this with your actual char digits
    printf("You entered: ");
    for (int i =0; i<5;i++) {
        if(i<4)
        printf("%c, ", simCode[i]);
        else printf("%c \n", simCode[i]);
    }
    for (int i = 0; i < 5; i++) {
         arr[i] = simCode[i] - '0';
    }
}

void drawRoom(const SmartHomeState *state)
/*
      This function draw room details
*/
{
    printf("Lamp 1: ");
    if (state->lamp1) {
        for (int i = 0; i <= state->dimmerALevel; ++i) {
            printf("*");
        }
        printf("\n");
    } else printf("-\n");
    printf("Lamp 2: ");
    if (state->lamp2) {
        for (int i = 0; i <= state->dimmerALevel; ++i) {
            printf("*");
        }
        printf("\n");
    } else printf("-\n");
    printf("Lamp 3: ");
    if (state->lamp3) {
        for (int i = 0; i <= state->dimmerBLevel; ++i) {
            printf("*");
        }
        printf("\n");
    } else printf("-\n");
    printf("Temperature: ");
    for(int i = 0; i<=state->temperatureRoomLevel;i++)
        printf("-");
    printf("\n");
}
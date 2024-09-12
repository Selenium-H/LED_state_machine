// Program to test the virtual functioning of a group of LED in a system.

#include<stdint.h>  // For the uint datatypes
#include<stdio.h>   // For standard I/O

#define ON 1   // LED state ON 
#define OFF 0  // LED satate OFF

#define INVALID_RGB_COLOR_FORMAT -1  

#define LED_COUNT 3


// Stucture to store the settings parameters of the LED
struct LEDSettings {
    uint8_t state;
    uint8_t brightness;
    uint32_t color;    
};

// Structure to hold the individual as well as the group settings of the LED
struct LEDGroup {
    struct LEDSettings singleLED;
    uint8_t groupState;
    uint8_t groupBrightness; 
};

// Displays the statuses of the LEDs
int displayLEDGroupStatus(struct LEDGroup* group) {
    int i = 0;
    
    for(i=0;i< LED_COUNT; i++) { 
        printf("\nLED STATUS");
        printf("\nIndividual LED > state: %d",      group[i].singleLED.state);
        printf("\nIndividual LED > brightness: %d", group[i].singleLED.brightness);
        printf("\nIndividual LED > color: %d",      group[i].singleLED.color);
        printf("\nLED Group > state: %d",           group[i].groupState);
        printf("\nLED Group > brightness: %d\n",    group[i].groupBrightness);
    }   
}


// Updtates the LED settings of the individual LEDs and the group
int updateLEDGroupSettings(
    struct LEDGroup* group,
    uint8_t groupState,
    uint8_t groupBrightness,
    uint8_t state,
    uint8_t brightness,
    uint32_t color
) {
    int i = 0;
    
    // Check if the RGB format is correct
    if(color > 255255255) {
        return INVALID_RGB_COLOR_FORMAT;
    }
    
    for(i=0;i< LED_COUNT; i++) {     
        group[i].singleLED.state = state;
        group[i].singleLED.brightness = brightness;
        group[i].singleLED.color = color;
        group[i].groupState = groupState;
        group[i].groupBrightness = groupBrightness;   
    }   
    
    return 0; 

}

// Initializes the settings of individual LEDs and the group the are in.
int initLEDGroup(struct LEDGroup* group) {
    // call the updateLEDGroupSettings with the default initial parameters
    return updateLEDGroupSettings(
        group,
        OFF,
        0,
        OFF,
        0,
        0
    );
}


// Entry point for the program
int main(void) {
    // Declare an array of LEDs which forms a group.
    struct LEDGroup boardLED[LED_COUNT];
    // Initializes all the LEDs
    initLEDGroup(boardLED);
   
    updateLEDGroupSettings(
        boardLED, 
        ON,
        128,
        ON,
        128, 
        255000000 
    );
    
    displayLEDGroupStatus(boardLED);    
}



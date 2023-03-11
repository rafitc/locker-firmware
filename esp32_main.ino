#include <Arduino_FreeRTOS.h>
#include <WiFi.h>
#include <PubSubClient.h>

// -----All locker and pin mapping 


// Struct for handling each locker 
struct locker_map
{
    int LED_R; //ALLOC
    int LED_G; //Unalloc and //Combination of R,G is FOR OPEN 
}L_MAP[12];

enum struct_member{LED_R, LED_G};
struct_member mode;

void changeStateOfLed(int num, bool state){
    if (num <= 16){
        Serial.println("In i2c one ");
    }
    else{
        Serial.println("in i2c two ")
    }
}

void init_locker_pins(L_MAP[12]) {

    L_MAP[0].LED_R = 1 ; L_MAP[0].LED_R = 2 ; L_MAP[0].LED_R = 3 ;
    L_MAP[1].LED_R = 4 ; L_MAP[1].LED_R = 5 ; L_MAP[1].LED_R = 6 ;
    L_MAP[2].LED_R = 7 ; L_MAP[2].LED_R = 8 ; L_MAP[2].LED_R = 9 ;
    // L_MAP[3].LED_R = 1 ; L_MAP[3].LED_R = 1 ; L_MAP[3].LED_R = 1 ;
    // L_MAP[4].LED_R = 1 ; L_MAP[4].LED_R = 1 ; L_MAP[4].LED_R = 1 ;
    // L_MAP[5].LED_R = 1 ; L_MAP[5].LED_R = 1 ; L_MAP[5].LED_R = 1 ;
    // L_MAP[6].LED_R = 1 ; L_MAP[6].LED_R = 1 ; L_MAP[6].LED_R = 1 ;
    // L_MAP[7].LED_R = 1 ; L_MAP[7].LED_R = 1 ; L_MAP[7].LED_R = 1 ;
    // L_MAP[8].LED_R = 1 ; L_MAP[8].LED_R = 1 ; L_MAP[8].LED_R = 1 ;
    // L_MAP[9].LED_R = 1 ; L_MAP[9].LED_R = 1 ; L_MAP[9].LED_R = 1 ;
    // L_MAP[10].LED_R = 1 ; L_MAP[10].LED_R = 1 ; L_MAP[10].LED_R = 1 ;
    // L_MAP[11].LED_R = 1 ; L_MAP[11].LED_R = 1 ; L_MAP[11].LED_R = 1 ;
}

bool state_of_pin(int id, int mode){
    if (mode == 0){
        Serial.println("Reading pin val of LED_R of Locker %d", L_MAP[id].LED_R)
        return true;
    }
    else if(mode == 1){
        Serial.println("Reading pin val of LED_G of Locker %d", L_MAP[id].LED_G)
        return false;
    }
}
void turn_on_led(int id, int mode){
    if (mode = 0){
        Serial.println("output of pin set to %d - %d", L_MAP[id].LED_R)
    }
    if (mode = 1){
        Serial.println("output of pin set to %d - %d", L_MAP[id].LED_G)
    }
    if (mode == 2){
        Serial.println("output of pin set to %d - %d", L_MAP[id].LED_R)
        Serial.println("output of pin set to %d - %d", L_MAP[id].LED_G)
    }
}
void lock_alloc(int arr[]){
    for(int i=0; i<12; i++){
        //make sure LED_R is off 
        state = state_of_pin(locker, LED_R);
        if (state != HIGH){
            turn_on_led(4, LED_R)
        }
    }
}

void alloc_led()

void TaskOne(void *pvParameter); //two tasks
void TaskTwo(void *pvParameter);

void setup() {
  Serial.begin(115200);
  delay(100);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  //----setup tasks----//

  xTaskCreate(
    TaskOne, //task function
    "Task One", //just for reference
    128, //stack size
    NULL,
    2,//Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    NULL );

  xTaskCreate(
    TaskTwo, //task function
    "Task Two", //just for reference
    128, //stack size
    NULL,
    1,//Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    NULL );

}
// In setup 
/*
init MQTT connection 

In Loop
2 tasks. 
one for fetching data from mqtt and updating list based on that, 
next task for readig input from button and act acordingly. Next one for 
on/off led based on the data coming from mqtt 

if any issue in connection. show it in board by arrangment of led 
error codes can be displayed in that way.

*/
void loop() {
  // Empty
}

void TaskOne(void *pvParameter) {
  (void) pvParameter;
  while (1) {
    Serial.println("Task One ");
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}

void TaskTwo(void *pvParameter) {
  (void) pvParameter;
  while (1) {
    Serial.println("Task Two ");
    vTaskDelay( 2000 / portTICK_PERIOD_MS ); // wait for one second
  }
}

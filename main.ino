/*

AQLIM smart locker firmware for locker
This is the firmware for to control the assigned locker deatils with set of LED conditions

*/

// ----- All the pre defined values goes HERE
// Add your MQTT Broker IP address, example:
// const char* mqtt_server = "192.168.1.144";

void setup()
{
    Serial.begin(115200);
    setupSmartConfig();
    setupMqttBrocker();
}

void loop()
{
    // TODO rewrite with free RTOS Task
    checkForWifiReConfig();
    delay(100);

    // Check for MQTT
    // Check for MQTT
    if (!client.connected())
    {
        reconnect();
    }
    client.publish("rafi/humidity", "HIII");
    delay(2000);
    client.loop();
}
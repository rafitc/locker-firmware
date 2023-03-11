#include <PubSubClient.h>

PubSubClient client(espClient);

// Add your MQTT Broker IP address, example:
// const char* mqtt_server = "192.168.1.144";
#define MQTT_SERVER = "test.mosquitto.org"
#define MQTT_TOPIC_OF_LOCKER_LED_STATUS = "aqlim/locker/notify/led/"

void setupMqttBrocker()
{
    // MQTT COnfig
    client.setServer(MQTT_SERVER, 1883);
    client.setCallback(callback);
    // Subscribe
    client.subscribe(MQTT_TOPIC_OF_LOCKER_LED_STATUS);
}

// MQTT reconnect
void reconnect()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP8266Client"))
        {
            Serial.println("connected");
            // Subscribe
            client.subscribe("esp32/output");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void callback(char *topic, byte *message, unsigned int length)
{
    Serial.print("Message arrived on topic: ");
    Serial.print(topic);
    Serial.print(". Message: ");
    String messageTemp;

    for (int i = 0; i < length; i++)
    {
        Serial.print((char)message[i]);
        messageTemp += (char)message[i];
    }
    Serial.println();

    // Feel free to add more if statements to control more GPIOs with MQTT

    // If a message is received on the topic esp32/output, you check if the message is either "on" or "off".
    // Changes the output state according to the message
    if (String(topic) == MQTT_TOPIC_OF_LOCKER_LED_STATUS)
    {
        Serial.print("Message Recevied : %s", messageTemp);
    }
}
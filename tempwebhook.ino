// This #include statement was automatically added by the Particle IDE.
#include <JsonParserGeneratorRK.h>

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

#define DHTPIN D7     // what pin we're connected to

// Here we define the type of sensor used
#define DHTTYPE DHT11        // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

void CreateStringTempHum(double temp, double hum)
{
    JsonWriterStatic<256> jw;
    {
        JsonWriterAutoObject obj(&jw);
        jw.insertKeyValue("temp", temp);
        jw.insertKeyValue("hum", hum);
    }
    
    Particle.publish("temp", jw.getBuffer(), PRIVATE);
}

void setup() 
{
    dht.begin();
    pinMode(DHTPIN, INPUT);
}

void loop() 
{
    double temp = dht.getTempCelcius();
    double hum = dht.getHumidity();
    
    CreateStringTempHum(temp, hum);

    delay(30000);               // Wait for 30 seconds
}
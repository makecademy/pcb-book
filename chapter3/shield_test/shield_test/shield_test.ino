/*************************************************** 
  This is a sketch to test the HA Shield
  
  Written by Marco Schwartz for Open Home Automation
 ****************************************************/
 
const int relay_pin = 7; // Relay pin

// Define current sensor pin
#define CURRENT_SENSOR A1

// Define measurement variables
float amplitude_current;
float effective_value;
float effective_voltage = 230; // Set voltage to 230V (Europe) or 110V (US)
float effective_power;
float zero_sensor;

void setup() {
  Serial.begin(9600);
  pinMode(relay_pin,OUTPUT);
  
  // Calibrate sensor with null current
  zero_sensor = getSensorValue();
  Serial.print("Zero point sensor: ");
  Serial.println(zero_sensor);
  Serial.println("");
  
  delay(5000);
}

void loop() {
  
  // Activate relay
  digitalWrite(relay_pin, HIGH);
  
   // Perform power measurement
  float sensor_value = getSensorValue();
  Serial.print("Sensor value relay ON: ");
  Serial.println(sensor_value);
  
  // Wait for 1 second
  delay(5000);
  
   // Deactivate relay
  digitalWrite(relay_pin, LOW);
  
  // Perform power measurement
  sensor_value = getSensorValue();
  Serial.print("Sensor value relay OFF: ");
  Serial.println(sensor_value);
  
  // Wait for 1 second
  delay(5000);
 
}

// Get the reading from the current sensor
float getSensorValue()
{
  int sensorValue;
  float avgSensor = 0;
  int nb_measurements = 100;
  for (int i = 0; i < nb_measurements; i++) {
    sensorValue = analogRead(CURRENT_SENSOR);
    avgSensor = avgSensor + float(sensorValue);
  }	  
  avgSensor = avgSensor/float(nb_measurements);
  return avgSensor;
}

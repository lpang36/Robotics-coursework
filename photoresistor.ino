
//PhotoResistor Pin
int lightPin = 0; 
//LED Pin
int ledPin = 9;   
void setup()
{
  pinMode(ledPin, OUTPUT); //sets the led pin to output
}
void loop()
{
 int lightLevel = analogRead(lightPin); //Read the
                                        // lightlevel
 lightLevel = map(lightLevel, 200, 250, 0, 255); 
 lightLevel = constrain(lightLevel, 0, 255);//make sure the 
                                           //value is betwween 
                                           //0 and 255
 analogWrite(ledPin, lightLevel);  //write the value
}

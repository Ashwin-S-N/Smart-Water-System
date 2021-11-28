int trigger_pin = 2;
int echo_pin = 3;
int buzzer_pin = 10; 
int led_pin= 7;
int t;
int distance; 
void setup ( ) {
        Serial.begin (9600); 
        pinMode (trigger_pin, OUTPUT); 
        pinMode (echo_pin, INPUT);
        pinMode (buzzer_pin, OUTPUT);
        pinMode (led_pin, OUTPUT);
}
void loop ( ) {
    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    t = pulseIn (echo_pin, HIGH);
    distance = (t * 0.034) / 2;
  if (distance <= 4) 
        {
 
        digitalWrite (buzzer_pin, HIGH);
        digitalWrite (led_pin,HIGH);
        delay (500);
        }
  else {

        digitalWrite (buzzer_pin, LOW);
        digitalWrite (led_pin,LOW);
        delay (500);        
  } 
  }

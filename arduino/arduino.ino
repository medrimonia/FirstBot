
char leftMode  = 1;
char rightMode = 1;
char leftPWM   = 0;
char rightPWM  = 0;

// Initialization
void setup()
{
  pinMode( 9, OUTPUT);
  pinMode( 7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode( 8, OUTPUT);

  Serial.begin(115200);          // Baudrate = 115200
  Serial.flush();                // Flush buffer
  
  Serial.write('O');
}

// Main loop
void loop()
{
  SCmode();
  
  digitalWrite( 7, leftMode );
  analogWrite ( 9, leftPWM  );
  digitalWrite( 8, rightMode);
  analogWrite (10, rightPWM );
  
  //if(leftPWM > 0) {
  //  leftPWM--;
  //}
  //if(rightPWM >0) {
  //  rightPWM--;  
  //}
}

// Discussion for serial communication
void SCmode()
{
  if(Serial.available() >= 5)
  {
    char serialSecurity = Serial.read();
    if(serialSecurity == '$')
    {
      leftMode  = Serial.read();
      leftPWM   = Serial.read();
      rightMode = Serial.read();
      rightPWM  = Serial.read();    
    }
  }
}


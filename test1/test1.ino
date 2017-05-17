const int buttonPin = 2;
int buttonState = 0;
int lastButtonState = LOW;
void setup() {
  pinMode(buttonPin, INPUT);   
}
void loop(){
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState and buttonState == LOW)
  {
    system("echo 'hello, world!' > /home/root/hello.txt");
  }
  lastButtonState = buttonState;
}

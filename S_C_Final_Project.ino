float potvolt = 0;
float tempvolt = 0;
int LMtemp = 0;
int real_temp = 0;
int error = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
tempvolt = analogRead(A1);
potvolt = analogRead(A0);

LMtemp = (((20*tempvolt/(1023))*(5)/(.01))-2.5)/37;
real_temp = 40 - (((20*potvolt/(1023))*(5)/(.01)) - 2.5)/500;
error = real_temp - LMtemp;

if (real_temp > LMtemp)
{
  analogWrite(3,205-(real_temp-LMtemp));
}
if (LMtemp > real_temp)
{
  analogWrite(3,205+(LMtemp-real_temp));
}

Serial.print("P Temp: ");
Serial.print('\t');
Serial.println(real_temp);

Serial.print("M Temp: ");
Serial.print('\t');
Serial.println(LMtemp);
Serial.println('\t');
Serial.println('\t');

}

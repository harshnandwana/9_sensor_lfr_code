int sl=0,sr=0,sl1=0,sr1=0;
int s1[9]={A0,A1,A2,A3,2,A4,A5,A6,A7};
int s[9]={A0,A1,A2,A3,2,A4,A5,A6,A7};
 int time,i,j,max=0,min=1023,sub,sum,sum1,sub1;

 #define LM1 3       // left motor
 #define LM2 5       // left motor
 #define RM1 6     // right motor
 #define RM2 9     // right motor
 #define LED 13    //LED

void setup()
 {
   pinMode(A0, INPUT); pinMode(A1, INPUT); pinMode(A2, INPUT);pinMode(A3, INPUT);//pinMode(2, INPUT);
   pinMode(A4, INPUT);pinMode(A5, INPUT);//pinMode(A6, INPUT);pinMode(A7, INPUT);
   pinMode(LM1, OUTPUT); pinMode(LM2, OUTPUT); pinMode(RM1, OUTPUT); pinMode(RM2, OUTPUT); pinMode(LED, OUTPUT);
   Serial.begin(9600);
 }
void FWD();void LEFT();void RIGHT();
void loop(){
   s[0]= analogRead(A0);s[1]= analogRead(A1);s[2]= analogRead(A2);s[3]= analogRead(A3);s[4]= digitalRead(2);s[5]= analogRead(A4);s[6]= analogRead(A5);s[7]= analogRead(A6);s[8]= analogRead(A7);

int time=millis();
 if(time<80000)
 {
  for(i=0;i<8;i++)
  {if(max<s[i]){max=s[i];}}
  for(j=0;j<8;j++)
  {if(min>s[j]){min=s[i];}}
 }
 else
 {  for(int i=0;i<8;i++)
  { s[i]=map(s[i],min,max,0,180);
  s1[i]=map(s1[i],min,max,0,180);}
 s[1]=s[1]/1.2;s[2]=s[2]/1.5;s[3]=s[3]/2; s[5]=s[5]/1.2;s[6]=s[6]/1.5;s[7]=s[7]/2;
 for(i=0;i<4;i++)
  {   sl+=s[i];
      sr+=s[i+5];}
  sub=sl-sr;sum=sl+sr;
  if(sum<100)
  {if(s[4]=HIGH)
  {  FWD(0);delay(100);
      FWD(150);delay(350);
      FWD(0);delay(300);
      Read();
          if(sum1<100)//STOP
        {
      digitalWrite(LED,HIGH);
     FWD(0);
      delay(1000000000);
        }
          else{ 
            RIGHT(abs(sub));
            delay(700);} }}
   else{
  if(abs(sub)<12){FWD(300);}//fwd
  else if(sub<0){ LEFT(abs(sub));}//lefft
  else if(sub>0){ RIGHT(abs(sub));}///right
  else if (sum>900){LEFT(500);}//dead end
   }
   }}
      
void FWD(int x)
{
     analogWrite(LM1, x);
     analogWrite(LM2,0 );
     analogWrite(RM1, x);
     analogWrite(RM2, 0);
     SHOW(x,0,x,0);
}
void LEFT(int x)
{
  x=map(x,0,540,0,255);
     analogWrite(LM1, 0);
     analogWrite(LM2, x);
     analogWrite(RM1, x);
     analogWrite(RM2, 0);
     SHOW(0,0,70,0);
}
void RIGHT(int x)
{  x=map(x,0,540,0,255);
     analogWrite(LM1, x);
     analogWrite(LM2, 0);
     analogWrite(RM1, 0);
     analogWrite(RM2, x);
     SHOW(0,0,70,0);
}
  void Read()
{
s1[0]= analogRead(A0);s1[1]= analogRead(A1);s1[2]= analogRead(A2);s1[3]= analogRead(A3);s1[4]= digitalRead(2);s1[5]= analogRead(A4);s1[6]= analogRead(A5);s1[7]= analogRead(A6);s1[8]= analogRead(A7);
 for(i=0;i<4;i++)
  {   sl1+=s[i];
      sr1+=s[i+5];}
  sub=sl1-sr1;sum=sl1+sr1;
}
void SHOW(int m,int n,int p,int q)
{
 Serial.println(m);
 Serial.println(n);
 Serial.println(p);
 Serial.println(q);
 Serial.println(); 
}


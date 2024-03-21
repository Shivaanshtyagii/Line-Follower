void setup()  
{ 
  pinMode(13, INPUT);//left sensor 1    
  pinMode(12, INPUT); //left sensor 2 
  pinMode(11, INPUT); //middle sensor3 
  pinMode(10, INPUT); //right sensor 4 
  pinMode(9, INPUT); //right  sensor5
  
  //LEFT MOTOR.
  pinMode(8, OUTPUT);  
  pinMode(7, OUTPUT);
  
  //RIGHT MOTOR. 
  pinMode(6, OUTPUT);   
  pinMode(5, OUTPUT); 
}   

void loop() 
{ 
  int LeftMost = !digitalRead(13); 
  int Left = !digitalRead(12); 
  int Middle = !digitalRead(11); 
  int Right = !digitalRead(10);  
  int RightMost = !digitalRead(9); 

//FORWARD 
if ((LeftMost == 0 && Left == 0 && Middle == 1 && Right==0 && RightMost== 0)||(LeftMost == 0 && Left == 1 && Middle == 1 && Right==1 && RightMost== 0))
  { 
    digitalWrite(8, HIGH); 
    digitalWrite(7, LOW); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, LOW); 
  }

//Smooth LEFT TURN
else if ((LeftMost == 0 && Left == 1 && Middle == 0 && Right==0 && RightMost==0)||(LeftMost==0 && Left== 1 && Middle==1 &&Right== 0 && RightMost==0)
||(Leftmost==1 && Left== 1 && Middle==1 && Right==1 && RightMost==0)||(LeftMost==1 && Left== 1 && Middle==1 && Right==0 && RightMost==0))
  { 
    digitalWrite(8,LOW); 
    digitalWrite(7,LOW); 
    digitalWrite(6,HIGH); 
    digitalWrite(5,LOW); 
  } 
  
//Smooth RIGHT TURN
else if ((LeftMost == 0 && Left == 0 && Middle == 0 && Right==1 && RightMost==0)||(LeftMost==0  && Left==  0 && Middle==1  &&Right== 1  &&RightMost==1)
||(LeftMost==0 && Left== 1 && Middle==1 &&Right== 1 &&RightMost==1)||(LeftMost==0 && Left== 0 && Middle==1 &&Right== 1 &&RightMost==0))  
   { 
    digitalWrite(8, HIGH); 
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(5, LOW); 
   } 
//Sharp Right Turn
else if ((LeftMost==0 && Left== 0 && Middle==0 &&Right==1 &&RightMost==1)||(LeftMost==0 && Left== 0  && Middle==0 && Right== 0 && RightMost==1)){
    digitalWrite(8, HIGH); 
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(5, HIGH);
}
//Sharp left turn
else if ((LeftMost==1 && Left==1 && Middle==1 &&Right==0 &&RightMost==0)||(LeftMost==1  &&  Left== 0  && Middle==0 &&Right== 0 &&RightMost==0)){
    digitalWrite(8, LOW); 
    digitalWrite(7, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, LOW);
}
// BACK
else if (LeftMost == 0 && Left ==0  && Middle ==0  && Right==0 && RightMost==0){ 
    digitalWrite(8, LOW); 
    digitalWrite(7, HIGH); 
    digitalWrite(6, LOW); 
    digitalWrite(5, HIGH);    
    }
    
//STOP
else if (LeftMost == 1 && Left == 1 && Middle == 1 && Right==1 && RightMost== 1){
    digitalWrite(8, LOW); 
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(5, LOW);
    }
    else 
    {
     digitalWrite(8, HIGH); 
    digitalWrite(7, LOW); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, LOW);
      
  }
}

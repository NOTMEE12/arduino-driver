/*
git!

echo "# arduino-driver" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M master
git remote add origin https://github.com/NOTMEE12/arduino-driver.git
git push -u origin master

*/

int Front_right = 4;
int Front_left = 5;
int Back_right = 3;
int Back_left = 1;


void moveMotors(String direction){
  bool condition_met = false;
  // Front and all similiar directions
  if(direction == "Front-left"){
    digitalWrite(Front_right, HIGH);
    condition_met = true;
  }
  else if(direction == "Front-right"){
    digitalWrite(Front_left, HIGH);
    condition_met = true;
  }
  else if(direction == "Front"){
    condition_met = true;
    digitalWrite(Front_right, HIGH);
    digitalWrite(Front_left, HIGH);
  }
  // Back and all similiar directions
  else if(direction == "Back-left"){
    digitalWrite(Back_right, HIGH);
    condition_met = true;
  }
  else if(direction == "Back-right"){
    digitalWrite(Back_left, HIGH);
    condition_met = true;
  }
  else if(direction == "Back"){
    digitalWrite(Back_left, HIGH);
    digitalWrite(Back_right, HIGH);
    condition_met = true;
  }
  if(condition_met){
    delay(1500);
    digitalWrite(Front_right, LOW);
    digitalWrite(Front_left, LOW);
    digitalWrite(Back_left, LOW);
    digitalWrite(Back_right, LOW);
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(Front_right, OUTPUT);
  pinMode(Front_left, OUTPUT);
  pinMode(Back_left, OUTPUT);
  pinMode(Back_right, OUTPUT);
  digitalWrite(Front_right, LOW);
  digitalWrite(Front_left, LOW);
  digitalWrite(Back_left, LOW);
  digitalWrite(Back_right, LOW);
}

void loop() {
	moveMotors("Front");
  	Serial.print("Front");
  	moveMotors("Front-left");
  	Serial.print("Front-left");
}

//===== SD CARD INITIALIZATION =====//
void initializeSD(){
  
  // Check if the SD Card is inserted.
  if (!SD.begin()){
    Serial.println("Missing SD Card!");
    for (int x=0;x<10;x++){
        led = !led;
        digitalWrite(pinLed, led);
        delay(300);
    }
    delay(1000);
    exit(0);
  }

  // Check if folder of log data is missing.
  if (!SD.open(dataLoggerDir)){
    Serial.println("Creating Data Logger Folder!");

    if(!SD.mkdir(dataLoggerDir)){
      Serial.println("Failed Creating Folder");
      for (int x=0;x<10;x++){
        led = !led;
        digitalWrite(pinLed, led);
        delay(300);
      }
      delay(1000);
      exit(0);
    }
  }

  // Check if settings.txt file is missing in the SD Card.
  if (!SD.exists(settingsFile)){
    Serial.println("Creating Settings File!");
    
    sdFile = SD.open(settingsFile, FILE_WRITE);
    sdFile.println("frequency=" + String(frequency));
    sdFile.println("voltageIntercept=" + String(voltageIntercept));
    sdFile.println("voltageSlope=" + String(voltageSlope));
    sdFile.println("currentCorrection=" + String(currentCorrection));
    sdFile.println("magnetNumber=" + String(magnetNumber));
    sdFile.println("recordInterval=" + String(recordInterval));
    sdFile.close();
    
    delay(3000); 
  }
  sdFile.close();
}


//===== READ SETTINGS VALUE =====//
void readSettings(){
  String line;
  String value[5];
  int count = 0;
  int index = 0;
  int len = 0;
  
  sdFile = SD.open(settingsFile, FILE_READ);
  while (sdFile.available()){
    line = sdFile.readStringUntil('\n');
    index = line.indexOf('=');
    len = line.indexOf('\n');
    value[count] = line.substring(index+1, len);
    count ++;
  }
  sdFile.close();

  // Import Values from settings file.
  frequency = value[0].toInt();
  windowLength = 100/frequency; 
  voltageIntercept = value[1].toFloat();
  voltageSlope = value[2].toDouble();
  currentCorrection = value[3].toDouble();
  magnetNumber = value[4].toInt();
  recordInterval = value[5].toInt();
}


//===== LOG DATA INTO CSV =====//
void logData(bool recording){
  int countFile = 0;

  if (recording){
    if (!isNewFileCreated){
      // Check file if already exists and will create a new one.
      while (SD.exists(dataLoggerDir + dataLoggerFile + String(countFile) + ".csv")){
        countFile ++;
      }
      newFile = dataLoggerDir + dataLoggerFile + String(countFile) + ".csv";
      sdFile = SD.open(newFile, FILE_WRITE);
      sdFile.println("Time (s),Voltage (V),Current (A),Power (W),Revolution (RPM)");
      isNewFileCreated = true;
    }
    else{
      // Append data into CSV File
      if (millis() > previousRecordInterval + recordInterval){
        sdFile.println(String(timeRecording) + "," + String(voltageRMS) + "," + String(currentRMS) + "," + String(powerRMS) + "," + String(rpmAverage));
        timeRecording += recordInterval / 1000;
        previousRecordInterval = millis();
      }
    }
  }
  else{
    sdFile.close();
    isNewFileCreated = false;                                                       // Reset and will create new file in the next recording.
    timeRecording = 0;                                                              // Reset record time.
  }
}

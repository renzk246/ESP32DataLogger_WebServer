void initializeServer(){
  disableCore0WDT();
  Serial.println("starting server");
 
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  WiFi.softAP(ssid, password);

  server.on("/", SendWebsite);
  server.on("/xml", SendXML);
  server.on("/BUTTON_0", ProcessButton_0);
  server.on("/BUTTON_1", ProcessButton_1);
  server.begin();
  
  Serial.println("HTTP server started");
}


void ProcessButton_0() {
  led = !led;
  calibrating = !calibrating;
  digitalWrite(pinLed, led);
  server.send(200, "text/plain", "");
}

void ProcessButton_1() {
  recording = !recording;
  server.send(200, "text/plain", ""); //Send web page
}


void SendWebsite() {
  server.send(200, "text/html", PAGE_MAIN);
}


void SendXML() {
  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");

  // send Voltage
  sprintf(buf, "<V0>%.2f</V0>\n", voltageRMS);
  strcat(XML, buf);

  // send Current
  sprintf(buf, "<A0>%.2f</A0>\n", currentRMS);
  strcat(XML, buf);

  // send Power
  sprintf(buf, "<P0>%.2f</P0>\n", powerRMS);
  strcat(XML, buf);

  // send Revolution
  sprintf(buf, "<R0>%d</R0>\n", rpmAverage);
  strcat(XML, buf);

  // send RecordingState
  if (recording) {
    strcat(XML, "<R1>1</R1>\n");
  }
  else {
    strcat(XML, "<R1>0</R1>\n");
  }

  // send Time Recording
  sprintf(buf, "<T0>%d</T0>\n", timeRecording);
  strcat(XML, buf);


  // ESP32 LED STATUS
  if (led) {
    strcat(XML, "<LED>1</LED>\n");
  }
  else {
    strcat(XML, "<LED>0</LED>\n");
  }

  // DISPLAY MODE
  if (displayMode) {
    strcat(XML, "<D1>1</D1>\n");
  }
  else {
    strcat(XML, "<D1>0</D1>\n");
  }


  strcat(XML, "</Data>\n");
  server.send(200, "text/xml", XML);
}

/*
 the main general sections of a web page are the following and used here
  <html>
    <style>
    // dump CSS style stuff in here
    </style>
    <body>
      <header>
      // put header code for cute banners here
      </header>
      <main>
      // the buld of your web page contents
      </main>
      <footer>
      // put cute footer (c) 2021 xyz inc type thing
      </footer>
    </body>
    <script>
    // you java code between these tags
    </script>
  </html>
*/

// note R"KEYWORD( html page code )KEYWORD"; 
// again I hate strings, so char is it and this method let's us write naturally

const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" class="js-focus-visible">
<title>Web Page Update Demo</title>
  <style>
    table {
      position: relative;
      width:100%;
      border-spacing: 0px;
    }
    tr {
      border: 1px solid white;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
    }
    th {
      height: 20px;
      padding: 3px 50px;
      background-color: #343a40;
      color: #FFFFFF !important;
      }
    td {
      height: 20px;
      padding: 3px 50px;
    }
    .tabledata {
      font-size: 30px;
      position: relative;
      padding-left: 5px;
      padding-top: 5px;
      height:   25px;
      border-radius: 5px;
      color: #FFFFFF;
      line-height: 20px;
      transition: all 200ms ease-in-out;
      background-color: #00AA00;
    }
    .fanrpmslider {
      width: 30%;
      height: 55px;
      outline: none;
      height: 25px;
    }
    .bodytext {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 30px;
      text-align: left;
      font-weight: light;
      border-radius: 5px;
      display:inline;
    }
    .navbar {
      width: 100%;
      height: 50px;
      margin: 0;
      padding: 10px 0px;
      background-color: #FFF;
      color: #000000;
      border-bottom: 5px solid #293578;
    }
    .fixed-top {
      position: fixed;
      top: 0;
      right: 0;
      left: 0;
      z-index: 1030;
    }
    .navtitle {
      float: left;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 50px;
      font-weight: bold;
      line-height: 50px;
      padding-left: 20px;
    }
   .navheading {
     position: fixed;
     left: 70%;
     height: 50px;
     font-family: "Verdana", "Arial", sans-serif;
     font-size: 20px;
     font-weight: bold;
     line-height: 20px;
     padding-right: 20px;
   }
   .navdata {
      justify-content: flex-end;
      position: fixed;
      left: 80%;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      font-weight: bold;
      line-height: 20px;
      padding-right: 20px;
   }
    .category {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: bold;
      font-size: 38px;
      line-height: 50px;
      padding: 20px 10px 0px 10px;
      color: #000000;
    }
    .heading {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: normal;
      font-size: 34px;
      text-align: left;
    }
  
    .btn {
      background-color: #444444;
      border: none;
      color: white;
      position: fixed;
      left: 15%;
      width: 180px;
      padding: 20x 20px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 24px;
      margin: 3px 3px;
      cursor: pointer;
    }
    .foot {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      position: relative;
      height:   30px;
      text-align: center;   
      color: #AAAAAA;
      line-height: 20px;
    }
    .container {
      max-width: 1800px;
      margin: 0 auto;
    }
    table tr:first-child th:first-child {
      border-top-left-radius: 5px;
    }
    table tr:first-child th:last-child {
      border-top-right-radius: 5px;
    }
    table tr:last-child td:first-child {
      border-bottom-left-radius: 5px;
    }
    table tr:last-child td:last-child {
      border-bottom-right-radius: 5px;
    }
    
  </style>
  <body style="background-color: #efefef" onload="process()">
  
    <header>
      <div class="navbar fixed-top">
          <div class="container">
            <div class="navtitle">Sensor Monitor</div>
            <div class="navdata" id = "date">mm/dd/yyyy</div>
            <div class="navheading">DATE</div><br>
            <div class="navdata" id = "time">00:00:00</div>
            <div class="navheading">TIME</div>
            
          </div>
      </div>
    </header>
  
    <main class="container" style="margin-top:70px">
      <div class="category">Sensor Readings</div>
      <div style="border-radius: 10px !important;">
      <table style="width:100%">
      <colgroup>
        <col span="1" style="background-color:rgb(230,230,230); width: 50%; color:#000000 ;">
        <col span="1" style="background-color:rgb(200,200,200); width: 25%; color:#000000 ;">
        <col span="1" style="background-color:rgb(180,180,180); width: 25%; color:#000000 ;">
      </colgroup>
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <tr>
        <th colspan="1"><div class="heading">Variable</div></th>
        <th colspan="1"><div class="heading">Values</div></th>
        <th colspan="1"><div class="heading">Mode</div></th>
      </tr>
      <tr>
        <td><div class="bodytext">Voltage (V)</div></td>
        <td><div class="tabledata" id = "v0"></div></td>
        <td><div class="tabledata" id = "v1"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Current (A)</div></td>
        <td><div class="tabledata" id = "a0"></div></td>
        <td><div class="tabledata" id = "a1"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Power (P)</div></td>
        <td><div class="tabledata" id = "p0"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Revolution (rpm)</div></td>
        <td><div class="tabledata" id = "r0"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Recording</div></td>
        <td><div class="tabledata" id = "r1"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Time (s)</div></td>
        <td><div class="tabledata" id = "t0"></div></td>
      </tr>
      </table>
    </div>
    <br>
    <div class="category">Sensor Controls</div>
    <br>
    <div class="bodytext">Mode</div>
    <button type="button" class = "btn" id = "btn0" onclick="ButtonPress0()">Toggle</button>
    </div>
    <br>
    <div class="bodytext">Record</div>
    <button type="button" class = "btn" id = "btn1" onclick="ButtonPress1()">Toggle</button>
    </div>
    <br>
    <br>
  </main>
  <footer div class="foot" id = "temp" >ESP32 Web Page and Data</div></footer>
  </body>

  
  <script type = "text/javascript">
    var xmlHttp=createXmlHttpObject();

    function createXmlHttpObject(){
      if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
      }
      else{
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      return xmlHttp;
    }

    function ButtonPress0() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      xhttp.open("PUT", "BUTTON_0", false);
      xhttp.send();
    }

    function ButtonPress1() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_1", false);
      xhttp.send(); 
    }
    
    function response(){
      var message;
      var barwidth;
      var currentsensor;
      var xmlResponse;
      var xmldoc;
      var dt = new Date();
      var color = "#e8e8e8";
     
      // get the xml stream
      xmlResponse=xmlHttp.responseXML;
  
      // get host date and time
      document.getElementById("time").innerHTML = dt.toLocaleTimeString();
      document.getElementById("date").innerHTML = dt.toLocaleDateString();
  

      // VOLTAGE
      xmldoc = xmlResponse.getElementsByTagName("V0");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 250){
        color = "#aa0000";
      }
      else if (message > 150){
        color = "#c203fc";
      }
      else {
        color = "#0000aa";
      }
      document.getElementById("v0").innerHTML=message;
      width = message / 2.6;
      document.getElementById("v0").style.width=(width+"%");
      document.getElementById("v0").style.backgroundColor=color;


      // CURRENT
      xmldoc = xmlResponse.getElementsByTagName("A0");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 3){
        color = "#aa0000";
      }
      else if (message > 1){
        color = "#c203fc";
      }
      else {
        color = "#0000aa";
      }
      document.getElementById("a0").innerHTML=message;
      width = message / 0.05;
      document.getElementById("a0").style.width=(width+"%");
      document.getElementById("a0").style.backgroundColor=color;


      // POWER
      xmldoc = xmlResponse.getElementsByTagName("P0");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 500){
        color = "#aa0000";
      }
      else if (message > 250){
        color = "#c203fc";
      }
      else {
        color = "#0000aa";
      }
      document.getElementById("p0").innerHTML=message;
      width = message / 5;
      document.getElementById("p0").style.width=(width+"%");
      document.getElementById("p0").style.backgroundColor=color;


      // REVOLUTION
      xmldoc = xmlResponse.getElementsByTagName("R0");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 6000){
        color = "#aa0000";
      }
      else if (message > 2000){
        color = "#c203fc";
      }
      else {
        color = "#0000aa";
      }
      document.getElementById("r0").innerHTML=message;
      width = message / 60;
      document.getElementById("r0").style.width=(width+"%");
      document.getElementById("r0").style.backgroundColor=color;


      // RECORDING
      xmldoc = xmlResponse.getElementsByTagName("R1");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("r1").style.backgroundColor="rgb(200,200,200)";
      // update the text in the table
      if (message == 0){
        document.getElementById("r1").innerHTML="OFF";
        document.getElementById("btn1").innerHTML="OFF";
        document.getElementById("r1").style.color="#0000AA"; 
      }
      else {
        document.getElementById("r1").innerHTML="ON";
        document.getElementById("btn1").innerHTML="ON";
        document.getElementById("r1").style.color="#00AA00";
      }
      

      // TIME RECORDING
      xmldoc = xmlResponse.getElementsByTagName("T0");
      message = xmldoc[0].firstChild.nodeValue;
      color = "#c8c8c8";
      document.getElementById("t0").innerHTML=message;
      document.getElementById("t0").style.backgroundColor=color;


      // ESP32 LED STATUS
      xmldoc = xmlResponse.getElementsByTagName("LED");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v1").style.backgroundColor="rgb(180,180,180)";
      document.getElementById("a1").style.backgroundColor="rgb(180,180,180)";
      if (message == 0){
        document.getElementById("v1").innerHTML="Calibrated";
        document.getElementById("a1").innerHTML="Calibrated";
        document.getElementById("v1").style.color="#00aa00";
        document.getElementById("a1").style.color="#00aa00";
        document.getElementById("btn0").innerHTML="Calibrated";
      }
      else{
        document.getElementById("v1").innerHTML="Uncalibrated";
        document.getElementById("a1").innerHTML="Uncalibrated";
        document.getElementById("v1").style.color="#aa0000";
        document.getElementById("a1").style.color="#aa0000";
        document.getElementById("btn0").innerHTML="Uncalibrated";
      }
     }



    function process(){
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4) {
        xmlHttp.open("PUT","xml",true);
        xmlHttp.onreadystatechange=response;
        xmlHttp.send(null);
      }       
        // you may have to play with this value, big pages need more porcessing time, and hence
        // a longer timeout
        setTimeout("process()",100);
    }
  </script>
</html>
)=====";

<h1 align="center"> 
Car Theft Detection and Control System
</h1>
<div align="justify">
  
<h3>
  Introduction
</h3>
The proposed project focuses on developing an Car Theft Detection and Control System leveraging IoT technologies. The system integrates a GPS-enabled ESP32 microcontroller, ThingSpeak cloud platform, and a custom-built mobile application using MIT App Inventor to provide real-time location tracking and remote control functionalities. 
<br>
<br>
The project employs a GPS module to continuously monitor the car's geographical 
coordinates (latitude and longitude). These coordinates are uploaded to the 
ThingSpeak server at regular intervals. The mobile app fetches this data and 
displays it to the user in a simple, intuitive interface, including an embedded Google 
Map for visualizing the car's location. Additionally, the app integrates reverse 
geocoding using the LocationIQ API to translate coordinates into a human-readable 
address.

The system is equipped with safety features such as remote engine start and stop 
capabilities, enabling the user to disable the vehicle remotely in the event of theft. 
Communication between the app and the car is established using HTTP requests to 
the ESP32, ensuring seamless and secure control commands.

<h3>
  COMPONENTS
</h3>
<p align="center">
  <img width="500" height="400" alt="image" src="https://github.com/user-attachments/assets/4d78b662-3e29-452c-89b0-f7286861463a" />
</p>

<h3>
  FLOW CHART
</h3>
<p align="center">
  <img width="550" height="600" alt="image" src="https://github.com/user-attachments/assets/0983b0e0-49c0-41f9-85e4-c57ecee1b355" />

</p>
<h3>
  BLOCK DIAGRAM
</h3>
<p align="center">
<img width="635" height="327" alt="image" src="https://github.com/user-attachments/assets/732e9d1b-23a7-419b-b4b6-e69dd046e289" />
</p>

The block diagram illustrates the interaction between various hardware 
components: 

• ESP32 is the central controller; sends the location data to the mobile 
app through ThingSpeak and receives commands (start/stop motor). 

• GPS Module provides the location data to ESP32. 

• Relay Module controls the power to the motor, which is interfaced with 
the L293D Motor Driver. 

•  The mobile app communicates with ESP32/ ThingSpeak cloud 
platform over Wi-Fi.

<h3>CONNECTIONS:</h3>
<ins>ESP32 to GPS Module:</ins>
<ul style="list-style-type:circle">
 <li>GPS RX → ESP32 TX2 (Pin 17) </li>
 <li>GPS TX → ESP32 RX2 (Pin 16)</li>  
</ul>
<ins>ESP32 to Relay:</ins>

<ul style="list-style-type:circle">
  <li>Relay IN → ESP32 Pin 21 </li> 
</ul>

<ins>ESP32 to L293D:<ins>

<ul style="list-style-type:circle">
  <li>IN1 → ESP32 Pin 18 </li> 
  <li>IN2 → ESP32 Pin 19 </li>
</ul>

<ins>Motors to L293D:</ins>

<ul style="list-style-type:circle">
  <li> Left Motor Wires → L293D OUT1</li>  
  <li>Right Motor Wires → L293D OUT2</li> 
</ul>

<ins>Power Supply:</ins>

<ul style="list-style-type:circle">
  <li>L293D Vin (Motor Voltage) → Battery Positive (e.g., 12V)</li>  
  <li> L293D Vcc (Logic Voltage) → 5V </li>
  <li>L293D GND → Battery Ground and ESP32 Ground</li> 
  <li>Relay Vcc → 5V</li> 
  <li> Relay GND → Battery Ground and ESP32 Ground</li> 
  <li> GPS Vcc → 3.3V</li> 
  <li> GPS GND → Battery Ground and ESP32 Ground</li> 
  <li>ESP32 Vcc → 3.3V </li>
  <li>ESP32 GND → Battery Ground and ESP32 Ground</li>
</ul>
<h3>CIRCUIT DIAGRAM</h3>
<p align="center">
  <img width="650" height="400" alt="image" src="https://github.com/user-attachments/assets/f6bd6a27-0e7e-4096-a1e8-dc571725cce1" />


</p>
</div>


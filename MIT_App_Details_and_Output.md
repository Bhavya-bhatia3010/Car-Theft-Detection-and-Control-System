<h1 align="center">MIT APP INVENTOR DESIGN AND CODE</h1>
<p align="justify">
	
<h3>App Layout</h3>

Buttons:
<p align="center">
	<ul>
		<li>Start: Sends the "START" command to the ESP32 web server.</li>
		<li>Stop: Sends the "STOP" command to the ESP32 web server.</li>
		<li>Update Location: Fetches location from ThingSpeak.</li>
		<li>Show Location: Displays the location on Google Maps using a WebViewer.</li>
		<li>Refresh: Resets the app to its initial state.</li>
	</ul>

</p>

Web Components:
<ul>
	<li>Web1: Fetches GPS data from ThingSpeak.</li>
	<li>Web2: Sends "START" and "STOP" commands to the ESP32.</li>
	
</ul>

Designer View
<p align="center">
  <img width="300" height="400" alt="image" src="App_Images/Fig_1_MIN_Inventor_Designer_Window.png" />
</p>
<p align="center">
Fig 1: MIN Inventor Designer Window
</p>

<h3>App Blocks Explanation</h3>

Start Button:

Sets Web2 URL to /start and triggers the ESP32 server to start the car.
<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_2_MIN_Inventor_Start_Button_Block.png" />
</p>

Stop Button:

Sets Web2 URL to /stop and triggers the ESP32 server to stop the car.

<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_3_MIN_ Inventor_Stop_Button_Block.png" />
</p>

Update Location Button:

Fetches latitude and longitude from ThingSpeak using Web1.
<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_4_Update_location_Button_Block.png" />
</p>

View Location on Google map Button:

Loads Google Maps URL in WebViewer with the latest coordinates.

<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_5_Location_on_Google_map_Button_Block.png" />
</p>

Web1 Code: Fetches GPS data from ThingSpeak.
<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_6_MIN_Inventor_Web1_Block.png" />
</p>

Web2 Code: Sends "START" and "STOP" commands to the ESP32

<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_7_MIN_Inventor_Web2 _Block.png" />
</p>

Reverse Button Commands

<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_8_MIN_Inventor_Web2_Block.png" />
</p>

<h2 align="center">OUTPUT AND RESULT</h2>

<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_9_ThingSpeak_Output.png" />
</p>

<p align="center">
Fig 9- ThingSpeak Output
</p>

<p align="center">
  <img width="400" height="500" alt="image" src="App_Images/Fig_Output.png" />
</p>












</p>

# permaculture
Python projet arduino - permaculture

Ajoutez dans les pref arduino : http://arduino.esp8266.com/stable/package_esp8266com_index.json

Ajoutez la carte esp8266 dans le gestionnaire de carte

librairie websocket : https://github.com/morrissinger/ESP8266-Websocket

_________________

Inside the downloaded .zip file should be a folder called ESP8266-Websocket-master. Extract it and rename it to ESP8266-Websocket.

Now we need to manually place our extracted and renamed folder in the same directory of the other Arduino libraries. Usually, the libraries are located on a folder called Arduino on the Documents of the Windows user. For example, in my case, the libraries are located at C:\Users\MyUsername\Documents\Arduino\libraries.

After finding your Arduino libraries folder, simply paste the ESP8266-Websocket folder there.

Before we proceed to the actual coding, we will need to change the name of some functions of the files inside the ESP8266-Websocket folder. If these changes are not performed, when trying to compile the code for the ESP32, we will receive an error related to conflicts caused by the names of those functions.

So, in order to avoid that error, we need to follow the suggestion given in this ESP32 forum thread. As indicated, we need to open the MD5.c and MD5.h files from the ESP8266-Websocket folder and rename the following functions:

MD5Init to MD5InitXXX
MD5Update to MD5UpdateXXX
MD5Final to MD5FinalXXX
Note that the XXX appended at the end could be something else, as long as we did not use the original names, which are conflicting with other definitions. Nonetheless, we need to use the same new names in both the .c and .h files.
____________________

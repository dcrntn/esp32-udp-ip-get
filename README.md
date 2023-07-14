# Get IP on local network
This is a sample program, that can be run on an ESP32 to retrieve the devices' IP address on the local network. With this approach dynamic IP can be used, thus reserving IP in the router isn't required.

## Note
This program is a functionality test - or can be called a "PoC".

Releated to the: [Microcontroller manager software](https://github.com/dcrntn/mcu-manager)

## Installation
1. Clone or download this repo.
2. Set the WiFi credentials. 
3. Give a uuid, the uuid should be unique to all ESP on the network.
4. Build with PIO.
5. Flash to a ESP32.

## Usage
1. Send a UDP broadcast packet with the "iue" message to the 43770 port.
2. Listen for responses. The response should look like ("ESP32_\<esp's uuid\>")  
3. Get the IP from the response packet.
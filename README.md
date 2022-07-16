<img src="https://img.shields.io/badge/-ATtiny%20Project-blue.svg?&amp;style=flat-square&amp" style="max-width: 100%;"> <img src="https://img.shields.io/badge/-Arduino%20IDE-%2300979D.svg?&amp;style=flat-square&amp;logo=arduino&amp;logoColor=white" style="max-width: 100%;">


# General info
[![](https://yt-embed.live/embed?v=qwDi0INFS3Y)](http://www.youtube.com/watch?v=qwDi0INFS3Y "Angry Cat Keychain")

## Code
- In the RGB LED, 3 small LEDs are combined in the colours red, green and blue. 
- Therefore we have to declare the pins for each colour of the LED.
- We also declare the pin for the push button and some variables for debouncing the push button
- The function colourToLed sets the brightness value of each small LED in the RGB LED.
- In the loop, we debounce the push button and count the detected button presses so that we can perform different actions each time the button is pressed. 

## Hardware
- For this project we use an ATtiny25 and two RGB LEDs with a common cathode.
- We added three 100 Ω resistors (one for each colour) and a 10k Ω resistor for the push button.
- The keychain is powered by a button cell battery.

![Verdrahtung](https://github.com/pixelEDI/attiny_cat_keychain/blob/main/RGBATtiny_wiring.jpg)


## 3D Case
Get the Case:   [Thingiverse](https://www.thingiverse.com/thing:5433790)

You like it? Then I would be very happy if you treat me to a coffee on [ko-fi.com/pixeledi](https://www.ko-fi.com/pixeledi)

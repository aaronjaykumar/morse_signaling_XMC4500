# morse_signaling_XMC4500
Uses the LEDs and buttons on XMC4500 to transmit a message in the form of morse code.

In continuous_transmission, a given string is transmitted continuously in Morse code via LED1. The ITU standard M.1677-1 for Morse code was used. The length of a dot is approx 100 ms.

In button_controlled_transmission, the given string is transmitted via LED1 only when Button 1 is pushed. If Button 2 is pressed, the time interval (in ms) between the last two Button 1 transmissions is transmitted via LED1.

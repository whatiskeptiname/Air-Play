# Air-Play

An Arduino based instrument to play music by waving hand in the air. This is a simple demonestration of contactless musical instrument.

## Components Used

1. Arduino Uno
2. Ultrasonic Sensor HC-SR04 *5
3. Piezo buzzer
4. LiPo battery

## Working

Five ultrasonic sensors (array) are used to detect the player hand. Base frequency is assigned to each sensors. The frequency to deduce from the base frequency is determined from the proximity of player hand from each sensor. As the proximity increases the total frequency decreases. This is applied for each sensor which have different base frequency so each sensor will trigger a different frequency according to the senor's position and the proximity of the player hand.

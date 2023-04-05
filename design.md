# Design Document

## Smart Device Theme

> For my automated system (smart device), I have decided to create a 'smart' video game, akin to Five Nights at Freddy’s. This smart device acts a remote control game in which the human player utilises the inputs (buttons and remotes) and indicators (buzzers and lights) of the Arduino electronic board alongside the possible use of a remote control to change certain aspects of the game in order to win.


## Behaviours

1. When the Sonar / Distance Sensor detects an edge or wall 10 to 15 centimetres from the electric board, the Buzzer can activate as an alarm.
2. When the Line Sensor detects a specific barcode or type of line, the game’s monitor will change scenes.
3. When the button is pressed, the game monitor’s interface will be interacted with. The player can access the game’s UI through the use of the button.
4. When the Infrared Remote Control is used:
> The arrow keys on a remote can interact with the doors in-game per press.
> The menu buttons (for example, ‘home’) will activate the game’s UI, for the button’s use.
5. When the SD Card is saved as a file on the computer (sd card specific files), the Arduino mega can then (with sd card connected) read the data of the sd card file to the board for saved data to initialise.
6. When the Servo motor’s state is changed, and the game developer portion of the monitor is initialised, the motor can change the overall speed of executing the program.
7. When the buzzer is called upon by:
> the Sonar / Distance Sensor alarm (in the instance of a hazard), it will buzz (initialise).
> a specific danger element ‘in-game’, it will buzz (alert the player of a threat) and activate the red traffic light.
8. When the Potentiometer’s state is changed, the master sound of the game’s monitor will change accordingly.
9. When the in-game threats are closer to the player character, the traffic lights will change colour accordingly (red being high danger, yellow is medium danger, and green is low danger).
10. When the game program is active, the DC motor activates a slowly moving progress system, indicating the length of the game’s level, a clock-like system loosely attached to the electronic board.

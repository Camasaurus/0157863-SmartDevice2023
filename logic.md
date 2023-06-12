
# Logic Subsystems of my main assignment.

> Behaviours as short sentences, with each behaviour represented in the following subsystems.


## Sonar Logic Subsystem
    When the Sonar / Distance Sensor detects an edge or wall 10 to 15 centimetres from the electric board, the Buzzer can activate as an alarm.

```mermaid
flowchart LR
    Start([Sonar / distance sensor])
    getEnvironmentStatus[Get current environmental placement, in search of any obstacles]
    checkEnvironment{Is the electronic board placement suitable?}
    environmentAlert[/Display alert message/]
    finish([End])
    
    subgraph Sonar / Distance Behaviour
    Start-->getEnvironmentStatus-->checkEnvironment
    checkEnvironment-->|Yes|finish
    checkEnvironment-->|No|environmentAlert
    environmentAlert-->finish
    end

```
## Line Sensor Subsystem
    When the Line Sensor detects a specific barcode or type of line, the game’s monitor will change scenes.

```mermaid
flowchart LR
    Start([Line Sensor])
    lineVariable[User brings out their line code pattern card]
    examineLineCode[Examine the Line Pattern on the card]
    lineCodeCheck{Is the line pattern code correct?}
    lineDebugPrivelege[/Give the user access to debug console and debug properties/]
    finish([End])

    subgraph Line Sensor Behaviour
    Start-->lineVariable-->examineLineCode-->lineCodeCheck
    lineCodeCheck-->|Yes|lineDebugPrivelege
    lineCodeCheck-->|No|finish
    lineDebugPrivelege-->finish
    end
```

## Button Subsystem
    When the button is pressed, the game monitor’s interface will be interacted with. The player can access the game’s UI through the use of the button.

```mermaid
flowchart LR
    start([Button Device])
    buttonCheck{Has the button been pressed?}
    interfaceChangeResult[/Change the button on the program's 'focus'/]
    finish([End])

    subgraph Button Behaviour
    start-->buttonCheck
    buttonCheck-->|Yes|interfaceChangeResult
    buttonCheck-->|No|finish
    interfaceChangeResult-->finish
    end
```

## Infrared Remote Subsystem
    When the Infrared Remote Control is used:
        The arrow keys on a remote can interact with the doors in-game per press.
        The menu buttons (for example, ‘home’) will activate the game’s UI, for the button’s use.

```mermaid
flowchart LR
    start([Infrared Remote Sensor])
    userInput[User interacts with a button on the remote]
    determineButton{What button has been pressed?}
    buttonInputOne[/Doors in-game/]
    buttonInputTwo[/User Interface/]
    buttonInputThree[/Options/]
    finish([End])

    subgraph Infrared Remote Behaviour
    start-->userInput-->determineButton
    determineButton-->|Number Buttons|buttonInputOne
    determineButton-->|Arrow Buttons|buttonInputTwo
    determineButton-->|Home Button|buttonInputThree
    buttonInputOne-->finish
    buttonInputTwo-->finish
    buttonInputThree--->finish
    end
```

## SD Card Subsystem
    When the SD Card is saved as a file on the computer (sd card specific files), the Arduino mega can then (with sd card connected) read the data of the sd card file to the board for saved data to initialise.

``` mermaid
flowchart LR
    start([SD Card Device])
    cardInitialisation{Has the SD Card Initialised?}
    initialisedTrue[/Log all necessary events, and print them to Serial Monitor./]
    initialisedFalse[/Print the error to Serial Monitor./]
    finish([End])

    subgraph SD Card Behaviour
    start-->cardInitialisation
    cardInitialisation-->|Yes|initialisedTrue
    cardInitialisation-->|No|initialisedFalse
    initialisedTrue-->finish
    initialisedFalse-->finish
    end
```
## Servo Motor Subsystem
    When the Servo Motor’s state is changed, and the game developer portion of the monitor is initialised, the motor can change the overall speed of executing the program.

```mermaid
flowchart LR
    start([Servo Motor Device])
    determineStatus{Has the Potentiometer changed the Servo's status?}
    developerCheck{Has the user been given access to developer properties from the Line Sensor?}
    newStatus[/Change the speed at which the program runs according to the status of the Servo Motor/]
    finish([End])

    subgraph Servo Motor Behaviour
    start-->determineStatus
    determineStatus-->|Yes|developerCheck
    determineStatus-->|No|finish
    developerCheck-->|Yes|newStatus
    developerCheck-->|No|finish
    newStatus-->finish
    end
```

## Buzzer Subsystem
    When the buzzer is called upon by:
        The Sonar / Distance Sensor alarm (in the instance of a hazard), it will buzz (initialise).
        A specific danger element ‘in-game’, it will buzz (alert the player of a threat) and activate the red traffic light.
    
```mermaid
flowchart LR
    start([Buzzer Device])
    sonarDeviceCall{Has the Sonar Sensor detected an environmental hazard?}
    programDangerCall{Is there a dangerous element close to the player in-game?}
    buzzerResult[/Sound the Alarm./]
    finish([End])

    subgraph Buzzer Sensor
    start-->sonarDeviceCall
    start-->programDangerCall
    sonarDeviceCall-->|Yes|buzzerResult
    sonarDeviceCall-->|No|finish
    programDangerCall-->|No|finish
    programDangerCall-->|Yes|buzzerResult
    buzzerResult-->finish
    end
```

## Potentiometer Subsystem
    When the Potentiometer’s state is changed, the master sound of the game’s monitor will change accordingly.

```mermaid
flowchart LR
    start([Potentiometer Device])
    determineStatus{Has the device changed its status?}
    newStatus[/Change the volume of the program's sound from changing the volume of the computer./]
    exportPotentiometerForServo[Export the Potentiometer Value for the Servo Function]
    finish([End])

    subgraph Servo Motor Behaviour
    start-->determineStatus
    determineStatus-->|Yes|newStatus
    newStatus-->exportPotentiometerForServo
    determineStatus-->|No|finish
    exportPotentiometerForServo-->finish
    end
```

## Traffic Lights Subsystem
    When the in-game threats are closer to the player character, the traffic lights will change colour accordingly (red being high danger, yellow is medium danger, and green is low danger).

```mermaid
flowchart LR
    start([Traffic Lights System])
    dangerCheck[Determine the danger level in-game.]
    dangerEvaluation{What is danger level in-game?}
    highDanger[/Turn on the Red LED./]
    mediumDanger[/Turn on the Yellow LED./]
    lowDanger[/Turn on the Green LED./]
    finish([End])

    subgraph Traffic Lights Behaviour
    start-->dangerCheck-->dangerEvaluation
    dangerEvaluation-->|High|highDanger
    dangerEvaluation-->|Medium|mediumDanger
    dangerEvaluation-->|Low|lowDanger
    highDanger-->finish
    mediumDanger-->finish
    lowDanger-->finish
    end
```

## DC Motor Subsystem
    When the game program is active, the DC motor activates a slowly moving progress system, indicating the length of the game’s level, a clock-like system loosely attached to the electronic board.


```mermaid
flowchart LR
    start([DC Motor Device])
    programStatus{Has the program's game begun?}
    motorProgression[/As the game progresses, the DC motor will move to show the amount of progression in the game's time./]
    finish([End])

    subgraph DC Motor Behaviour
    start-->programStatus
    programStatus-->|Yes|motorProgression
    programStatus-->|No|finish
    motorProgression-->finish
    end
```
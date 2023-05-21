
# Logic Subsystems of my main assignment.

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Sonar Logic Subsystem

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

## Servo Motor Subsystem
```mermaid
flowchart LR
    start([Servo Motor Device])
    determineStatus{Has the device changed its status?}
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
    programDangerCall-->|Yes|buzzerResult
    programDangerCall-->|No|finish
    buzzerResult-->finish
    end
```

## Potentiometer Subsystem
```mermaid
flowchart LR
    start([Potentiometer Device])
    determineStatus{Has the device changed its status?}
    newStatus[/Change the volume of the program's sound from changing the volume of the computer./]
    finish([End])

    subgraph Servo Motor Behaviour
    start-->determineStatus
    determineStatus-->|Yes|newStatus
    determineStatus-->|No|finish
    newStatus-->finish
    end
```

## Traffic Lights Subsystem
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

# Programming Logic

## Example Subsystem from Programming Logic Exercise (3/05/23)

```mermaid
flowchart RL
    start([Intruder Sonar System - Start])
    Sonar[Activate Sonar]
    checkPeople{Is a person too close to the house?}
    intruderAlert[/Activate the alarm/]
    finish([End])

    Start2([Garage Button - Start])
    buttonPressed{Has the garage button been pressed?}
    activateDoor[/Activate the Servo to open the door/]
    activateLight[/Activate the red LED/]
    Pause[After starting the two devices, pause for 5 seconds]
    deactivateDoor[/Turn off the Servo to close the door/]
    deactivateLight[/Turn off the red LED/]
    finish2([End])

    Start3([DC Motor Speed - Start])
    potentiometerStatus{Has the potentiometer controller been adjusted?}
    motorAdjust[/Adjust to the DC Motor speed according to the adjustment of the potentiometer/]
    finish3([End])

    subgraph Behaviour 3
    Start3-->potentiometerStatus
    potentiometerStatus-->|Yes|motorAdjust
    potentiometerStatus-->|No|finish3
    motorAdjust-->finish3
    end

    subgraph Behaviour 2
    Start2-->buttonPressed
    buttonPressed-->|Yes|activateDoor
    buttonPressed-->|Yes|activateLight
    activateDoor-->Pause
    activateLight-->Pause
    Pause-->deactivateDoor
    Pause-->deactivateLight
    deactivateDoor-->finish2
    deactivateLight-->finish2
    buttonPressed-->|No|finish2
    end

    subgraph Behaviour 1
    start-->Sonar-->checkPeople
    checkPeople-->|Yes|intruderAlert
    checkPeople-->|No|finish
    intruderAlert-->finish
    end
```

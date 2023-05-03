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

# Logic Subsystems of my main assignment.

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Sonar Logic Subsystem

```mermaid
flowchart RL
    Start([Sonar / distance sensor])
    getEnvironmentStatus[Get current environmental placement]
    checkEnvironment{Is the electronic board placement suitable?}
    environmentAlert[/Display alert message/]
    finish([End])
    
    Start-->getEnvironmentStatus-->checkEnvironment
    checkEnvironment-->|Yes|finish
    checkEnvironment-->|No|environmentAlert
    environmentAlert-->finish

```
## Line Sensor Subsystem

```mermaid
flowchart LR
    Start([Line Sensor])

```
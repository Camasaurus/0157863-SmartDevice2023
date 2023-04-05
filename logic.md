# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## Sonar Logic Subsystem

```mermaid
flowchart TD
    Start([Sonar / distance sensor])
    getEnvironmentStatus(Get current environmental placement)
    checkEnvironment{Is the electronic board placement suitable?}
    environmentAlert(Display alert message)
    finish(End)
    
    Start-->getEnvironmentStatus-->checkEnvironment
    checkEnvironment-->|Yes|finish
    checkEnvironment-->|No|environmentAlert
    environmentAlert-->finish

```
## Line Sensor Subsystem

```mermaid
flowchart TD
    Start([Line Sensor])

```
###### This is a refactored version of [MightyMaya/CPU-Scheduler](https://github.com/MightyMaya/CPU-Scheduler)

# CPU Scheduler:
<p align="center"> <img src=https://github.com/MariamH78/CPU-Scheduler/assets/99722575/e87f2bad-2694-4593-b2ff-db0eb930e91e width="500"> </p>

#### A Qt application that mimics how a CPU would schedule waiting processes in 5 different algorithms:
* First come first serve (FCFS)
* Round robin
* Preemptive shortest job first (SJW)
* Non-preemptive shortest job first (SJW)
* Preemptive priority scheduling
* Non-preemptive priority scheduling

#### The application also supports:
* Offline/not-live scheduling
* Online/live scheduling

#### And for each process added by the user, the following parameters are modifiable (depending on the chosen scheduler):
* Burst time
* Quantum time
* Arrival time
* Priority
---
Below is a running example of live scheduling using the preemptive priority scheduler, and note that `time` throughout the app is measured in `seconds`, the GIF is sped up:
<p align="center"><img src=https://github.com/MariamH78/CPU-Scheduler/assets/99722575/9d503a58-1cbd-4d4f-9ddc-c02a7cf21aa5 width="600"></p>

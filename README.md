# Assistive-Turbulence-Detection-and-Flight-Control-Module
Turbulence poses significant challenges to the safety and efficiency of drone operations, particularly for delivery drones. Unanticipated turbulent conditions can lead to hardware malfunctions, destabilization, and increased power consumption, jeopardizing mission success and safety.

The Drone Turbulence Detector and Monitoring System is designed to improve drone stability by detecting turbulence in real-time and providing categorized output to assist in monitoring flight patterns and maneuverability. The system consists of an onboard STEVAL-MKBOXPRO (SensorTile.Box PRO) module mounted on an FPV Drone that logs motion data and classifies flight conditions based on a trained model.

<img src="Project_images/SensorTile.Box PRO Mounted on FPV Drone.jpg" height = "500px" width= "694px" alt="SensorTile.Box PRO Mounted on FPV Drone">

Real-Time Sensor Data Acquisition: The system continuously records data from an onboard STEVAL-MKBOXPRO module, which includes an accelerometer and gyroscope.

MLC Configuration and Classification: The collected data is used to generate a dataset, which is then processed using the ST AIoT Craft tool to generate a Machine Learning Core (MLC) configuration. This configuration enables the board to classify different flight conditions, distinguishing between turbulence, stable flight, and various tilt states.

Validation and Output Display: The MLC configuration is flashed onto the sensor module, and the classified output is displayed via Bluetooth on the ST AIoT Craft mobile application for real-time validation.

## Block Diagram
<img src="Project_images/Block_Diagram.png" alt="Block Diagram">



## Training Stats and workflow
<img src="Project_images/training stats and accuracy.png" alt="training stats with 99.43% accuracy">


# How to Reproduce the Demo
## System Requirements
STEVAL-MKBOXPRO: Equipped with the included MicroSD card.

Android Device: Installed with the latest version of the ST AIoT Craft mobile application supporting datalog2_3.0 firmware.

MicroSD Card Reader: For data transfer purposes.

Drone/UAV: For testing and implementation


## Steps to Run the System
Data Acquisition: The sensor module is connected to the mobile app and datalogging is done while ensuring that both accelerometer and gyroscope data are recorded at a 240Hz Output Data Rate, to collect real-time flight data during various operational conditions(no_power, grounded, left, right, forward, backward tilts, air_stable and air_turbulence).

Data Upload: Collected data is transferred to the ST AIoT Craft web dashboard through SD card, where a new dataset is created, and .CSV files or datalog folders are uploaded.

Model Creation: Within the ST AIoT Craft platform, a new project and corresponding model are created. The dataset is assigned to the model, and the MLC inference rate is kept the same as the ODR of the sensors. 

Feature Extraction and Training: The default feature extraction mode is selected, and then the run MLC configuration option is clicked to train the model.

Deployment: The trained model is flashed onto the STEVAL-MKBOXPRO through the mobile app itself after connecting through bluetooth.

Validation: Using the ST AIoT Craft mobile application, the model is validated in real-time via Bluetooth connectivity.

### In-Flight Testing:
The board, mounted on the drone, classifies flight states during actual flight scenarios such as:-

No_Power: The system is off or not receiving sufficient power to operate.

Armed: The drone is stationary on the ground with its blades powered on, with no active flight movement.

Motion_Turbulence: The drone is experiencing unstable airflow, leading to erratic motion and increased power consumption.

Motion_Stable: The drone is flying smoothly without significant disturbances.

Pitch_Forward: The drone is leaning forward, possibly due to acceleration or external forces.

Pitch_Backward: The drone is tilting backward, which may indicate deceleration or wind resistance.

Roll_Left: The drone is leaning to the left, which could be caused by maneuvering or external factors.

Roll_Right: The drone is leaning to the right, similar to left tilt but in the opposite direction.

## Training Results
<img src="Project_images/training results.png" alt="Training results">


# xNucleo-IKS4A1_LPS22DF_mbedOS_000-GetTemperature_GetPressure

## Code Description

This code establishes communication with an LPS22DF pressure and temperature sensor using the "mbed" and "plt_iks4a1.h" libraries. Additionally, it communicates with an external device via serial communication.

### Including Libraries
```cpp
#include "mbed.h"
#include "plt_iks4a1.h"
```

The `mbed.h` library provides essential functionalities for programming on ARM mbed platforms, while `plt_iks4a1.h` likely contains definitions and functions specific to the LPS22DF sensor.

### Initializing Components
```cpp
LPS22DF sensor(I2C_SDA, I2C_SCL); 
Serial pc(USBTX, USBRX);
DigitalOut led(LED1);
```

This code initializes an instance of the `LPS22DF` class named `sensor` to communicate with the LPS22DF sensor using the I2C protocol. It also initializes a `Serial` object named `pc` for serial communication, and a `DigitalOut` object named `led` to control an LED.

### Declaring Variables
```cpp
float pressure, temperature;
```

Two float variables, `pressure` and `temperature`, are declared to store the pressure and temperature readings obtained from the sensor.

### `main()` Function
```cpp
int main()
{
    pc.baud(115200);
    sensor.begin();
    sensor.Enable();
```

In the `main()` function, the serial communication baud rate is set to 115200 baud using the `baud()` method of the `pc` object. The `begin()` method is called to initialize the sensor, and `Enable()` is used to enable it.

### Reading Data and Controlling the LED
```cpp
    while (true) {
        sensor.GetPressure(&pressure);
        sensor.GetTemperature(&temperature);

        pc.printf("Pressure[hPa]: %f , Temperature[C]: %f\r\n", pressure, temperature);
  
        led =!led;
        ThisThread::sleep_for(2000);
    }
```

Within an infinite loop, the code continuously reads pressure and temperature values from the sensor using the `GetPressure()` and `GetTemperature()` methods. These values are then printed to the serial port using `pc.printf()`. Additionally, the LED state is toggled using `led = !led` to indicate program execution, and a 2000 milliseconds delay is inserted using `ThisThread::sleep_for(2000)` before repeating the loop.

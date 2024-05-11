#include "mbed.h"
#include "plt_iks4a1.h"


LPS22DF sensor(I2C_SDA, I2C_SCL); 

Serial pc(USBTX, USBRX);
DigitalOut led(LED1);

float pressure, temperature;


// main() runs in its own thread in the OS
int main()
{
    
    pc.baud(115200);
    sensor.begin();
    sensor.Enable();
    

    while (true) {
        sensor.GetPressure(&pressure);
        sensor.GetTemperature(&temperature);

        pc.printf("Pressure[hPa]: %f , Temperature[C]: %f\r\n", pressure, temperature);
  
        led =!led;
        ThisThread::sleep_for(2000);
    }
}



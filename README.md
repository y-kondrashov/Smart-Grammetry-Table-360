# Smart Grammetry Table 360
<img width="1181" height="870" alt="image" src="https://github.com/user-attachments/assets/6189b026-206e-44cf-9377-d80b40db4ece" />
<img width="1025" height="810" alt="image" src="https://github.com/user-attachments/assets/2f57ac2a-245f-4fbf-adad-392dbd7df252" />

Проєкт тестує керування кроковим двигуном через драйвер **MKS SERVO42C** за допомогою **ESP32-S3**. Прошивка автоматично виконує цикли руху на різних швидкостях, перевіряє прискорення та гальмування, а також повторювані переміщення вперед і назад. Повідомлення про перебіг тестів виводяться в послідовний монітор.

## Апаратне підключення

У поточній прошивці призначення контактів ESP32-S3 такі:

| Сигнал драйвера | Контакт ESP32-S3 |
| --- | ---: |
| STEP | GPIO 5 |
| DIR | GPIO 6 |
| EN | GPIO 4 |

Підключіть сигнали до відповідних входів MKS SERVO42C та забезпечте двигун і драйвер належним живленням. Перед запуском перевірте сумісність рівнів сигналу й підключення відповідно до документації драйвера.

## Збірка та запуск

Проєкт налаштовано для PlatformIO: плата `esp32-s3-devkitm-1`, Arduino framework, швидкість послідовного порту — **115200 бод**. Залежність від `FastAccelStepper` задається у `platformio.ini`.

1. Відкрийте проєкт у PlatformIO.
2. Зберіть і завантажте прошивку на ESP32-S3.
3. Відкрийте Serial Monitor на швидкості 115200 бод.

Після запуску прошивка робить паузу, послідовно виконує п’ять тестів і повторює цикл. Параметри швидкості, прискорення та тривалості тестів можна змінити у `src/main.cpp`.

## Матеріали MKS SERVO42C

Нижче наведено довідкові матеріали виробника драйвера, які зберігаються разом із проєктом.

---

# MKS SERVO42C V1.1
MKS SERVO42C is an upgraded version of MKS SERVO42B, It built-in Field-Oriented Control algorithm , position/speed/ torque  closed-loop ,4 Half bridge driver with 8 MOSFET,  it makes the motor quieter, lower vibration and Lower calorific. it supports serial port control.  
Compared with MKS SERVO42C V1.0, MKS SERVO42C V1.1 has improved many functions and fixed many problems, [Click to view](https://github.com/makerbase-mks/MKS-SERVO42C/releases/tag/MKS-SERVO42C-V1.1).

## Related tutorials and Notice
* We developed and open sourced [MKS SERVO42C CONTROL TOOL](https://github.com/makerbase-mks/MKS-SERVO42C/tree/MKS-SERVO42C-V1.1/MKS%20SERVO42C%20CONTROL%20TOOL).

* User manual.[click here](https://github.com/makerbase-mks/MKS-SERVO42C/wiki)

* Welcome to follow us on Facebook to learn about the company's latest developments.[click here](https://www.facebook.com/Makerbase.mks/)
## How to buy
[Aliexpress link（PCBA）](https://www.aliexpress.com/item/1005003340856835.html)

[Aliexpress link（with motor）](https://www.aliexpress.com/item/1005003341058386.html)
## Comparison of 42C, 42B and 42A
We released a video. [Please watch.](https://www.youtube.com/watch?v=23O0bUudVkM)
|Product name| MKS SERVO42C | MKS SERVO42B | MKS SERVO42A | 
|------------|--------------------|--------------------|--------------------|
|The frequency of update| Position:10KHz Velocity:10KHz Torque:20KHz| Position:8KHz| Position:5KHz|
|PID control mode| Incremental PID | Incremental PID | sPID/pPID/vPID,The default is sPID |
|Driver| 4 Half bridge driver with 8 MOSFET | Allergo A4954 Motor Driver | Allergo A4954 Motor Driver |
|OLED| YES | Optional | Optional |
|Opreating Voltage| 7-28V | 12-24V | 12-24V |
|Adjustable range of current| 0-3000mA | 0-1500mA | 0-2000mA |
|USART| YES | NO | YES |
|Field-Oriented Control| YES | NO | NO|
|Subdivision| 1-256(1,2,4,8,16,32,64,128,256 can be set by the key,and others can be set by serial port) | 16,32,64,128,256 |16,32,64,128,256 |
|Angle Resolution| 0.08 degrees | 0.125 degrees | 0.125 degrees |
|Maximum speed| 1000RPM | 600RPM | 600RPM |
|Motor vibration| Low | Normal | Normal |
|Motor noise| Low | Normal | Normal |
|Motor temperature| Low | Normal | Normal |
## Hardware
* [MKS SERVO42C V1.00](https://github.com/makerbase-mks/MKS-SERVO42C/tree/main/Hardware/MKS%20SERVO42C%20V1.00)
## Firmware
![mks_link](https://user-images.githubusercontent.com/12979070/149611774-c2e4e56f-ee07-46c2-abff-a3e3cdd629ae.png)

# Cahier des charges - Développement et Fabrication Projet Rover GNSS

## Modules GNSS Possibles

1. **F9P Drotek Mpcie:**
   - [Lien Produit](https://store-drotek.com/923-DP0602.html)
   - [Fiche Technique](https://raw.githubusercontent.com/drotek/datasheets/master/DrotekDoc_0923%20-%20DP0602%20(mPCIe%20F9P).pdf)
   - ![image](https://github.com/jancelin/RoverGNSS_RTK_BT_esp32_f9p/assets/6421175/bc562449-4c93-4c96-ac31-dea995517e41)

2. **F9P Ardusimple Mpcie:**
   - [Lien Produit](https://www.ardusimple.com/product/simplertk2b-mpcie-zed-f9p/)
   - Connectique en évolution pour les prochains modèles, en attendant : [Guide d'intégration PCB](https://www-ardusimple-com.translate.goog/pcb-integration-guide-simplertk2b-mpcie/?_x_tr_sl=auto&_x_tr_tl=en&_x_tr_hl=auto)

3. **Mosaic X5 Ardusimple Mpcie:**
   - [Lien Produit](https://www.ardusimple.com/product/simplertk3b-mpcie-septentrio-mosaic/)
   - ![image](https://github.com/jancelin/RoverGNSS_RTK_BT_esp32_f9p/assets/6421175/18602417-c3d7-48cf-a976-15696fe26927)


## Référence des Pinouts des Cartes GNSS en Mpcie

1. **F9P Mpcie Ardusimple:**
   - 36 USB_DATA-
   - 38 USB_DATA+
   - 22 RESET

2. **F9P Mpcie Drotek:**
   - 17 UART1 Tx
   - 19 UART1 Rx
   - 36 USB_DATA-
   - 38 USB_DATA+
   - 45 UART2 Tx
   - 47 UART2 Rx
   - 49 EXTINT
   - 51 TIMEPULSE

3. **Mosaic X5 Mpcie Ardusimple:**
   - 11 COM2 Rx
   - 13 COM2 Tx
   - 17 EXTINT
   - 19 TIMEPLUSE
   - 22 RESET
   - 36 USB_DATA-
   - 38 USB_DATA+
   - 45 COM3 Rx
   - 47 COM3 Tx
   - 49 COM1 Rx
   - 51 COM1 Tx

## Microcontrôleur ESP32 WROOM

- [Pinout Joy-It SBC-NodeMCU-ESP32](https://joy-it.net/files/files/Produkte/SBC-NodeMCU-ESP32/SBC-NodeMCU-ESP32-Manual-2021-06-29.pdf)

  ![image](https://github.com/jancelin/RoverGNSS_RTK_BT_esp32_f9p/assets/6421175/8c0e1e21-467d-4e64-9869-d3256f4bad83)


## Connexion ESP32 -> F9P Drotek

### Dev Actuel Transposé au Matériel Connectique Mpcie

> L'ensemble des projets est théoriquement adaptable en connexion sur les pinouts USB, mais l'accès aux autres pins est essentiel au maximum.

- **Projet "ROVER Bluetooth"** ([Lien GitHub](https://github.com/jancelin/RoverGNSS_RTK_BT_esp32_f9p))
  - 16 UART1 Rx ESP32 -> UART1 17 Tx Drotek F9P
  - 17 UART1 Tx ESP32 -> UART1 19 Rx Drotek F9P

- **Projet "PHYSALIA_MAVI"** ([Lien GitHub](https://github.com/jancelin/physalia/tree/main/buoy_mavi))
  - Connexion data en SDA/SDC, possible de l'adapter en UART (normalement):
  - 16 UART1 Rx ESP32 -> UART1 17 Tx Drotek F9P
  - 17 UART1 Tx ESP32 -> UART1 19 Rx Drotek F9P

- **F9p-ntrip-esp32** ([Lien GitHub](https://github.com/buched/F9p-ntrip-esp32))
  - 17 UART1 Rx ESP32 -> UART1 17 Tx Drotek F9P
  - 23 VSPI_MOSI ESP32 -> UART1 19 Rx Drotek F9P

...

## Possibilités

### Objectif PCB

Offrir le plus de possibilités de connexion entre l'ESP32, le récepteur GNSS, et des pins à souder. Si il n'est pas possible d'avoir une connexion directe, prévoir des pins à souder qui amènent directement au port du matériel.

### Pins Communs aux Récepteurs GNSS Mpcie

- **Pin 36**
  - USB_DATA- (Sortie - Drotek)
  - USB_DATA- (Sortie - Ardusimple MosaicX5)

- **Pin 38**
  - USB_DATA+ (Sortie - Drotek)
  - USB_DATA+ (Sortie - Ardusimple MosaicX5)

- **Pin 17**
  - Extint (Entrée et Sortie)
  - UART1 Tx (Sortie - Drotek)

- **Pin 19**
  - Timepulse (Entrée et Sortie)
  - UART1 Rx (Entrée - Drotek)
  - Timepulse (Sortie - Ardusimple MosaicX5)

- **Pin 45**
  - UART2 Tx (Sortie - Drotek)
  - COM3 Rx (Entrée - Ardusimple MosaicX5)

- **Pin 47**
  - UART2 Rx (Entrée - Drotek)
  - COM3 Tx (Sortie - Ardusimple MosaicX5)

- **Pin 49**
  - Extint (Sortie - Drotek)
  - COM1 Rx (Entrée - Ardusimple MosaicX5)

- **Pin 51**
  - Timepulse (Sortie - Drotek)
  - COM1 Tx (Sortie - Ardusimple MosaicX5)

### Connexion ESP32 -> GNSS

- **Pin 01 UART0 Tx** -> **Pin 36**
  - USB_DATA- (Entrée - Drotek)
  - USB_DATA- (Entrée - Ardusimple MosaicX5)

- **Pin 03 UART0 Rx** -> **Pin 38**
  - USB_DATA+ (Sortie - Drotek)
  - USB_DATA+ (Sortie - Ardusimple MosaicX5)

- **Pin 16 UART1 Tx** -> **Pin 45**
  - UART2 Tx (Sortie - Drotek)
  - COM3 Rx (Entrée - Ardusimple MosaicX5)

- **Pin 17 UART1 Rx** -> **Pin 47**
  - UART2 Rx (Entrée - Drotek)
  - COM3 Tx (Sortie - Ardusimple MosaicX5)
 
- **Pin 22 VSPI_MOSI Rx** -> 

### Objectifs Supplémentaires

- Rendre accessible ESP32 UART1-GNSS 45/47 + SCL/SDA en connectique à souder
- Rendre accessible alimentation 3.3V/VIN+GND en connectique à souder
- Switch pour paramétrage USB (UART0) vers ESP32 ou récepteur GNSS
- Microcontrôleur ESP32 WROOM pour Bluetooth classique
- Charge batterie connexion USB
- Batterie 2000mAh
- connecteur batterie standard 2mm
- Niveau de charge
- Interrupteur général ON/OFF
- Compact, plat, format carte de crédit
- Antenne GNSS: Connectique SMA F90 to IPEX-1 F, blindée, longueur à adapter en fonction du modèle 3D de la boîte (environ 5-10 cm)
- Exemple de montage ports data supplémentaires [Voir ici](https://www.seeedstudio.com/Grove-Shield-for-Seeeduino-XIAO-p-4621.html)
- Modèle 3D, impression
- Intégration module 4g

### Branchement

 exemple de connexion avec f9p Drotek ou mosaic x5 ardusimple AS
 
| ESP32 WROOM| FONCTION             | Piste       | Mpcie GNSS| FONCTION                      | Piste | à Souder| Commentaires              |
|:----------:|:--------------------:|:-----------:|:---------:|:-----------------------------:|:-----:|:-------:|:-------------------------:|
| **01**| **UART0 Tx**              | ----------->| **36**| **USB_DATA-**                     | -     |  -      |                           |
| **03**| **UART0 Rx**              | <-----------| **38**| **USB_DATA+**                     | -     |  -      |                           |
| **16**| **UART1 Rx**              | <-----------| **45**| **UART2 Tx Drotek / COM3 Rx AS**  |<----- | **1**   |                           |
| **17**| **UART1 Tx**              | ----------->| **47**| **UART2 Rx Drotek / COM3 Tx AS**  |-----> | **2**   |                           |
| **19**| **UART2 Rx SPI VSPI_MISC**| <-----jumper| **17**| **UART1 Tx Drotek / Extint AS**   |<----- | **3**   |#include <HardwareSerial.h>|
| **19**|                           | <-----jumper| **49**| **Extint Drotek / COM1 Rx AS**    |-----> | **4**   |                           |
| **23**| **UART2 Tx SPI VSPI_MOSI**| ----->jumper| **19**| **UART1 Rx Drotek / Timepulse AS**|-----> | **5**   |#include <HardwareSerial.h>|
| **23**|                           | ----->jumper| **51**| **Timepulse Drotek / COM1 Tx AS** |-----> | **6**   |                           |
| **21**| **I2C SDA**               | <-----------|-------|-----------------------------------|-----> | **SDA** |                           |
| **22**| **I2C SCL**               | <-----------|-------|-----------------------------------|-----> | **SCL** |                           |
|**GND**| <-------------------------| ----------> | **4** | **GND**                           |-----> | **GND** |                           |
|**3V3**| <-------------------------| ----------> | **2** | **3V3**                           |-----> | **3V3** |                           |
|**VIN**| <-------------------------| ------------|-------|-----------------------------------|-----> | **VIN** |                           |

> TODO rajouter tout SPI? https://randomnerdtutorials.com/esp32-microsd-card-arduino/

> TODO ou brancher un récepteur 4G?

### Schéma Branchement

```mermaid
flowchart LR
    00{ESP32}
    00 --> 01
    00 --> 02
    00 --> 03
    00 --> 04
    00 --> 05
    00 --> 06
    00 --> 07
    00 --> 08
    00 --> 09
    00 --> 10
    01[Esp32_01] -->|UART0 Tx| 21[Mpcie_36]
    02[Esp32_03] -->|UART0 Rx| 22[Mpcie_38]
    03[Esp32_16] -->|UART1 Rx| 23[Mpcie_45]
    23 --> 41[*pin 1]
    04[Esp32_17] -->|UART1 Tx| 24[Mpcie_47]
    24 --> 42[*pin 2]
    05[Esp32_19] -->|UART2 Rx| 60{Jumper_1}
    60 --> 25[Mpcie_17]
    60 --> 26[Mpcie_49]
    25 --> 43[*pin 3]
    26 --> 44[*pin 4]
    06[Esp32 23] -->|UART2 Tx| 62{Jumper_2}
    62 --> 27[Mpcie_19]
    62 --> 28[Mpcie_51]
    27 --> 45[*pin 5]
    28 --> 46[*pin 6]
    07[Esp32_SDA] --> 47[pin SDA]
    08[Esp32_SCL] --> 48[pin_SCL]
    09[Esp32_GND] --> 29[Mpcie_GND]
    29 --> 49[*pin GND]
    10[Esp32_3V3] --> 30[Mpcie_3V3]
    30 --> 50[*pin 3V3]
    11[Esp32_VIN] --> 51[*pin VIN]
    70{Alimentation}
    70 --> 71
    70 --> 72
    70 --> 73
    71[5V] --> 11
    72[GND] --> 09
    73[3v3] --> 10
    

```




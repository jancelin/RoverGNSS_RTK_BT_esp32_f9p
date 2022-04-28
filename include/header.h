#ifndef HEADER_H
#define HEADER_H

#include <Arduino.h>

/* Serial */
#define BAUD_SERIAL 115200 // Debug Serial baund rate
#define BAUND_RECEIVER 0   // Auto detect baud //921600 // GPS receiver baund rate
#define SERIAL_SIZE_RX 1024
/* SD card */
#ifdef ESP32
#ifdef TTGO_BOARD
#define CS_PIN 13
#define RXD2 32
#define TXD2 33
#define RXD1 13
#define TXD1 23
#else
#define CS_PIN 5 // SD card cs_pin (default D5 GPIO5 on ESP32 DevkitV1)
#define RXD2 16
#define TXD2 17
#define RXD1 4
#define TXD1 15
#endif // TTGO_BOARD
#else
#error Platform not supported
#endif // ESP32

#endif // HEADER_H
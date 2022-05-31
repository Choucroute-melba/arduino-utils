#ifndef SERIAL_BUFFER_H
#define SERIAL_BUFFER_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class SerialBuffer
{
    public :
    SerialBuffer();
    SerialBuffer(SoftwareSerial * serial);
    void tick();
    int available();
    int linesAvailable();
    byte read();
    byte * readLine();

    private :
    SoftwareSerial * m_serial;

    byte * content;
    int size = -1;
};


#endif

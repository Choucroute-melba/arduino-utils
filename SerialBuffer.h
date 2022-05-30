#ifndef SERIAL_BUFFER_H
#define SERIAL_BUFFER_H

#include <Arduino.h>

class SerialBuffer
{
    public :
    SerialBuffer();
    void tick();
    int available();
    int linesAvailable();
    byte read();
    byte * readLine();

    private :

    byte * content;
    int size = -1;
};


#endif

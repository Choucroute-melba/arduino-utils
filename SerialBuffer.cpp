#include "SerialBuffer.h"

// init the content of the buffer
SerialBuffer::SerialBuffer()
{
  content = (byte *) malloc(sizeof(byte));
  if(content == NULL)
    size = -1;
  else
    size = 0;
}

//return the number of bytes available in the buffer
int SerialBuffer::available()
{
  return size;
}

// add received bytes to the buffer
void SerialBuffer::tick()
{
  if(size == -1)
    return;
  if(Serial.available())
  {
    content[size] = Serial.read();
    size++;
    content = (byte *) realloc(content, sizeof(byte) * (size + 1));
  }
}

// return the number of lines available in the buffer
int SerialBuffer::linesAvailable()
{
  int lines = 0;
  for(int i = 0; i < size; i++)
  {
    if(content[i] == '\n')
      lines++;
  }
  return lines;
}

// read one byte from the buffer
byte SerialBuffer::read()
{
  if(size == -1)
    return 0;
  char c = content[0];
  for(int i = 0; i < size; i++)
  {
    content[i] = content[i + 1];
  }
  size--;
  content = (byte *) realloc(content, sizeof(byte) * size);
  return c;
}

// read one line from the buffer
byte * SerialBuffer::readLine()
{
  if(size == -1)
    return NULL;
  int i = 0;
  while(content[i] != '\n')
  {
    i++;
  }
  byte * line = (byte *) malloc(sizeof(byte) * (i + 1));
  for(int j = 0; j < i; j++)
  {
    line[j] = content[j];
  }
  line[i] = '\0';
  for(int j = 0; j < size; j++)
  {
    content[j] = content[j + i + 1];
  }
  size -= i + 1;
  content = (byte *) realloc(content, sizeof(byte) * size);
  return line;
}
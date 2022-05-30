#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <Arduino.h>

class Command
{
  public :
  Command(const char * cmd);
  char * getValue(const char * argName);

  char * name() { return m_cmdName; }
  char * args() { return m_rawArgs; }
  char * raw() { return m_rawCmd; }

  private :
  char * m_rawCmd;
  int m_rawCmdLength;
  char * m_cmdName;
  int m_cmdNameLength;
  char * m_rawArgs;
  int m_rawArgsLength;
};


#endif
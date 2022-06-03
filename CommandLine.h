#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <Arduino.h>

class Command
{
  public :
  Command(const char * cmd);
  char * getValue(const char * argName);

  char * name() { return m_cmdName; }
  bool setName(const char * newName);
  char * args() { return m_rawArgs; }
  bool setArg(const char * newArgName, const char * newArgValue);
  char * raw() { return m_rawCmd; }
  bool setRaw(const char * newRaw);

  private :
  bool parse();

  char * m_rawCmd;
  int m_rawCmdLength;
  char * m_newRawCmd;
  int m_newRawCmdLength;

  char * m_cmdName;
  int m_cmdNameLength;
  char * m_newCmdName;
  int m_newCmdNameLength;

  char * m_rawArgs;
  int m_rawArgsLength;
  char * m_newRawArgs;
  int m_newRawArgsLength;
};


#endif

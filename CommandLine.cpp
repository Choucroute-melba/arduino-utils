#include "CommandLine.h"

Command::Command(const char * cmd)
{
  m_rawCmd = (char *) cmd;
  m_rawCmdLength = strlen(cmd);
  m_cmdName = strtok(m_rawCmd, " ");
  m_cmdNameLength = strlen(m_cmdName);
  m_rawArgs = strtok(NULL, " ");
  m_rawArgsLength = strlen(m_rawArgs);
}

// get the value of the argument with the given name
char * Command::getValue(const char * argName)
{
  char * argNamePtr = strstr(m_rawArgs, argName);
  if(argNamePtr == NULL)
    return NULL;

  strtok(argNamePtr, " ");
  char * argValue = strtok(NULL, " ");
  return argValue;
}

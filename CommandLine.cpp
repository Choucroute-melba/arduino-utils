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

bool Command::parse()
{
  // check if the command name has changed
  if(strcmp(m_cmdName, m_newCmdName) != 0)
  {
    m_cmdName = m_newCmdName;
    m_cmdNameLength = m_newCmdNameLength;
    return true;
  }

  // check if the arguments have changed
  if(strcmp(m_rawArgs, m_newRawArgs) != 0)
  {
    m_rawArgs = m_newRawArgs;
    m_rawArgsLength = m_newRawArgsLength;
    return true;
  }

  // check if the raw command have changed
  if(strcmp(m_rawCmd, m_newRawCmd) != 0)
  {
    m_rawCmd = m_newRawCmd;
    m_rawCmdLength = m_newRawCmdLength;
    
    m_cmdName = strtok(m_rawCmd, " ");
    m_cmdNameLength = strlen(m_cmdName);
    m_rawArgs = strtok(NULL, " ");
    m_rawArgsLength = strlen(m_rawArgs);
    return true;
  }

  return false;
}

bool Command::setName(const char * newName)
{
  m_newCmdName = (char *) newName;
  m_newCmdNameLength = strlen(newName);
  return parse();
}

bool Command::setArg(const char * newArgName, const char * newArgValue)
{
  char * argNamePtr = strstr(m_rawArgs, newArgName);
  if(argNamePtr == NULL)
    return false;
  {
    m_newRawArgs = strcpy(m_newRawArgs, m_rawArgs);
    m_newRawArgsLength = strlen(m_newRawArgs) + strlen(argNamePtr);
    m_newRawArgs = strcat(m_newRawArgs, argNamePtr);
    return parse();
  }
}

bool Command::setRaw(const char * newRaw)
{
  m_newRawCmd = (char *) newRaw;
  m_newRawCmdLength = strlen(newRaw);
  return parse();
}

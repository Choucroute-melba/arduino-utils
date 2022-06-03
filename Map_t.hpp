#include "Map.h"

template <typename TK, typename TV>
Pair<TK, TV>::Pair()
{
  m_key = 0;
  m_value = 0;
}

template <typename TK, typename TV>
Pair<TK, TV>::Pair(const TK key, const TV value)
{
  m_key = key;
  m_value = value;
}

template <typename TK, typename TV>
Pair<TK, TV>::Pair(const Pair & p)
{
  m_key = p.m_key;
  m_value = p.m_value;
}

template <typename TK, typename TV>
Map<TK, TV>::Map()
{
  m_size = 0;
  m_pairs = nullptr;
}

template <typename TK, typename TV>
Map<TK, TV>::Map(Pair <TK, TV> pairs[], const int size)
{
  m_size = size;
  m_pairs = new Pair<TK, TV>[size];
  for(int i = 0; i < size; i++)
  {
    m_pairs[i] = pairs[i];
  }
}

template <typename TK, typename TV>
bool Map<TK, TV>::add(const TK key, const TV value)
{
  if(m_size == 0)
  {
    m_pairs = new Pair<TK, TV>[1];
  }
  else
  {
    Pair<TK, TV> * newPairs = new Pair<TK, TV>[m_size + 1];
    for(int i = 0; i < m_size; i++)
    {
      newPairs[i] = m_pairs[i];
    }
    delete[] m_pairs;
    m_pairs = newPairs;
  }
  m_pairs[m_size] = Pair<TK, TV>(key, value);
  m_size++;
  return true;
}

template <typename TK, typename TV>
bool Map<TK, TV>::remove(const TK key)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_pairs[i].key() == key)
    {
      for(int j = i; j < m_size - 1; j++)
      {
        m_pairs[j] = m_pairs[j + 1];
      }
      m_size--;
      return true;
    }
  }
  return false;
}

template <typename TK, typename TV>
bool Map<TK, TV>::contains(const TK key)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_pairs[i].key() == key)
    {
      return true;
    }
  }
  return false;
}

template <typename TK, typename TV>
const TV Map<TK, TV>::get(const TK key)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_pairs[i].key() == key)
    {
      return m_pairs[i].value();
    }
  }
  return TV();
}

template <typename TK, typename TV>
const TK Map<TK, TV>::getKey(const TV value)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_pairs[i].value() == value)
    {
      return m_pairs[i].key();
    }
  }
  return TK();
}

template <typename TK, typename TV>
void Map<TK, TV>::set(const TK key, const TV value)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_pairs[i].key() == key)
    {
      m_pairs[i].setValue(value);
      return true;
    }
  }
  return false;
}

template <typename TK, typename TV>
void Map<TK, TV>::clear()
{
  delete[] m_pairs;
  m_size = 0;
}

template <typename TK, typename TV>
int const Map<TK, TV>::size()
{
  return m_size;
}

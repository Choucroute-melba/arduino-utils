#ifndef MAP_H
#define MAP_H

template <typename TK, typename TV>
class Pair
{
  public:

  Pair();
  Pair(const TK key, const TV value);
  Pair(const Pair & p);

  const TK key() { return m_key; }

  const TV value() { return m_value; }

  void setValue(const TV value) { m_value = value; }

  private:
  TK m_key;
  TV m_value;
};

template <typename TK, typename TV>
class Map
{
  public:
  Map();
  Map(Pair <TK, TV> pairs[], const int size);
  bool add(const TK key, const TV value);
  bool remove(const TK key);
  bool contains(const TK key);
  TV const get(const TK key);
  void set(const TK key, const TV value);
  void clear();
  const int size();

  private:
  int m_size;
  Pair<TK, TV> * m_pairs;
};

#include "Map_t.hpp"

#endif // MAP_H
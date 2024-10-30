#include <string>
#define SOURCE_H
using namespace std;

class Monster
{
private:
    std::string m_monsterName;
    int m_monsterHP;
    int m_monsterEXP;
    int m_monsterLevel;

public:

    int getHP() { return m_monsterHP; }
    int getEXP() { return  m_monsterEXP; }
    int getLevel() { return m_monsterLevel; }
    string getName() { return m_monsterName; }

    void setHP(int x) { m_monsterHP = x; }
    void setEXP(int x) { m_monsterEXP = x; }
    void setLevel(int x) { m_monsterLevel = x; }
    void setName(string x) { m_monsterName = x; }
};


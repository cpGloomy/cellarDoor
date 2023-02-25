#ifndef MOBILE_H
#define MOBILE_H

#include <string>

struct OffensiveStats
{
    int WeaponSkill = 75;
    int Damage = 20;
};

class Mobile
{
    public:
        Mobile() {};
        Mobile(std::string name) 
            : name(name) {};
        ~Mobile() {};

        std::string GetName() { return name; }
        void SetName(std::string name) { this->name = name; }
        virtual void Dodge() = 0;

    protected:
        std::string name;
        int maxHP = 1;
        int currentHP = 1;
        int maxMP = 0;
        int currentMP = 0;
        int Exp = 0;
        int Level = 1;

        OffensiveStats OStats;
};

class Combatant
{
    public:
        Combatant(Mobile &combatant) : combatant(combatant) {};
        void Attack(Mobile &defender);
        Mobile &combatant;

        //virtual void OnHit() = 0;
        //virtual void DealDamage() = 0;
        //virtual void OnTakeHit() = 0;
        //virtual void TakeDamage() = 0;
};

class PlayerCharacter : public Mobile
{
    public:
        void Attack(Mobile &defender);
        void Dodge();
        //virtual void OnHit() = 0;
        //void DealDamage(Mobile &attacker, Mobile &defender);
        //virtual void OnTakeHit() = 0;
        //void TakeDamage(Mobile &attacker, Mobile &defender);

    private:
        //Skills skills;
        //Spells spells;
        //Mobile[] minions;
};

class Minion : public Mobile
{
    public:
        void Attack(Mobile &defender);
        //virtual void OnHit() = 0;
        //void DealDamage(Mobile &attacker, Mobile &defender);
        //virtual void OnTakeHit() = 0;
        //void TakeDamage(Mobile &attacker, Mobile &defender);
};

class Monster : public Mobile
{
    public:
        void Attack(Mobile &defender);
        void Dodge();
        //virtual void OnHit() = 0;
        //void DealDamage(Mobile &attacker, Mobile &defender);
        //virtual void OnTakeHit() = 0;
        //void TakeDamage(Mobile &attacker, Mobile &defender);
};

#endif
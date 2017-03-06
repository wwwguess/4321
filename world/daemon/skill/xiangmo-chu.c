//xiangmo-chu.c -��ħ��

#include <combat.h>

inherit SKILL;
inherit "/adm/daemons/weapond.c";

mapping *action = ({
([      "action" : "$N����$w�������ӰƮ�������ص���$n��$l",
        "force" : 60,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 0,
                "damage_type":  "����",
]),
([      "action" : "$N����$wһ������ͷһ������$n���ؿ�",
        "force" : 80,
        "dodge" : 10,
        "damage" : 30,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 16,
                "damage_type":  "����",
]),
([      "action" : "$N����$w������һ���󻡣���������$n",
        "force" : 110,
        "dodge" : 15,
        "damage" : 35,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 32,
                "damage_type":  "����",
]),
([      "action" : "$N$w��һ������ĽǶ�����$n��$l",
        "force" : 140,
        "dodge" : 5,
        "damage" : 50,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 41,
                "damage_type":  "����",
]),
([      "action" : "$N$w��磬��$n��ȫ��ӿȥ",
        "force" : 180,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 55,
                "damage_type":  "����",
]),
([      "action" : "$N����$wһ������ͷ����$n���ؿ�",
        "force" : 220,
        "dodge" : -20,
        "damage" : 70,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 70,
                "damage_type":  "����",
]),
([      "action" : "$N����$wЮ�������֮������$n",
        "force" : 300,
        "dodge" : -20,
        "damage" : 90,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 90,
                "damage_type":  "����",
]),
});

int valid_enable(string usage) { return usage == "pestle" || usage == "parry"; }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xiangmo-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "halberd")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("�����������������ꪡ�\n");
        me->receive_damage("kee", 25);
        return 1;
}

string *parry_msg = ({
        "$nһ��$v�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$n����$v�����е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ������$N�������ȥ��\n",
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n���ִ̳�$v����������ʧ��һ�Ź�â֮�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�ͻ�$N�����ţ��Ƶ�$N��;����$w��\n",
        "$n����Ϊ��������$v�ͻ�$N������\n",
        "$n��������һ��$N$w����ƫ��$N$w��\n",
        "$n������������$N֮�ؾȡ�\n",
        "$n��ȭ���£���ȭ�Ա�����$N���ڳ��⡣\n",
        "$n˫ȭ�����$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

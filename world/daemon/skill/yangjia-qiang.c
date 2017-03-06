// yangjia-qiang.c ���ǹ

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w���죬���ƻԻͣ�һǹ����$n��$l",
        "force" : 120,
        "dodge" : -10,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��$wһ������������һ��ǹ��,����$n��$l",
        "force" : 130,
        "dodge" : -10,
        "damage" : 5,
        "lvl" : 8,
        "damage_type" : "����"
]),
([      "action" : "$N���һ������$wʹ����ͬһ�����ߴ���$n��$l",
        "force" : 140,
        "dodge" : -5,
  	"damage" : 15,
        "lvl" : 16,
        "damage_type" : "����"
]),
([      "action" : "$N����$w������һ���һ��Բ��������$n��$l",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 24,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ������$w����$n��$l",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ǹ����������$n",
        "force" : 210,
    	"dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "damage_type" : "����"
]),
([      "action" : "$N˫ĿԲ����$wֻ��һ���ɷ�����$n��$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 51,
        "damage_type" : "����"
]),
([      "action" : "$N����Խ��ǹ������������ɷ���$n��$l��ȥ",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "spear" || usage == "parry"; }

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
        level = (int) me->query_skill("yangjia-qiang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("����������������ǹ��\n");
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

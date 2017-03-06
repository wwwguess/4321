//lujia-ji.c -�����

inherit SKILL;
inherit "/adm/daemons/weapond.c";

mapping *action = ({
([      "action" : "$N����$wбָ��������Σ�һ���$n��$l��ȥ",
        "force" : 120,
        "dodge" : -10,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��$wһ��������$n�ľ���",
        "force" : 130,
        "dodge" : -10,
        "damage" : 5,
        "lvl" : 8,
        "damage_type" : "����"
]),
([      "action" : "$N���һ������$w���϶��£�����$n",
        "force" : 140,
        "dodge" : -5,
  	"damage" : 15,
	"post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 16,
        "damage_type" : "����"
]),
([      "action" : "$N$w�󿪴��أ����¶��ϻ���һ���󻡣���ֱ����$n",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
	"post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 24,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����˫�ֳ�$w�������У�����$n��$l",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "damage_type" : "����"
]),
([      "action" : "$N����$w���ޱ��޼ʵ��Ӱͱ��$n",
        "force" : 210,
  	"dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��Ӱ���Σ�Ю���ҷ�������$n��$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
	"post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 51,
        "damage_type" : "����"
]),
([      "action" : "$N����$wꪹ���ѩ����$n��ȫ��ͱȥ",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "halberd" || usage == "parry"; }

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
        level   = (int) me->query_skill("lujia-ji",1);
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

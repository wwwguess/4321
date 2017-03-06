// yuxiao-jian.c ���｣��
// cleansword 2/15/96
// Marz 5/21/96

inherit SKILL;

mapping *action = ({
([      "action" : "$N�鲽����������$w���������һ��������$n��$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ�������ֽ���������$wֱ��$n��$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
        "force" : 170,
 	"dodge" : 15,
        "damage" : 40,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : "$N����ƽָ��һ���ǳɺ�ɨ$n��$l",
        "force" : 190,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : "$N����ֱ�������಻�ϻ���$n��$l",
        "force" : 240,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 29,
        "damage_type" : "����"
]),
([      "action" : "$N���̤ʵ���ҽ���㣬����$w����һ�Ž���������$n��$l",
        "force" : 280,
        "dodge" : 5,
        "damage" : 70,
 	"lvl" : 39,
        "damage_type" : "����"
]),
([      "action" : "$N���Ծ����أ�$w�س飬���ֹ���$n��$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 59,
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�������ָ��ת������$n��$l",
        "force" : 330,
        "dodge" : -5,
        "damage" : 90,
        "lvl" : 79,
        "damage_type" : "����"
]),
([  "action" : "$N����š���������鱧��$w�й�ֱ��������$n��$l",
        "force" : 380,
        "dodge" : -5,
        "damage" : 115,
        "lvl" : 99,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������\n");
	if ((int)me->query_skill("taohua-force", 1) < 20)
                return notify_fail("����һ������̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yuxiao-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
 		return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("����������������｣����\n");
        me->receive_damage("kee", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yuxiao-jian/" + action;
}

string *parry_msg = ({
        "$nһ��$v�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$n����$v�����е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ������$N��������ȥ��\n",
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n���ֻӳ�$v����������ʧ��һ�Ź�â֮�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�ͻ�$N�����ţ��Ƶ�$N��;����$w��\n",
        "$n����Ϊ�����ͻ�$N������\n",
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

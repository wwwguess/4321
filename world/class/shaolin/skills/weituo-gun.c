// weituo-gun.c -Τ�ӹ�

inherit SKILL;

mapping *action = ({
([	"action":"$Nһ�С���ʯ���ġ�������$w�����ѵ�ˮ�㣬������$n������Ҫ����ȥ",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "��ʯ����",
	"damage_type":"����"
]),
([	"action":"$N��$wƽ���ؿڣ�һš��һ�С�����ͣ�桹��$w�͵�����$n�ľ���",
	"force" : 180,
        "dodge" : 5,
        "parry" : 10,
	"damage": 15,
	"lvl" : 8,
	"skill_name" : "����ͣ��",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�ƽ�����ɡ���ȫ���������ڵ��ϴ����ת���ٹ���$n���ظ����ȥ",
	"force" : 210,
        "dodge" : 5,
        "parry" : 15,
	"damage": 20,
	"lvl" : 16,
	"skill_name" : "ƽ������",
	"damage_type":"����"
]),
([	"action":"$N����һ��������һ�С��������硹��$wЮ��������Ѹ��ɨ��$n������",
	"force" : 250,
        "dodge" : 15,
        "parry" : 5,
	"damage": 25,
	"lvl" : 25,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$Nһ�С����Ǹ��¡��������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n��$l",
	"force" : 300,
        "dodge" : 20,
        "parry" : 15,
	"damage": 30,
	"lvl" : 35,
	"skill_name" : "���Ǹ���",
	"damage_type":"����"
]),
([	"action":"$N˫�ֳֹ����˸���ش�Ȧ��һ�С���ϼ���ա���һ����Բ�����л�����ײ��$n���ؿ�",
	"force" : 350,
        "dodge" : 20,
        "parry" : 15,
	"damage": 35,
	"lvl" : 44,
	"skill_name" : "��ϼ����",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�Ͷ�޶�������$w�߾٣����������֮�ƶ�׼$n�����鵱ͷ����",
	"force" : 410,
        "dodge" : 25,
        "parry" : 20,
	"damage": 40,
	"lvl" : 52,
	"skill_name" : "Ͷ�޶���",
	"damage_type":"����"
]),
([	"action":"$NǱ��������һ�С������麣����$w��ʱ�������ɣ�������ֱ��$n���ؿ�",
	"force" : 470,
        "dodge" : 30,
        "parry" : 25,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "�����麣",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return  (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("weituo-gun", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�����Τ�ӹ��İ��ء�\n");
	return 1;
}

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
	level   = (int) me->query_skill("weituo-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("�������������Τ�ӹ���\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("weituo-gun", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�����Τ�ӹ��İ��ء�\n");
	me->receive_damage("kee", 25);
	return 1;
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

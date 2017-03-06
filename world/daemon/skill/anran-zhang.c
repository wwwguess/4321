// anran-zhang.c
//  created by diablo
inherit SKILL;

mapping *action = ({
([      "action": "$NĿ����ͣ������ٻ���һ�С�����ľ��������$n��$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���α��ǣ���������һ�С�������졹����$n��$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "����"
]),
([	"action": "$N����һ����һ�С��ǻ��չȡ���Ѹ���ޱȵس���$n��$l",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage_type": "����"
]),
([	"action": "$N��������Ʈ����������ˮ��ʩ��һ�С������ˮ����������������$n��$l",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage_type": "����"
]),
([	"action": "$N���彩ֱ������һ�С���ʬ���⡹��������$n��$l",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage_type": "����"
]),
([	"action": "$Nʩ��һ�С�ӹ�����š������ֲ������Ҽ�ײ��$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$Nʹ������;ĩ·�������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage_type": "����"
]),
([	"action": "$N���һ����ʹ��������������������һ�а����$n",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage_type": "����"
]),
([	"action": "$Nʹ�������񲻰�������$n��$l��������",
	"dodge": -20,
	"parry": -20,
	"force": 230,
	"damage_type": "����"
]),
([	"action": "$N������������һ�ã�����һɨ��һ�С�������ʳ��һǰһ����$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 160,
	"damage_type": "����"
]),
([	"action": "$Nʹ��������ֻӰ�������α�ֱ���𣬵�����$n��$l����",
	"dodge": -20,
	"parry": 30,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$N����ϲŭ���֣���״�ٳ���ʹ����������ɫ����$n��������",
	"dodge": -20,
	"parry": 20,
	"force": 270,
	"damage_type": "����"
]),
([	"action": "$N������˼,һ�С�����Ƿǡ�����ס$n����·������бб������$l",
	"dodge": -15,
	"parry": 20,
	"force": 220,
	"damage_type": "����"
]),
([	"action": "$NͻȻͷ�½��ϣ��������ӣ�ʹ����������ʩ����һ������$n��$l",
	"dodge": -25,
	"parry": 10,
	"force": 350,
	"damage_type": "����"
]),
([	"action": "$N����һת��ͻȻ�۵�$n��ǰ��һ�С��ľ�����������$n��$l",
	"dodge": -20,
	"parry": 40,
	"force": 330,
	"damage_type": "����"
]),
([	"action": "$N�Ż��󿪣�һ�С��������ġ���$n��$l��ȥ",
	"dodge": -25,
	"parry": 1,
	"force": 320,
	"damage_type": "����"
]),
([	"action": "$Nʹ�����������С�����Ȼȫ����$n��$l",
	"dodge": -15,
	"parry": 40,
	"force": 200,
	"damage_type": "����"
]),
});
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ�����Ʊ�����֡�\n");
	if ((int)me->query_skill("jiuyin", 1) < 20)
		return notify_fail("��ľ����񹦵Ļ�򲻹����޷�����Ȼ�����ơ�\n");
        if ((int)me->query_skill("jiuyin", 1) < (int)me->query_skill("anran-zhang", 1) && (int)me->query_skill("jiuyin", 1) < 150)
                return notify_fail("��ľ����񹦵Ļ�򲻹����޷�������Ȼ�����Ƶ��⾳��\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷�����ȼ�����ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 10)
		return notify_fail("���������������Ȼ�����ơ�\n");
        if ((int)me->query_skill("jiuyin", 1) < (int)me->query_skill("anran-zhang", 1) && (int)me->query_skill("jiuyin", 1) < 150)
                return notify_fail("��ľ����񹦻�򲻹����޷�������Ȼ�����Ƶ��⾳��\n");
	me->receive_damage("kee", 30);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"anran-zhang/" + action;
}

string *parry_msg = ({
        "$nһ��$v�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$n����$v�����е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ������$N��������ȥ��\n",
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n���ֻӳ�$v����������ʧ��һ�Ź�â֮�С�\n",
});

string *unarmed_parry_msg = ({
        "$n����Ϊ��������$N������\n"
        "$n˫�ƽ�����ž����һ����$N��$w����˫��֮�䡣\n",
        "$n˫��һ������ƫ��$N��$w��\n",
        "$n�������ǣ�����ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
        "$n����Ϊָ������$N������ҪѨ��\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

// mo-cha-jue.c 魔叉诀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w一立，一招「健儿好身手」向$n的$l捅去!",
	"force" : 100,
        "dodge" : -20,
	"lvl" : 0,
	"skill_name" : "健儿好身手",
	"damage_type" : "刺伤"
]),
([	"action" : "$N 一招「勇锐今何愚」，$w挟着劲风，劈向$n",
	"force" : 280,
        "dodge" : -35,
	"damage" : 35,
	"lvl" : 16,
	"skill_name" : "勇锐今何愚",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「东风吹血腥」，用$w的中部砸向$n的$l",
	"force" : 260,
        "dodge" : -25,
	"damage" : 35,
	"lvl" : 24,
	"skill_name" : "东风吹血腥",
	"damage_type" : "瘀伤"
]),
});


int valid_enable(string usage) { return usage == "fork" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("tianmo-dafa", 1) < 20)
                return notify_fail("你的天魔大法功力不够! n");
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
	level   = (int) me->query_skill("mo-cha-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "cha")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练魔叉诀。\n");
	me->receive_damage("kee", 25);
	return 1;
}

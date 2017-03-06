// taiji-quan.c 太极拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「揽雀尾」，双手划了个半圈，按向$n的$l",
	"force" : 150,
	"dodge" : 30,
	"skill_name" : "揽雀尾",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚按，右手使一招「白蛇吐信」，向$n的$l插去",
	"force" : 250,
	"dodge" : 25,
	"skill_name" : "白蛇吐信",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，向前向后划弧，一招「双风贯耳」打向$n的$l",
	"force" : 300,
	"dodge" : 20,
	"skill_name" : "双风贯耳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚划，右手一记「指裆锤」击向$n的裆部",
	"force" : 320,
	"dodge" : 15,
	"skill_name" : "指裆锤",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出「伏虎式」，右手击向$n的$l，左手攻向$n的裆部",
	"force" : 370,
	"dodge" : 10,
	"skill_name" : "伏虎式",
        "damage_type" : "瘀伤"
])
});

   int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太极拳必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功火候不够，无法学太极拳。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < (int)me->query_skill("taiji-quan", 1) && (int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("你的太极神功火候不够，无法领悟太极拳形神合一，用意不用力，圆转贯串，滔滔不绝的招术.\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练太极拳。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练太极拳。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < (int)me->query_skill("taiji-quan", 1) && (int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("你的太极神功火候不够，无法领悟太极拳形神合一，用意不用力，圆转贯串，滔滔不绝的招术.\n");
	me->receive_damage("kee", 25);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n使出太极拳法「卸」字诀，$v轻轻一点，$N的$w好象打在棉絮中，对$n毫无伤害。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

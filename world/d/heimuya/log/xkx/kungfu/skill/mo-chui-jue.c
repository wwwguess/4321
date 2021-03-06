// mo-chui-jue.c 魔锤诀

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「建业暮钟」，手中$w向$n的$l砸去",
	"force" : 220,
        "dodge" : -20,
	"lvl" : 0,
	"skill_name" : "建业暮钟",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「十年离乱」,$w一提一收,$w砸向$n的颈部",
	"force" : 230,
        "dodge" : -20,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "十年离乱",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N$w一招「天地英雄」，砸向$n",
	"force" : 240,
        "dodge" : -25,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "天地英雄",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N力贯$w，一招「千秋凛然」砸向$n的$l",
	"force" : 260,
        "dodge" : -25,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "千秋凛然",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N手中$w一沉，一招「红叶萧萧」 ，当头砸向$n的胸口",
	"force" : 280,
        "dodge" : -20,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "红叶萧萧",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「雷霆震怒鬼神惊」,$w挟万钧之势砸向$n",
	"force" : 300,
        "dodge" : -20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "雷霆震怒鬼神惊",
	"damage_type" : "瘀伤"
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-chui-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 80)
		return notify_fail("你的体力不够练魔锤诀.\n");
	me->receive_damage("kee", 25);
	return 1;
}

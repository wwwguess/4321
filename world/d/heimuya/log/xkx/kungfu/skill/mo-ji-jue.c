// mo-dao-jue.c 魔戟诀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「汉兵奋迅如霹雳」，戟作刀形，一戟向$n的$l撩去",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "汉兵奋迅如霹雳",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「虏骑崩腾畏蒺藜」 ,将$w一抖，挥向$n的颈部",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "虏骑崩腾畏蒺藜",
	"damage_type" : "割伤"
]),
([	"action" : "$N大喝一声! 一招「贺兰山下阵如云」,将$w从上而下,劈向$n",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "贺兰山下阵如云",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「世事蹉跎成白首」，$w大开大阖，自下而上划出一个大弧，笔直撩向$n",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "世事蹉跎成白首",
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「昔时飞箭无全目」 ，双手持$w拦腰反切，削向$n的$l",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "昔时飞箭无全目",
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「苍茫古木连穷巷」，无边无际的戟影涌向$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
	"skill_name" : "苍茫古木连穷巷",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「羽檄交驰日夕闻」,$w如影随形，挟烈烈风声劈向$n的$l",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "羽檄交驰日夕闻",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「试拂铁衣如雪色」,戟光如雪，向$n的全身涌去",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "试拂铁衣如雪色",
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "ji" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-ji-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "ji")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练魔刀诀。\n");
	me->receive_damage("kee", 25);
	return 1;
}

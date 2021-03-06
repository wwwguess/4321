// mo-dao-jue.c 魔斧诀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w一立，一招「贼斫不死」向$n的$l砍去!",
	"force" : 180,
        "dodge" : -20,
	"lvl" : 0,
	"skill_name" : "贼斫不死",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「力尽关山」,$w似重若轻,一横削向 $n的颈部",
	"force" : 190,
        "dodge" : -30,
	"damage" : 25,
	"lvl" : 8,
	"skill_name" : "力尽关山",
	"damage_type" : "割伤"
]),
([	"action" : "$N斧作虎形, 一招「胡雁哀鸣」，挟着劲风，劈向$n",
	"force" : 210,
        "dodge" : -35,
	"damage" : 35,
	"lvl" : 16,
	"skill_name" : "胡雁哀鸣",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「杀气阵云」，$w大开大阖，自上而下划出一个圆弧，笔直劈向$n",
	"force" : 220,
        "dodge" : -15,
	"damage" : 35,
	"lvl" : 24,
	"skill_name" : "杀气阵云",
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「绝域苍茫」 ，双手持斧，砍向$n的胸口",
	"force" : 240,
        "dodge" : -20,
	"damage" : 40,
	"lvl" : 33,
	"skill_name" : "绝域苍茫",
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「野云万里」，上劈下撩，左挡右开，劈向$n",
	"force" : 260,
        "dodge" : -15,
	"damage" : 50,
	"lvl" : 42,
	"skill_name" : "野云万里",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「单于猎火」,$w一直往前，迅猛劈向$n的$l",
	"force" : 270,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "单于猎火",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「一身转战三千里」,天地变色!斧风如火!劈向$n的全身!",
	"force" : 290,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "一身转战三千里",
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "axe" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-fu-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练魔斧诀。\n");
	me->receive_damage("kee", 25);
	return 1;
}

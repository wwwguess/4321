// mo-jian-jue.c 魔剑诀

inherit SKILL;

mapping *action = ({
(["action":"$N使一式「美人如花」，手中$w由上而下，钩向$n的$l",
	"force" : 120,
        "dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "美人如花",
	"damage_type":	"割伤"
]),
(["action":"$N腰身一扭，使出「青冥之天」，钩光映雪,$w向$n的$l挥去",
	"force" : 140,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "青冥之天",
	"damage_type":	"割伤"
]),
([	"action":"$N一式「卷帷望月」Ｊ种�$w从左至右划向$n的$l",
	"force" : 60,
        "dodge" : 5,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "卷帷望月",
	"damage_type":	"割伤"
]),
([	"action":"$N纵身跃起，一式「孤灯不明」将$w圈转,霍霍斩向$n的$l",
	"force" : 80,
        "dodge" : 10,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "孤灯不明",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w中宫直进，一式「微霜凄凄」，对准$n的$l就是一钩",
	"force" : 120,
        "dodge" : 15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "微霜凄凄",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w一抖，一式「络纬秋啼」对准$n的$l斜斜钩出",
	"force" : 160,
        "dodge" : 5,
	"damage": 45,
	"lvl" : 44,
	"skill_name" : "络纬秋啼",
	"damage_type":	"刺伤"
]),
([	"action":"$N右手$w斗伸,一式「渌水之波」刺向$n的$l",
	"force" : 220,
        "dodge" : 5,
	"damage": 55,
	"lvl" : 52,
	"skill_name" : "渌水之波",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「天长路远魂飞苦」，$w猛地向$n的$l刺出!",
	"force" : 280,
        "dodge" : 5,
	"damage": 60,
	"lvl" : 60,
	"skill_name" : "天长路远魂飞苦",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "hook" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-gou-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hook")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练魔剑诀!\n");
	me->receive_damage("kee", 25);
	return 1;
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

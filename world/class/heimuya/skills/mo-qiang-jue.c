// mo-qian-jue.c 魔枪诀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w向天，一招「万夫莫开」，气势辉煌,一$w向$n的$l刺去",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "万夫莫开",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「朝避猛虎」 ,将$w一抖，抖出若大一个枪花,刺向$n的$l",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "朝避猛虎",
	"damage_type" : "刺伤"
]),
([	"action" : "$N大喝一声! 一招「夕避长蛇」,将$w使得如同一条活蛇刺向$n的$l",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "夕避长蛇",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「磨牙吮血」，$w自左而右划出一个圆弧，刺向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "磨牙吮血",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w一沉，一招「杀人如麻」 ，双手持$w刺向$n的$l",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "杀人如麻",
	"damage_type" : "刺伤"
]),
([	"action" : "$N挥舞$w，使出一招「飞湍瀑流」，枪身如龙刺向$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
	"skill_name" : "飞湍瀑流",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「枯松倒挂」,$w只如一条飞凤撩向$n的$l",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "枯松倒挂",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「蜀道之难难於上青天」,枪如游龙,人如飞凤向$n的$l刺去",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "蜀道之难难於上青天",
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return usage == "spear" || usage == "parry"; }

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
	level = (int) me->query_skill("mo-qiang-jue", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练魔刀诀。\n");
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

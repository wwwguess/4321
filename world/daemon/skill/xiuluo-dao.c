// xiuluo-dao.c 修罗刀

inherit SKILL;

mapping *action = ({
([	"action" : "$N藏刀内收，一招「割肉饲鹰」，刀锋自下而上划了个半弧，向$n的$l挥去",
	"force" : 120,
        "dodge" : -10,
        "parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "割肉饲鹰",
	"damage_type" : "割伤"
]),
([	"action" : "$N左掌虚托右肘，一招「投身饿虎」，手中$w笔直划向$n的$l",
	"force" : 130,
        "dodge" : -10,
        "parry" : 10,
	"damage": 20,
	"lvl" : 12,
	"skill_name" : "投身饿虎",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「斫头谢天」，$w绕颈而过，刷地一声自上而下向$n猛劈",
	"force" : 140,
        "dodge" : -5,
        "parry" : 5,
	"damage": 25,
	"lvl" : 18,
	"skill_name" : "斫头谢天",
	"damage_type" : "割伤"
]),
([	"action" : "$N右手反执刀柄，一招「折骨出髓」，猛一挫身，$w直向$n的颈中斩去",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage": 30,
	"lvl" : 24,
	"skill_name" : "折骨出髓",
	"damage_type" : "割伤",
]),
([	"action" : "$N一招「挑身千灯」，无数刀尖化作点点繁星，向$n的$l挑去",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage": 35,
	"lvl" : 30,
	"skill_name" : "挑身千灯",
	"damage_type" : "割伤"
]),
([	"action" : "$N双手合执$w，一招「挖眼布施」，拧身急转，刀尖直刺向$n的双眼",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "挖眼布施",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「剥皮书经」，手中$w划出一个大平十字，向$n纵横劈去",
	"force" : 240,
        "dodge" : 15,
        "parry" : 15,
	"damage": 50,
	"lvl" : 42,
	"skill_name" : "剥皮书经",
	"damage_type" : "割伤"
]),
([	"action" : "$N反转刀尖对准自己，一招「剜心决志」，全身一个翻滚，$w向$n拦腰斩去",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage": 60,
	"lvl" : 48,
	"skill_name" : "剜心决志",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「烧身供佛」，$w的刀光仿佛化成一簇簇烈焰，将$n团团围绕",
	"force" : 320,
        "dodge" : 10,
        "parry" : 20,
	"damage": 75,
	"lvl" : 54,
	"skill_name" : "烧身供佛",
	"damage_type" : "割伤"
]),
([	"action" : "$N刀尖平指，一招「刺血满地」，一片片切骨刀气如飓风般裹向$n的全身",
	"force" : 370,
        "dodge" : 5,
        "parry" : 25,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "刺血满地",
	"damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="damo-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候太浅。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("xiuluo-dao", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握修罗刀的奥秘。\n");
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
	level   = (int) me->query_skill("xiuluo-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练修罗刀。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("xiuluo-dao", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握修罗刀的奥秘。\n");
	me->receive_damage("kee", 35);
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

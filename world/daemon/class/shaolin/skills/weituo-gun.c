// weituo-gun.c -韦陀棍

inherit SKILL;

mapping *action = ({
([	"action":"$N一招「黄石纳履」，手中$w如蜻蜓点水般，招招向$n的下盘要害点去",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "黄石纳履",
	"damage_type":"挫伤"
]),
([	"action":"$N把$w平提胸口，一拧身，一招「勒马停锋」，$w猛地撩向$n的颈部",
	"force" : 180,
        "dodge" : 5,
        "parry" : 10,
	"damage": 15,
	"lvl" : 8,
	"skill_name" : "勒马停锋",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「平地龙飞」，全身滴溜溜地在地上打个大转，举棍向$n的胸腹间戳去",
	"force" : 210,
        "dodge" : 5,
        "parry" : 15,
	"damage": 20,
	"lvl" : 16,
	"skill_name" : "平地龙飞",
	"damage_type":"挫伤"
]),
([	"action":"$N伏地一个滚翻，一招「伏虎听风」，$w挟呼呼风声迅猛扫向$n的足胫",
	"force" : 250,
        "dodge" : 15,
        "parry" : 5,
	"damage": 25,
	"lvl" : 25,
	"skill_name" : "伏虎听风",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「流星赶月」，身棍合一，棍端逼成一条直线，流星般向顶向$n的$l",
	"force" : 300,
        "dodge" : 20,
        "parry" : 15,
	"damage": 30,
	"lvl" : 35,
	"skill_name" : "流星赶月",
	"damage_type":"挫伤"
]),
([	"action":"$N双手持棍划了个天地大圈，一招「红霞贯日」，一棍从圆心正中击出，撞向$n的胸口",
	"force" : 350,
        "dodge" : 20,
        "parry" : 15,
	"damage": 35,
	"lvl" : 44,
	"skill_name" : "红霞贯日",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「投鞭断流」，$w高举，以雷霆万钧之势对准$n的天灵当头劈下",
	"force" : 410,
        "dodge" : 25,
        "parry" : 20,
	"damage": 40,
	"lvl" : 52,
	"skill_name" : "投鞭断流",
	"damage_type":"挫伤"
]),
([	"action":"$N潜运真力，一招「苍龙归海」，$w顿时长了数丈，矫龙般直射$n的胸口",
	"force" : 470,
        "dodge" : 30,
        "parry" : 25,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "苍龙归海",
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return  (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("weituo-gun", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握韦陀棍的奥秘。\n");
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
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练韦陀棍。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("weituo-gun", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握韦陀棍的奥秘。\n");
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

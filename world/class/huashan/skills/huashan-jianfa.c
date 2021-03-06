// huashan-jianfa.c 华山剑法
inherit SKILL;

mapping *action = ({
([	"action" : "$N一招「白云出岫」，手中$w点向$n的$l",
	"damage" : 20,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「有凤来仪」，$w闪烁不定，刺向$n的$l",
	"damage" : 25,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「天绅倒悬」，$w自上而下划出一个大弧，向$n劈砍下去",
	"damage" : 30,
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跨上一步，手中$w使出「白虹贯日」直刺$n的$l",
	"damage" : 35,
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，使出「苍松迎客」直刺$n的$l",
        "damage" : 50,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20 && (int)me->query_skill("huashan-neigong", 1) < 20)
                return notify_fail("你的内功等级太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 20)
		return notify_fail("你的体力不够练华山剑法。\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huashan-jianfa/" + action;
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

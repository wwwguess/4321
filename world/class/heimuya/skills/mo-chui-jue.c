// mo-chui-jue.c 魔锤诀

inherit SKILL;
inherit "/adm/daemons/weapond.c";

mapping *action = ({
([	"action" : "$N使一招「建业暮钟」，手中$w向$n的$l砸去",
	"force" : 220,
        "dodge" : -20,
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
	"lvl" : 0,
	"skill_name" : "建业暮钟",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「十年离乱」,$w一提一收,$w砸向$n的颈部",
	"force" : 230,
        "dodge" : -20,
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "十年离乱",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N$w一招「天地英雄」，砸向$n",
	"force" : 240,
        "dodge" : -25,
	"damage" : 15,
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
	"lvl" : 16,
	"skill_name" : "天地英雄",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N力贯$w，一招「千秋凛然」砸向$n的$l",
	"force" : 260,
        "dodge" : -25,
	"damage" : 25,
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
	"lvl" : 24,
	"skill_name" : "千秋凛然",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N手中$w一沉，一招「红叶萧萧」 ，当头砸向$n的胸口",
	"force" : 280,
        "dodge" : -20,
	"damage" : 30,
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
	"lvl" : 33,
	"skill_name" : "红叶萧萧",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「雷霆震怒鬼神惊」,$w挟万钧之势砸向$n",
	"force" : 300,
        "dodge" : -20,
	"damage" : 60,
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
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

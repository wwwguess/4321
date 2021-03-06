// mo-zhang-jue.c                 
//write by dfbb@hero
// date 1/25/97

inherit SKILL;

mapping *action = ({
([      "action": "$N使出一招「人生得意」，右掌穿出击向$n的$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形一晃，一招「烹羊宰牛」拍向$n的$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "瘀伤"
]),
([	"action": "$N右掌一招「金樽对月」，迅捷无比地劈向$n的$l",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage_type": "瘀伤"
]),
([	"action": "$N双掌施出一招「高堂明镜」，隐隐带着风声拍向$n的$l",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage_type": "瘀伤"
]),
([	"action": "$N剑眉一轩一招「会须一饮」缓缓推向$n的$l",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage_type": "瘀伤"
]),
([	"action": "$N施出一招「但愿长醉」，右掌插腰，左掌劈向$n的$l",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「奔流到海」，右掌从不可能的角度向$n的$l推出",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage_type": "瘀伤"
]),
([	"action": "$N大吼一声，双掌使出「黄河之水天上来」，不顾一切般击向$n",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("tianmo-dafa", 1) < 20)
                return notify_fail("你的天魔大法功力不够! n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 10)
		return notify_fail("你的内力不够练魔掌诀。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
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

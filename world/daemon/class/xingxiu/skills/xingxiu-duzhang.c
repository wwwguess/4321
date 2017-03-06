
// xingxiu-duzhang.c, based on xianglong-zhang.c
// by yucao

inherit SKILL;

mapping *action = ({
([      "action": "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
        "dodge": 30,
        "force": 160,
//      "poison": 80,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "dodge": 10,
        "force": 160,
//      "poison": 60,
        "damage_type": "瘀伤"
]),
([	"action": "$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
	"dodge": -20,
	"force": 150,
//      "poison": 100,
	"damage_type": "瘀伤"
]),
([	"action": "$N双掌挟着一股腥臭之气拍向$n的$l",
	"dodge": 10,
	"force": 160,
//      "poison": 80
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

mapping query_action(object me)
{
        if (random(me->query_skill("unarmed")) > 60 &&
            me->query_skill("force") > 50 &&
            me->query("force") > 100 ) {
                me->add("force", -100);
                return ([
                "action": "$N咬破舌尖，口中喷血，聚集全身的力量击向$n",
                "force": 300,
                "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练星宿毒掌必须空手。\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 10)
		return notify_fail("你的化功大法火候不够，无法练星宿毒掌。\n");
	if ((int)me->query("max_force") < 60)
		return notify_fail("你的内力太弱，无法练星宿毒掌");
	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 8)
		return notify_fail("你的内力不够练星宿毒掌。\n");
	if (me->query_skill("xingxiu-duzhang", 1) < 50)
		me->receive_damage("kee", 20);
	else
		me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
                //if( random(me->query_skill("huagong-dafa")) > (damage_bonus + foo)/3 )
	if( random(me->query_skill("huagong-dafa")) > 5) {
		//victim->receive_wound("kee", (damage_bonus + foo));
		victim->apply_condition("xx_poison", random(2) + 1 +
			victim->query_condition("xx_poison"));
	}
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

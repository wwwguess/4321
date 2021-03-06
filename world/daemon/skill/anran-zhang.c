// anran-zhang.c
//  created by diablo
inherit SKILL;

mapping *action = ({
([      "action": "$N目光呆滞，动作迟缓，一招「呆若木鸡」推向$n的$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形暴涨，左掌向下一招「杞人忧天」拍向$n的$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "瘀伤"
]),
([	"action": "$N右袖一拂，一招「徘徊空谷」，迅捷无比地抽向$n的$l",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage_type": "瘀伤"
]),
([	"action": "$N右手云袖飘动，宛若流水，施出一招「拖泥带水」，左掌凝重拍向$n的$l",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage_type": "瘀伤"
]),
([	"action": "$N身体僵直，左掌一招「行尸走肉」缓缓推向$n的$l",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage_type": "瘀伤"
]),
([	"action": "$N施出一招「庸人自扰」，左手插腰，右肩撞向$n的$l",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「穷途末路」，左掌从不可能的角度向$n的$l推出",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage_type": "瘀伤"
]),
([	"action": "$N大吼一声，使出「饮恨吞声」，不顾一切般击向$n",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「六神不安」，向$n的$l连拍数掌",
	"dodge": -20,
	"parry": -20,
	"force": 230,
	"damage_type": "瘀伤"
]),
([	"action": "$N凝神定气，左掌一撩，右袖一扫，一招「废寝忘食」一前一后按向$n的$l",
	"dodge": -10,
	"parry": 20,
	"force": 160,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「孤身只影」，身形笔直飞起，单掌向$n的$l劈下",
	"dodge": -20,
	"parry": 30,
	"force": 250,
	"damage_type": "瘀伤"
]),
([	"action": "$N脸上喜怒哀乐，怪状百出，使出「面无人色」向$n连砍数下",
	"dodge": -20,
	"parry": 20,
	"force": 270,
	"damage_type": "瘀伤"
]),
([	"action": "$N若有所思,一招「想入非非」，封住$n的退路，左掌斜斜地劈向$l",
	"dodge": -15,
	"parry": 20,
	"force": 220,
	"damage_type": "瘀伤"
]),
([	"action": "$N突然头下脚上，倒过身子，使出「倒行逆施」，一掌拍向$n的$l",
	"dodge": -25,
	"parry": 10,
	"force": 350,
	"damage_type": "瘀伤"
]),
([	"action": "$N脚下一转，突然欺到$n身前，一招「心惊肉跳」拍向$n的$l",
	"dodge": -20,
	"parry": 40,
	"force": 330,
	"damage_type": "瘀伤"
]),
([	"action": "$N门户大开，一招「力不从心」向$n的$l劈去",
	"dodge": -25,
	"parry": 1,
	"force": 320,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「无中生有」，竟然全身向$n的$l",
	"dodge": -15,
	"parry": 40,
	"force": 200,
	"damage_type": "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然销魂掌必须空手。\n");
	if ((int)me->query_skill("jiuyin", 1) < 20)
		return notify_fail("你的九阴神功的火候不够，无法练黯然销魂掌。\n");
        if ((int)me->query_skill("jiuyin", 1) < (int)me->query_skill("anran-zhang", 1) && (int)me->query_skill("jiuyin", 1) < 150)
                return notify_fail("你的九阴神功的火候不够，无法领悟黯然销魂掌的意境。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练黯燃销魂掌。\n");
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
		return notify_fail("你的内力不够练黯然销魂掌。\n");
        if ((int)me->query_skill("jiuyin", 1) < (int)me->query_skill("anran-zhang", 1) && (int)me->query_skill("jiuyin", 1) < 150)
                return notify_fail("你的九阴神功火候不够，无法领悟黯然销魂掌的意境。\n");
	me->receive_damage("kee", 30);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"anran-zhang/" + action;
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n化掌为刀，急切$N的手腕。\n"
        "$n双掌交错，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n双掌一划，引偏了$N的$w。\n",
        "$n步走七星，虚空拍出十三掌，逼得$N撤招自保。\n",
        "$n化掌为指，反点$N的周身要穴。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

// pudu-zhang.c 普渡杖法

inherit SKILL;

mapping *action = ({
([	"action":"$N使一招「黄牛转角」，手中$w自下而上，沉猛无比地向$n的小腹挑去。",
	"force" : 180,
        "dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "黄牛转角",
	"damage_type":"挫伤"
]),
([	"action":"$N快步跨出，一招「野马追风」，左手平托$w，右掌猛推杖端，顶向$n的胸口。",
	"force" : 200,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "野马追风",
	"damage_type":"挫伤"
]),
([	"action":"$N高举$w，一招「猛虎跳涧」，全身跃起，手中$w搂头盖顶地向$n击去。",
	"force" : 230,
        "dodge" : -5,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "猛虎跳涧",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「狮子摇头」，双手持杖如橹，对准$n猛地一搅，如同平地刮起一阵旋风。",
	"force" : 270,
        "dodge" : -10,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "狮子摇头",
	"damage_type":"挫伤"
]),
([	"action":"$N横持$w，一招「苍龙摆尾」，杖端化出无数个圆圈，凝滞沉重，把$n缠在其中。",
	"force" : 320,
        "dodge" : -15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "苍龙摆尾",
	"damage_type":"挫伤"
]),
([	"action":"$N全身滚倒，$w盘地横飞，突出一招「大蟒翻身」，杖影把$n裹了起来",
	"force" : 380,
        "dodge" : 5,
	"damage": 55,
	"lvl" : 45,
	"skill_name" : "大蟒翻身",
	"damage_type":"挫伤"
]),
([	"action":"$N双手和十，躬身一招「胡僧托钵」，$w自肘弯飞出，拦腰向$n撞去。",
	"force" : 450,
        "dodge" : -5,
	"damage": 55,
	"lvl" : 53,
	"skill_name" : "胡僧托钵",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「慈航普渡」，$w如飞龙般自掌中跃出，直向$n的胸口穿入。",
	"force" : 530,
        "dodge" : -5,
	"damage": 60,
	"lvl" : 60,
	"skill_name" : "慈航普渡",
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("pudu-zhang", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握普渡杖法的奥秘。\n");
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
	level   = (int) me->query_skill("pudu-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练普渡杖法。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("pudu-zhang", 1) - 20 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握普渡杖法的奥秘。\n");
	me->receive_damage("kee", 30);
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

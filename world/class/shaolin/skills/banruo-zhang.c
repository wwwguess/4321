
// banruo-zhang.c -般若掌

inherit SKILL;

mapping *action = ({
([	"action" : "$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
	"force" : 150,
        "dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "横空出世"
]),
([	"action" : "$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前大穴",
	"force" : 160,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 12,
	"skill_name" : "长虹贯日"
]),
([	"action" : "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
	"force" : 170,
        "dodge" : 5,
        "damage_type" : "劈伤",
	"lvl" : 18,
	"skill_name" : "云断秦岭"
]),
([	"action" : "$N左掌护胸，右拳凝劲后发，一式「铁索拦江」，缓缓推向$n的$l",
	"force" : 185,
        "dodge" : -5,
        "damage_type" : "瘀伤",
	"lvl" : 24,
	"skill_name" : "铁索拦江"
]),
([	"action" : "$N使一式「狂风卷地」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
	"force" : 200,
        "dodge" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 30,
	"skill_name" : "狂风卷地"
]),
([	"action" : "$N合掌抱球，猛吸一口气，一式「怀中抱月」，双掌疾推向$n的肩头",
	"force" : 220,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 36,
	"skill_name" : "怀中抱月"
]),
([	"action" : "$N向上高高跃起，一式「高山流水」，居高临下，掌力笼罩$n的全身",
	"force" : 240,
        "dodge" : 20,
        "damage_type" : "瘀伤",
	"lvl" : 42,
	"skill_name" : "高山流水"
]),
([	"action" : "$N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
	"force" : 270,
        "dodge" : 10,
        "damage_type" : "劈伤",
	"lvl" : 48,
	"skill_name" : "摘星换斗"
]),
([	"action" : "$N两掌上下护胸，一式「翻江搅海」，骤然化为满天掌雨，攻向$n",
	"force" : 310,
        "dodge" : 30,
        "damage_type" : "瘀伤",
	"lvl" : 54,
	"skill_name" : "翻江搅海"
]),
([	"action" : "$N一式「金刚伏魔」，双手合十，对着$n微微一揖，全身内劲如巨浪般汹涌而出",
	"force" : 360,
        "dodge" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 60,
	"skill_name" : "金刚伏魔"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="yizhi-chan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练般若掌必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学般若掌。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练般若掌。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("banruo-zhang", 1) - 10 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握般若掌的奥秘。\n");
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
	level = (int)me->query_skill("banruo-zhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练般若掌。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("banruo-zhang", 1) - 10 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握般若掌的奥秘。\n");
	me->receive_damage("kee", 25);
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

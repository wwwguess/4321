// qianye-shou.c -如来千叶手

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「南海礼佛」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
	"force" : 100,
        "dodge" : 10,
	"lvl" : 0,
	"skill_name" : "南海礼佛",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N侧身一晃，一式「金玉瓦砾」，左手拿向$n的肩头，右拳打向$n的胸口",
	"force" : 110,
        "dodge" : 10,
	"lvl" : 10,
	"skill_name" : "金玉瓦砾",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「人命呼吸」，右手环拢成爪，一出手就向扣$n的咽喉要害",
	"force" : 130,
        "dodge" : 20,
	"damage": 5,
	"lvl" : 20,
	"skill_name" : "人命呼吸",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚招，右掌直立，一式「镜里观影」，错步飘出，疾拍$n的面门",
	"force" : 160,
        "dodge" : 20,
	"damage": 10,
	"lvl" : 30,
	"skill_name" : "镜里观影",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「水中捉月」，左拳上格，右手探底突出，抓向$n的裆部",
	"force" : 200,
        "dodge" : 30,
	"damage": 15,
	"lvl" : 38,
	"skill_name" : "水中捉月",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双拳挥舞，一式「浮云去来」，两手环扣，拢成圈状，猛击$n的下颌",
	"force" : 250,
        "dodge" : 30,
	"damage": 20,
	"lvl" : 45,
	"skill_name" : "浮云去来",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「水泡出没」，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"force" : 310,
        "dodge" : 40,
	"damage": 25,
	"lvl" : 51,
	"skill_name" : "水泡出没",
        "damage_type" : "内伤"
]),
([	"action" : "$N双手抱拳，一式「梦里明明」，掌影翻飞，同时向$n施出九九八十一招",
	"force" : 380,
        "dodge" : 40,
	"damage": 30,
	"lvl" : 56,
	"skill_name" : "梦里明明",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「觉后空空」，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
	"force" : 460,
        "dodge" : 40,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "觉后空空",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="longzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练如来千叶手必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学如来千叶手。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("qianye-shou", 1) - 10 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握如来千叶手的奥秘。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练如来千叶手。\n");
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
	level   = (int) me->query_skill("qianye-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练如来千叶手。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < (int)me->query_skill("qianye-shou", 1) - 10 && (int)me->query_skill("hunyuan-yiqi", 1) < 180)
		return notify_fail("你的混元一气功火候不够，无法掌握如来千叶手的奥秘。\n");
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

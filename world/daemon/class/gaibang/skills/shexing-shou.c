// shexing-shou.c -蛇形刁手

inherit SKILL;

mapping *action = ({
([      "action" : "$N腾空飞起，一式「万蛇汹涌」，双手双腿齐出，令$n无可躲藏",
        "force" : 200,
        "dodge" : 30,
        "parry" : 30,
        "damage": 30,
        "lvl" : 100,
        "skill_name" : "万蛇汹涌",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N侧身一晃，一式「蛇馨青竹」，疾向$n的$l拍去",
        "force" : 180,
        "dodge" : 10,
        "parry" : 15,
        "damage": 20,
        "lvl" : 60,
        "skill_name" : "蛇磐青竹",
        "damage_type" : "瘀伤"
]),
 ([      "action" : "$N左手虚按，右手使一招「白蛇吐信」，向$n的$l插去",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage": 15,
        "lvl" : 50,
        "skill_name" : "白蛇吐信",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双拳挥舞，一式「蛇行鼠窜」，身行一晃，错步飘出，打向$n的$l",
        "force" : 100,
        "dodge" : 10,
        "parry" : 15,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "蛇行鼠窜",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手好似举杯，一式「杯弓蛇影」，右手缓缓推向$n的$l",
        "force" : 120,
        "dodge" : 30,
        "parry" : 20,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "杯弓蛇影",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N五指绽开，一式「画蛇添足」，疾向$n的$l拍去",
        "force" : 140,
        "dodge" : 10,
        "parry" : 5,
        "damage": 10,
        "lvl" : 30,
        "skill_name" : "画蛇添足",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「虎头蛇尾」，左手虚晃，右手猛地插往$n的$l",
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "damage": 5,
        "lvl" : 20,
        "skill_name" : "虎头蛇尾",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N单手突进，一式「灵蛇出洞」，直取$n的$l",
        "force" : 80,
        "dodge" : 10,
        "parry" : 5,
        "damage": 0,
        "lvl" : 10,
        "skill_name" : "灵蛇出洞",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="xianglong-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练蛇形刁手必须空手。\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 10)
                return notify_fail("你的混天气功火候不够，无法学蛇形刁手。\n");
        if ((int)me->query("max_force") < 50)
                return notify_fail("你的内力太弱，无法练蛇形刁手。\n");
        return 1;
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
        level   = (int) me->query_skill("shexing-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练蛇形刁手。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
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

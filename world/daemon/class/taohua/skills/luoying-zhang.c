// luoying-zhang.c -落英神剑掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N左指划圈，右掌向后一个甩劈，斩向$n的$l",
        "force" : 200,
        "dodge" : 50,
        "parry" : 30,
        "damage": 30,
        "lvl" : 100,
        "skill_name" : "江城飞花",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N虚步提腰，右手出指，急点$n的$l",
        "force" : 180,
        "dodge" : 40,
        "parry" : 15,
        "damage": 20,
        "lvl" : 60,
        "skill_name" : "雨急风狂",
        "damage_type" : "瘀伤"
]),
 ([      "action" : "$N向前跨上一步，右掌自上而下划出一个大弧，向$n的$l劈去",
        "force" : 160,
        "dodge" : 45,
        "parry" : 20,
        "damage": 15,
        "lvl" : 50,
        "skill_name" : "落英满天",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N纵身飘开数尺，右掌突然变指，戳向$n的$l",
        "force" : 100,
        "dodge" : 50,
        "parry" : 15,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "清风问莲",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N错步上前，右手淡淡地向$n的$l挥去",
        "force" : 120,
        "dodge" : 40,
        "parry" : 20,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "翠竹承霖",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右手平指，掌势如风，一气呵成横扫$n的腰间",
        "force" : 140,
        "dodge" : 350,
        "parry" : 5,
        "damage": 10,
        "lvl" : 30,
        "skill_name" : "露草拂霜",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N拔步挺腰，左手缓缓挥向$n的全身",
        "force" : 100,
        "dodge" : 30,
        "parry" : 10,
        "damage": 5,
        "lvl" : 20,
        "skill_name" : "败叶倾雪",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N回身拧腰，右手虚抱成圆，左指突然点向$n的$l",
        "force" : 80,
        "dodge" : 20,
        "parry" : 5,
        "damage": 0,
        "lvl" : 10,
        "skill_name" : "碧海连天",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="lanhua-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练落英神剑掌必须空手。\n");
        if ((int)me->query_skill("taohua-force", 1) < 20)
                return notify_fail("你的桃花内功功力不够，无法学落英神剑掌。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练落英神剑掌。\n");
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
        level   = (int) me->query_skill("luoying-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练落英神剑掌。\n");
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

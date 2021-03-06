// dugu-jiujian.c 独孤九剑

inherit SKILL;

mapping *action = ({
([      "action" : "$N斜斜得向$n的$1刺出一剑，所刺之出令人出乎意料。",
        "force" : 60,
        "dodge" : 10,
        "damage" : 85,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，右手$w平淡无奇的伸向$n的$l，根本无招可言。",
        "force" : 70,
        "dodge" : 10,
        "damage" : 105,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w突然撞向自己的$l，就在此时，一转向$n的$l挥去。",
        "force" : 70,
        "dodge" : 15,
        "damage" : 120,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N将手中$w舞成一片，直砍$n的$l",
        "force" : 100,
        "dodge" : 20,
        "damage" : 130,
        "lvl" : 30,
        "damage_type" : "砍伤"
]),
([      "action" : "$N突然将$w抛向空中，剑锋直向$n的$l刺去。$N跟上一步，又接住了$w。",
        "force" : 120,
        "dodge" : 20,
        "damage" : 150,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形急转，$w从一个不可思意的角度刺向$n的$l",
        "force" : 200,
        "dodge" : 30,
        "damage" : 150,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子一晃，抢步上前，出人意料的将$w交给左手，右食指点向$n的$l",
        "force" : 250,
        "dodge" : 40,
        "damage" : 180,
        "lvl" : 100,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右腿半屈般蹲，剑尖虚指，转身撩向$n的$l",
        "force" : 300,
        "dodge" : 40,
        "damage" : 200,
        "lvl" : 120,
        "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，$w中宫直进，刺向$n的$l",
        "force" : 350,
        "dodge" : 50,
        "damage" : 280,
        "lvl" : 150,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") ; }

int valid_learn(object me)
{
        if(me->query("family/master_id")!="feng qingyang")
                return notify_fail("独孤九剑只能向风清扬学。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("dugu-jiujian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练独孤九剑。\n");
        me->receive_damage("kee", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dugu-jiujian/" + action;
}


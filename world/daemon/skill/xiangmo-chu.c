//xiangmo-chu.c -降魔杵

#include <combat.h>

inherit SKILL;
inherit "/adm/daemons/weapond.c";

mapping *action = ({
([      "action" : "$N力贯$w，点点杵影飘浮不定地点向$n的$l",
        "force" : 60,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 0,
                "damage_type":  "挫伤",
]),
([      "action" : "$N手中$w一沉，当头一立抽向$n的胸口",
        "force" : 80,
        "dodge" : 10,
        "damage" : 30,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 16,
                "damage_type":  "挫伤",
]),
([      "action" : "$N挥舞$w，化出一个大弧，齐齐罩向$n",
        "force" : 110,
        "dodge" : 15,
        "damage" : 35,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 32,
                "damage_type":  "挫伤",
]),
([      "action" : "$N$w从一个怪异的角度砸向$n的$l",
        "force" : 140,
        "dodge" : 5,
        "damage" : 50,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 41,
                "damage_type":  "挫伤",
]),
([      "action" : "$N$w如虹，向$n的全身涌去",
        "force" : 180,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 55,
                "damage_type":  "挫伤",
]),
([      "action" : "$N手中$w一沉，当头砸向$n的胸口",
        "force" : 220,
        "dodge" : -20,
        "damage" : 70,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 70,
                "damage_type":  "挫伤",
]),
([      "action" : "$N手中$w挟雷霆万钧之势砸向$n",
        "force" : 300,
        "dodge" : -20,
        "damage" : 90,
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 90,
                "damage_type":  "挫伤",
]),
});

int valid_enable(string usage) { return usage == "pestle" || usage == "parry"; }

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
        level   = (int) me->query_skill("xiangmo-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "halberd")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练吕家戟。\n");
        me->receive_damage("kee", 25);
        return 1;
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕刺去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手刺出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，手中$v猛击$N的手腕。\n",
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

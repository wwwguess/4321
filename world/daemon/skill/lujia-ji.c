//lujia-ji.c -吕家戟

inherit SKILL;
inherit "/adm/daemons/weapond.c";

mapping *action = ({
([      "action" : "$N手中$w斜指，戟作刀形，一戟向$n的$l撩去",
        "force" : 120,
        "dodge" : -10,
        "lvl" : 0,
        "damage_type" : "割伤"
]),
([      "action" : "$N将$w一抖，刺向$n的颈部",
        "force" : 130,
        "dodge" : -10,
        "damage" : 5,
        "lvl" : 8,
        "damage_type" : "刺伤"
]),
([      "action" : "$N大喝一声！将$w从上而下，劈向$n",
        "force" : 140,
        "dodge" : -5,
  	"damage" : 15,
	"post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 16,
        "damage_type" : "割伤"
]),
([      "action" : "$N$w大开大阖，自下而上划出一个大弧，笔直撩向$n",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
	"post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 24,
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，双手持$w拦腰反切，削向$n的$l",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，无边无际的戟影捅向$n",
        "force" : 210,
  	"dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w如影随形，挟烈烈风声劈向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
	"post_action":  (: call_other, __FILE__, "bash_weapon" :),
        "lvl" : 51,
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w戟光如雪，向$n的全身捅去",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage == "halberd" || usage == "parry"; }

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
        level   = (int) me->query_skill("lujia-ji",1);
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

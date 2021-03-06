//liuhe-dao.c -六合刀

inherit SKILL;

mapping *action = ({
([      "action" : "$N展身虚步，提腰跃落，一招「阴阳隔阂」，刀锋一卷，拦腰斩向$n",
        "force" : 140,
        "dodge" : -5,
        "damage" : 15,
        "lvl" : 0,
        "skill_name" : "阴阳隔阂",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「和合六出」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
        "force" : 160,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 24,
        "skill_name" : "和合六出",
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，一招「离合无常」，双手持刃拦腰反切，砍向$n的胸口",
        "force" : 180,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 33,
        "skill_name" : "离合无常",
        "damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，使出一招「天地乍合」，上劈下撩，左挡右开，齐齐罩向$n",
        "force" : 210,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 42,
        "skill_name" : "天地乍合",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「气盖河山」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 51,
        "skill_name" : "气盖河山",
        "damage_type" : "割伤"
]),
([      "action" : "$N盘身驻地，一招「呵壁问天」，挥出一片流光般的刀影，向$n的全身涌去",
        "force" : 280,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 60,
        "skill_name" : "呵壁问天",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="dagou-bang"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 10)
                return notify_fail("你的混天气功火候太浅。\n");
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
        level   = (int) me->query_skill("liuhe-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练六合刀。\n");
        me->receive_damage("kee", 25);
        return 1;
}

string *parry_msg = ({
        "$n用手中的$v急削$N的五指。\n",
        "$n左脚踏前一步，手中的$v从侧面飘向$N之必救。\n",
        "$n手中的$v一抖，挽出一片刀花，撒向$N的全身。\n",
        "$n微退一步，手中的$v划出一条光弧，将$N的全身围住。\n",
	"$n手中的$v一抖，直奔$N。\n",
	"$n手中的$v划出将$N的全身围住。\n",
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

// mo-dao-jue.c 魔刀诀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「平沙莽莽」，刀法如水，一刀向$n的$l撩去",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "平沙莽莽",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「走马川行 」,$w一提一收，平刃挥向$n的颈部",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "走马川行",
	"damage_type" : "割伤"
]),
([	"action" : "$N刀光不定, 一招「抽刀断水」，刀锋一立，劈向$n",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "抽刀断水",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「风头如刀」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "风头如刀",
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「三军大呼 」 ，双手持刃拦腰反切，砍向$n的胸口",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "三军大呼",
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「北风卷地」，上劈下撩，左挡右开，齐齐罩向$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
	"skill_name" : "北风卷地",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「风掣红旗」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "风掣红旗",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「一川碎石大如斗」,一片雷霆般的刀光，向$n的全身涌去",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "一川碎石大如斗",
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("tianmo-dafa", 1) < 20)
                return notify_fail("你的天魔大法功力不够! n");
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
	level   = (int) me->query_skill("mo-dao-jue",1);
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
		return notify_fail("你的体力不够练魔刀诀。\n");
	me->receive_damage("kee", 25);
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

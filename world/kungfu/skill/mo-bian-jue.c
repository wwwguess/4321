// mo-bian-jue.c 魔鞭诀

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「杜鹃啼血」，手中$w抖得笔直向$n的$l连刺数鞭",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "杜鹃啼血",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「黄芦苦竹」,$w一提一收,$w挥向$n的颈部",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
	"skill_name" : "黄芦苦竹",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N$w变换不定, 一招「梦啼妆泪」，抽向$n",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "梦啼妆泪",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N力贯$w，一招「阴风惨澹」点点鞭影飘浮不定地点向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "阴风惨澹",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N手中$w一沉，一招「少妇断肠」 ，当头一立抽向$n的胸口",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
	"skill_name" : "少妇断肠",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N挥舞$w，使出一招「一曲红绡」 ，化出一个大弧，齐齐罩向$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
	"skill_name" : "一曲红绡",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「幽咽泉流」，$w从一个怪异的角度抽向$n的$l",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "幽咽泉流",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「此恨绵绵无绝期」,$w如虹，向$n的全身涌去",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "此恨绵绵无绝期",
	"damage_type" : "鞭伤"
]),
});


int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-bian-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练魔鞭诀.\n");
	me->receive_damage("kee", 25);
	return 1;
}

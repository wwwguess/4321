// yuenv-jian.c 越女剑法 based on taiji-jian.c
// by tang

inherit SKILL;

mapping *action = ({
([	"action" : "$N轻舒手臂，一招「玉女投梭」，手中$w向$n的$l刺去",
	"force" : 100,
	"dodge" : 30,
	"damage" : 30,
        "lvl" : 5,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「一笑倾城」，$w一扬，向$n的$l刺去。",
	"force" : 130,
	"dodge" : 25,
	"damage" : 40,
        "lvl" : 15,
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w虚点，一招「再笑倾国」，攻向$n的$l。",
	"force" : 160,
	"dodge" : 20,
	"damage" : 40,
        "lvl" : 25,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「幽谷佳人」，$w上挑，刺向$n的腹部。",
	"force" : 190,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 35,
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w轻轻颤动，一招「风摆杨柳」，刺向$n的$l",
	"force" : 220,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 45,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「荡舟西湖」，$w一抖，向$n的$l刺去",
	"force" : 250,
	"dodge" : 5,
	"damage" : 70,
        "lvl" : 55,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出一招「红颜薄命」，$w向$n的颈部抹去",
	"force" : 280,
	"dodge" : -5,
	"damage" : 80,
        "lvl" : 65,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「西子捧心」，$w回抽，反手向$n的$l刺去",
	"force" : 310,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 75,
	"damage_type" : "刺伤"
]),
([  "action" : "$N腾身跃起，$w挽了一个剑花，一招「凤舞九天」，向$n当头刺下",
	"force" : 340,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 85,
	"damage_type" : "刺伤"
]),

});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("sunv-xinfa", 1) < 20)
		return notify_fail("你的素女心法火候太浅。\n");
        	if ((int)me->query_skill("sunv-xinfa", 1) < (int)me->query_skill("yuenv-jian", 1) - 20 && (int)me->query_skill("sunv-xinfa", 1) < 200)
		return notify_fail("你的素女心法火候不够，无法领悟越女剑法更高深的招术.\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("yuenv-jian",1);
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
		return notify_fail("你的体力不够练越女剑法。\n");
        	if ((int)me->query_skill("sunv-xinfa", 1) < (int)me->query_skill("yuenv-jian", 1) - 100 && (int)me->query_skill("literate", 1) < 250)
                	return notify_fail("你的素女心法与读书写字火候不够，无法领悟越女剑法更高深的招术.\n");
	me->receive_damage("kee", 30);
	return 1;
}

string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n使出越女剑法「卸」字诀，$v轻轻一点，$N的$w好象打在棉絮中，对$n毫无伤害。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
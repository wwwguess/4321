// tangshi-jian.c 唐诗剑法 based on taiji-jian.c
// by tang

inherit SKILL;

mapping *action = ({
([	"action" : "$N虚步提腰，一招「马鸣风萧萧」，手中$w轻轻颤动，一剑点向$n的$l",
	"force" : 100,
	"dodge" : 40,
	"damage" : 25,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跨上一步，左手捏个剑诀，右手$w使出一式「忽听闻惊风」直刺$n的$l",
	"force" : 120,
	"dodge" : 35,
	"damage" : 30,
        "lvl" : 5,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「功盖三分国」，一抖$w，$w一化为三，刺向$n的$l",
	"force" : 140,
	"dodge" : 30,
	"damage" : 30,
        "lvl" : 10,
	"damage_type" : "刺伤"
]),
([	"action" : "$N足踏八卦，一招「名成八阵图」，$w一扬，向$n的$l刺去。",
	"force" : 160,
	"dodge" : 25,
	"damage" : 35,
        "lvl" : 15,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「明月松间照」，$n只觉得眼前剑光大盛，$w罩住了全身。",
	"force" : 180,
	"dodge" : 20,
	"damage" : 35,
        "lvl" : 20,
	"damage_type" : "刺伤"
]),
([	"action" : "$N身子左转，右脚虚点，右手$w交于左手，右手$w交于左手，一招「清泉石上流」，攻向$n的$l。",
	"force" : 200,
	"dodge" : 20,
	"damage" : 40,
        "lvl" : 25,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「千山鸟飞绝」，$w平推，向$n的头部削去。",
	"force" : 220,
	"dodge" : 15,
	"damage" : 45,
        "lvl" : 30,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左腿半屈，一招「万径人踪灭」，$w下削，刺向$n的腿部。",
	"force" : 240,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 35,
	"damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，左手虚指，一招「海上升明月」，$w大起大落，砍向$n的$l。",
	"force" : 260,
	"dodge" : 15,
	"damage" : 55,
        "lvl" : 40,
	"damage_type" : "刺伤"
]),
([	"action" : "$N深吸一口气，一招「天涯共此时」，举起手中$w刺向$n的$l",
	"force" : 280,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 45,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出一式「红豆生南国」，手中$w径奔$n的$l",
	"force" : 300,
	"dodge" : 10,
	"damage" : 65,
        "lvl" : 50,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「春来发几枝」，一抖$w，$w化为几道光芒，向$n的头部各处插去",
	"force" : 310,
	"dodge" : 10,
	"damage" : 70,
        "lvl" : 55,
	"damage_type" : "刺伤"
]),
([	"action" : "$N倒踩七星，手中$w一招「北斗七星寒」，向$n的$l斜斜刺去。",
	"force" : 320,
	"dodge" : 5,
	"damage" : 75,
        "lvl" : 60,
	"damage_type" : "刺伤"
]),
([	"action" : "$N抡起$w使出「哥舒夜带刀」向$n猛地剁了下去",
	"force" : 330,
	"dodge" : 5,
	"damage" : 80,
        "lvl" : 65,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左手虚指，右腿微抬，右手$w一招「东风不与周郎便」，攻向$n的$l。",
	"force" : 340,
	"dodge" : 5,
	"damage" : 85,
        "lvl" : 70,
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w回扫，一招「铜雀春深锁二乔」，反手勾向$n的$l",
	"force" : 350,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 75,
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w画出一道弧线，左掌拍出，一招「二十四桥明月夜」，攻向$n的$l",
	"force" : 360,
	"dodge" : -5,
	"damage" : 95,
        "lvl" : 80,
	"damage_type" : "刺伤"
]),
([  "action" : "$N左手虚抱，一招「玉人何处教吹箫」，$w中宫直进，刺向$n的$l",
	"force" : 370,
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
	if ((int)me->query_skill("tangmen-xinfa", 1) < 20)
		return notify_fail("你的唐门心法火候太浅。\n");
        	if ((int)me->query_skill("tangmen-xinfa", 1) < (int)me->query_skill("tangshi-jian", 1) - 20 && (int)me->query_skill("literate", 1) < 250)
		return notify_fail("你的唐门心法与读书写字火候不够，无法领悟唐诗剑法更高深的招术.\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tangshi-jian",1);
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
		return notify_fail("你的体力不够练唐诗剑法。\n");
        	if ((int)me->query_skill("tangmen-xinfa", 1) < (int)me->query_skill("tangshi-jian", 1) - 20 && (int)me->query_skill("literate", 1) < 250)
                	return notify_fail("你的唐门心法与读书写字火候不够，无法领悟唐诗剑法更高深的招术.\n");
	me->receive_damage("kee", 30);
	return 1;
}

//string perform_action_file(string action)
//{
//	return __DIR__"taiji-jian/" + action;
//}

string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n使出唐诗剑法「卸」字诀，$v轻轻一点，$N的$w好象打在棉絮中，对$n毫无伤害。\n",
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
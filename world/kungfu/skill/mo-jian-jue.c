// mo-jian-jue.c 魔剑诀

inherit SKILL;

mapping *action = ({
(["action":"$N使一式「孤鸿海上来」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force" : 120,
        "dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "孤鸿海上来",
	"damage_type":	"刺伤"
]),
(["action":"$N错步上前，使出「山月随人归」，剑气如水，$w无孔不入地向$n的$l挥去",
	"force" : 140,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "山月随人归",
	"damage_type":	"割伤"
]),
([	"action":"$N一式「曲尽河星稀」，剑气暴长,手中$w遥摇划向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "曲尽河星稀",
	"damage_type":	"割伤"
]),
([	"action":"$N纵身轻轻跃起，一式「春风不相识」剑光如轮疾转，霍霍斩向$n的$l",
	"force" : 180,
        "dodge" : 10,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "春风不相识",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w中宫直进，一式「世事两茫茫」，无声无息地对准$n的$l刺出一剑",
	"force" : 220,
        "dodge" : 15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "世事两茫茫",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式「浮云终日行」 ，对准$n的$l斜斜击出",
	"force" : 220,
        "dodge" : 5,
	"damage": 45,
	"lvl" : 44,
	"skill_name" : "浮云终日行",
	"damage_type":	"刺伤"
]),
([	"action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「置酒长安道」刺向$n的$l",
	"force" : 260,
        "dodge" : 5,
	"damage": 55,
	"lvl" : 52,
	"skill_name" : "置酒长安道",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「天寒翠袖薄」，$w由下至上，如疾电般射向$n的胸口",
	"force" : 280,
        "dodge" : 5,
	"damage": 60,
	"lvl" : 60,
	"skill_name" : "天寒翠袖薄",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

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
	level   = (int) me->query_skill("mo-jian-jue",1);
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
		return notify_fail("你的体力不够练魔剑诀!\n");
	me->receive_damage("kee", 25);
	return 1;
}

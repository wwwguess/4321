// tiannv-sanhua.c 天女散花

inherit SKILL;

int valid_enable(string usage) { return usage == "throwing"; }

int valid_learn(object me)
// need more limit here
{
	if ((int)me->query_skill("throwing", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	return 1;
}
                                                             
int practice_skill(object me)
{
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练天女散花。\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string func)
{
        return __DIR__"tainnv-sanhua/" + func;
} 
// sunv-xinfa.c 素女心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{                                             
	if ((string)me->query("gender")=="女性")
	{
		if ((int)me->query_skill("force", 1) < 10)
			return notify_fail("你的基本内功火候还不够。\n");
		return 1;
	}
	return notify_fail("女性才能学素女心法。\n");
}

int practice_skill(object me)
{
        return notify_fail("素女心法只能用学(learn)的来增加熟练度。\n");
}


string exert_function_file(string func)
{
        return __DIR__"sunv-xinfa/" + func;
} 
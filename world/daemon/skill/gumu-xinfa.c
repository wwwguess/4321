inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	return 1;
}

int practice_skill(object me)
{
        return notify_fail("古墓心法只能用学(learn)的来增加熟练度。\n");
}


string exert_function_file(string func)
{
        return "/open/diablo/skills/gumu-xinfa/" + func;
}

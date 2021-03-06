// tianmo-dafa.c 天魔大法
// dfbb@hero

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会天魔大法。\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail(" 天魔大法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"tianmo-dafa/" + func;
}

int help(object me)
{
        write(@HELP
	天魔大法是日月神教第十一代教主穷毕生之力创制
	它上手快,威力大,是本教的基本心法.
	它的最大秘密就是可以天魔解体(jie ti)
	当你身受重伤时, 施行解体大法后虽然真元大受损害
	却能大幅提升战力.只是时效甚短
HELP
        );
        return 1;
}


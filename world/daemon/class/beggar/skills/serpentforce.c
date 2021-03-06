// serpentforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	if( !environment(me)->query("resource/water") )
		return notify_fail("伏蛟功\只能在有水的地方练。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的气不够。\n");
	if( (int)me->query("force") < 30 )
		return notify_fail("你的内力不够");
	me->receive_damage("kee", 30);
	me->add("force", -30);

	write("你深深的吸了一口气，将头伸进水里依照所学的心法练起伏蛟功\。\n");
	
	if( random(me->query("kee")) < (int)me->query_skill("serpentforce") ) {
		me->set("water", me->max_water_capacity());
		return notify_fail("但是你心神一分，喝了一肚子水。\n");
	}

	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("beggar") + "/serpentforce/" + func;
}

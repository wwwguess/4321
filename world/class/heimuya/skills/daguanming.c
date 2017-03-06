// daguanming.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("daguanming", 1);
	
	if( (int)me->query("shen") > 100 )
	return notify_fail("你的正气太重，无法修炼大光明心法。\n");
		
	if(me->query("gender") == "无性" && lvl > 39)
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。\n");
		
	if(me->query("family/family_name")!="日月神教")
		return notify_fail("哈哈！"+RANK_D->query_respect(me)
			+"你这个正派中的狗贼,想死啊？\n");
		
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("大光明心法只能靠学习来提高。\n");
}

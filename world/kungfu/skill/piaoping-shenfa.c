//piaoping-shenfa.c 
//□飘萍身法 
//dfbb@hero


inherit SKILL;

string *dodge_msg = ({
	"$n一招「风吹飘萍」轻轻松松地避了开去。\n",
	"只见$n身形一转一式「每逐青溪水」早已闪开$N的攻击。\n",
	"$n使出「言入黄花川」身形微动，$N又扑了个空。\n",
	"$n左足一退右足一分，一招「漾漾泛菱荇」已避了开去。\n",
	"可是$n使一招「清川澹如此」身子象轻纱一样飘了开去。\n",
	"$n下身不动，上身轻侧已经藉一招「清辉淡水木」轻轻闪过。\n",
	"但是$n一招「幽意无断绝」使出,竟然绕到$N身後！\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("literate", 1) < 50 )
		return notify_fail("你的文学素养不够没有办法练飘萍身法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 80
	||	(int)me->query("gin") < 80 )
		return notify_fail("你的精神不足不能练飘萍身法。\n");
	me->receive_damage("kee", 10);
	me->receive_damage("sen", 10);
	me->add("force", 3);
	return 1;
}


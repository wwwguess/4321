// sttormdance.c

inherit SKILL;

string *dodge_msg = ({
	"$n一招「嫦娥奔月」，轻轻一纵优雅的自$N头顶越过！\n",
	"$n一式「天女散花」，自水袖中散出一片花雨，$N被花影迷蒙了双眼，与$n擦肩而过！\n",
	"$n使出「织女于归」，突然幻化成一双倩影，$N从其中一人透体而过！\n",
	"$n双脚微动翩然起舞，一招「双成献舞」，堪堪闪过$N的这招！\n",
	"但$n一式「蕙芳下凡」随著轻轻一叹，顺著$N的招式飘出六尺之外！\n"
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	if( (string)me->query("gender") != "女性" )
		return notify_fail("七宝天岚舞只有女性才能练。\n");
	if( (int)me->query("spi") < 20 )
		return notify_fail("你的灵性不够，没有办法练七宝天岚舞。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练七宝天岚舞。\n");
	me->receive_damage("sen", 30);
	return 1;
}

void skill_improved(object me)
{
	if( (int)me->query("per") < (int)me->query_skill("stormdance", 1)/3 ) {
		tell_object(me, "你从七宝天岚舞的舞姿中体会到了一些心境，变化了你的气质...\n");
		me->add("per", 1);
	}
}

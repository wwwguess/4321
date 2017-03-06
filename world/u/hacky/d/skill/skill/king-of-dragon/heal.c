// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if ( !wizardp(me)) return 0 ;
	write( HIY "你全身放松，坐下来开始运功疗伤。\n" NOR);
	message("vision",
		HIY + me->name() + "吐出一口金灿灿的血，脸色立刻恢复了正常。\n" NOR,
		environment(me), me);

	me->set("eff_qi", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("eff_jing", (int)me->query("max_gin"));
	me->set("gin", (int)me->query("max_gin"));
	me->set("force", (int)me->query("max_force"));
	me->set("jingli", (int)me->query("max_jingli"));
	return 1;
}


#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int i,force,damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("唱仙法只能在战斗中使用。\n");

	if( (int)me->query_skill("shedao-qigong", 1) < 100 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法吼字决。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");

	if( (int)me->query("force") < 500 )
		return notify_fail("你已经唱得精疲力竭,内力不够了。\n");


	force = me->query("force");

	me->add("force", -(300+random(200)));
	me->receive_damage("kee", 10);

	me->start_busy(random(5));

	message_vision(
		HIY "$N深深地吸一囗气，忽然仰天长啸，高声狂叫：不死神龙，唯我不败！\n" NOR, me);

		if( force/2 + random(force/2) < (int)target->query("force")/10) 
		return notify_fail("敌人的内力比你高出太多,伤不了！\n");
		
		damage = (force - (int)target->query("max_force")) / 10;
		if( damage > 0 ) {
			target->receive_damage("gin", damage);
			target->receive_damage("kee", damage);
			target->receive_wound("kee", damage);
			target->receive_wound("kee", damage);
		message_vision(
		HIR "$N只觉脑中一阵剧痛，金星乱冒，犹如有万条金龙在眼前舞动。\n" NOR, target);
		}
		else
		{
		message_vision(
		HIR "$N只觉脑中微痛，似乎受了一点轻伤。\n" NOR, target);
		target->receive_damage("gin", 10 );
		target->receive_damage("kee", 10 );
		target->receive_wound("kee", 10);
		}
		if( !target->is_killing(me) ) target->kill_ob(me);
		if( !me->is_killing(target) ) me->fight_ob(target);

	return 1;
}

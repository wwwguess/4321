// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if ( !wizardp(me)) return 0 ;
	write( HIY "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
	message("vision",
		HIY + me->name() + "�³�һ�ڽ�Ӳӵ�Ѫ����ɫ���ָ̻���������\n" NOR,
		environment(me), me);

	me->set("eff_qi", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("eff_jing", (int)me->query("max_gin"));
	me->set("gin", (int)me->query("max_gin"));
	me->set("force", (int)me->query("max_force"));
	me->set("jingli", (int)me->query("max_jingli"));
	return 1;
}

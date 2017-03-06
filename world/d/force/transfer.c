// transfer.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
	int A, B, force, forceme;

	// Don't let player order NPC to exert transfer on them.
	if( !userp(me) ) return 0;

	if( !target || target==me || !living(target) )
		return notify_fail("��Ҫ����������˭��\n");

	if( (string)me->query_skill_mapped("force") != target->query_skill_mapped("force") )
		return notify_fail(target->name() + "��ʹ�õ��ڹ�\���㲻ͬ��\n");

        if( (int)me->query("max_force") < (int)target->query("max_force") )
                return notify_fail("�Է������������, ��ʡʡ�ɡ�\n");

	if( (int)me->query("force") <= (int)me->query("max_force") )
		return notify_fail("��û���㹻����������������\n");

	if( (int)me->query("max_force") < 100 ) return notify_fail("����������㡣\n");

	me->add("max_force", -100);
        forceme = me->query("max_force");
        me->set("force", forceme / 3);
	message_vision("$N����������$n���ģ���ʼ�������������ע��$n���ڡ�\n", me, target);

        A = me->query_skill("force");
        B = target->query_skill("force");
        force = target->query("max_force");

	if( random(100) < ((A+B)/2)/((A-B)+1) )
          {
           message_vision("$n�ܲ���ǿ�������ĳ弤, ���˹�ȥ��\n", me, target);
           target->add("max_force", - force / 3 );
           target->set("force", 0);
           target->unconcious();
           return 1;
          }

        target->add("max_force", 60);
	write("Ok.\n");
	tell_object(target, HIY "�����һ��������" + me->name() + "�����ƴ��˹�����\n" NOR);

        if(userp(target)) log_file("static/TRANSFER", 
           sprintf("%s transfer force to %s on %s.\n", geteuid(me), geteuid(target), ctime(time()) ) );

	return 1;
        
}

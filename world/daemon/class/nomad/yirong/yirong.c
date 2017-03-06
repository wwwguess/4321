// yirong.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, object target);

void remove_effect(object me, object target)
{
	this_player()->set("id", me->query("id"));
	this_player()->set("name", me->query("name"));
        me->delete_temp("yirong");
}

int perform(object me, object target)
{
	string target_id;
	object ob;
	int skill;

	if ( !target )  {
		if (target_id = me->query("env/yi_target")) {
			ob = new (LOGIN_OB);
			ob->set("id", target_id);
			if ( !ob->restore())
				return notify_fail("û������˰�����Ҫ��װ��˭��ģ����\n");
			target = ob;
			}
		    else 
			return notify_fail("��Ҫ��װ��˭��ģ����\n");
		}
	
	ob = me;

	if ( !target || me->is_busy() ) 
		return notify_fail ("����æ���أ����п����ݣ�\n");

	if ( random (skill = me->query_skill("yirong") ) > 35 ) {
		me->set("id", target->query("id"));
		me->set("name", target->query("name"));
                me->set("yirong",1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", ob, me :), 2/*random(skill/10)*/ );
		
		return 1;
		}
	
	return 0;
}

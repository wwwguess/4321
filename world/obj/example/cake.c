// cake.c

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ES2 �������յ���", ({ "cake" }) );
	set_weight(160);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��ף ES2 �������������Ƶ��ش�ŵ��⡣\n");
		set("unit", "��");
		set("food_remaining", 99);
		set("food_supply", 100);
	}
}

void init()
{
	add_action("do_throw", "throw");
	::init();
}

int do_throw(string arg)
{
	string what, who, msg;
	object target;

	if( !arg || arg=="" || sscanf(arg, "%s at %s", what, who)!=2)
		return notify_fail("ָ���ʽ��throw <what> at <who>\n");
	if( !id(what) ) return notify_fail("��ʲ�᣿\n");
	target = present(who, environment(this_player()));
	if( !target || !target->is_character() )
		return notify_fail("��Ҫ��˭�����⣿\n");
	msg = HIY "$N����" + name() + "���ڿ��л���һ��Ư���Ļ��ߡ�������$n�ı��ӣ�\n\n";
	if( wiz_level(this_player()) < random(wiz_level(target)) )
		msg += "����û�� .... �����������ǵ����Լ��㿪�ˡ�\n\n" NOR;
	else
		msg += "��ž����һ�������к��ģ���ˬ ....\n\n" NOR;
	message_vision(msg, this_player(), target);
	destruct(this_object());
	return 1;
}


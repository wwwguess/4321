// gao.c ��ҩ
//created by kiss
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"��������"NOR, ({"tianxiang gao", "gao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������˵���ҩ��\n");
        set("value",100000);
	}
	setup();
}

int do_eat(string arg)
{
         object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if(this_player()->is_fighting())
		return notify_fail("ս���в��ܷ�ҩ��\n");
	if ((int)this_player()->query("eff_kee") == 
	    (int)this_player()->query("max_kee"))
		return notify_fail("�����ڲ���Ҫ���������ࡣ\n");
	else {
              me->set("eff_kee", (int)me->query("max_kee"));
              me->set("kee", (int)me->query("max_kee"));  		
                message_vision(GRN "$N����һ���������࣬��ɫ�������ö��ˡ�\n" NOR, this_player());
		destruct(this_object());
		return 1;
	}
}


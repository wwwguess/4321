// jinchuang.c ��ҩ
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
	set_name("��ҩ", ({"jinchuang yao", "jin", "jinchuang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n");
        set("value", 2500);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if(this_player()->is_fighting())
		return notify_fail("ս���в��ܷ�ҩ��\n");
	if ((int)this_player()->query("eff_kee") == 
	    (int)this_player()->query("max_kee"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	else {
		this_player()->receive_curing("kee", 50);
                message_vision(GRN "$N����һ����ҩ����ɫ�������ö��ˡ�\n" NOR, this_player());
		destruct(this_object());
		return 1;
	}
}


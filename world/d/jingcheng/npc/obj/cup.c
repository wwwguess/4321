// cup.c 

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"��䱭"NOR, ({ "feicui cup", "cup" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", CYN"����һ����������ɵľƱ����󸻺�����ƿͶ�ϲ������ʢ�ơ�\n
�����ƣ���������ҹ�Ɑ������ָ���ˡ�\n"NOR);
		set("value", 100000);
		set("material", "greysteal");
		set("no_get",0);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}


// slipcase.c

inherit ITEM;

void create()
{
	object obj;
	set_name("��ϻ", ({ "slipcase" }) );
	set_weight(4000);
    set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "����һ��ͭ�Ƶ���ϻ����������װһЩ�顣\n");
		set("value", 1);
	}
	obj=new(__DIR__"parry_book");
	obj->move(this_object());
}

int is_container() { return 1; }

// maintal.c

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("��ͷ", ({ "maintal" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ�������硢�����ڵĴ���ͷ��\n");
		set("unit", "��");
		set("value", 15);
        set("food_remaining", 4);
        set("food_supply", 50);
	}
}

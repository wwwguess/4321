// zhutou.c ��ͷ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ͷ��", ({ "zhu tourou", "tourou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һƬѪ���ܵ���ͷ�⡣\n");
		set("unit", "Ƭ");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
	setup();
}


// zasui.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({ "fragment" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "���ԳԵ�����\n");
		set("unit", "��");
		set("value", 50);
       		set("food_remaining", 2);
		set("food_supply", 30);
        	set("material", "blood");
	}

	setup();
}


// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("老白干", ({ "lbgwine", "wnie" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓶酒味扑鼻、香气四溢的老白干\n");
		set("unit", "瓶");
		set("value", 30);
		set("max_liquid", 10);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "老白干",
		"remaining": 15,
		"drunk_apply": 4,
	]) );
}

// stone.c

inherit ITEM;

void create()
{
	set_name("黑妖石", ({ "stone" }) );
	set_weight(100);
	set("unit", "个");
	set("long", "一颗毫不起眼的石头，黑黝黝地像是煤块。\n");
	set("value", 10);
}

void init()
{
	object env;

	env = environment();
	if( this_player()==env ) call_out( "more_heavy", 100 );
	else remove_call_out("more_heavy");
}

void more_heavy()
{
	set_weight( weight() * 2 );
	tell_object( environment(), "你觉得黑妖石颤动了一下，重量又变重了。\n");
	call_out( "more_heavy", 100 );
}

void owner_is_killed()
{
	set_weight(100);
}

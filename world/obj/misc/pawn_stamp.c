// pawn_stamp.c

inherit ITEM;

void create()
{
	set_name("µ±Æ±", ({ "pawn stamp", "stamp" }) );
	set_weight(0);
	set("value", 1);
	set("no_sell", 1);
}

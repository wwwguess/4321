// fighting_suit.c

inherit EQUIP;

void create()
{
	set_name("˿�񳤹�", ({ "silk cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("armor_type", "cloth");
		set("value", 2000);
		set("armor_prop/dodge", 6);
		set("armor_prop/armor", 1);
	}
}

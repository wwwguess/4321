// hat.c

inherit EQUIP;

void create()
{
	set_name("�����", ({ "jade hat", "hat" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������һ�����ĵ��ڡ�\n");
		set("value", 2000);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 1);
		set("armor_prop/spells", 3);
	}
}

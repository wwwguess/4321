// robe.c

inherit EQUIP;

void create()
{
	set_name("���Ե���", ({ "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ����ǰ���а��ԵĻ�ɫ���ۡ�\n");
		set("value", 8000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/spells", 5);
	}
}

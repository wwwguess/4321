// kame_suit.c

inherit EQUIP;

void create()
{
	set_name("�����������", ({ "kame suit", "suit" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ӡ�й����ɱ�ǵ���������������ʹ���\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/attack", 2);
	}
}

// garlic.c

inherit COMBINED_ITEM;

void create()
{
	set_name("����", ({"garlic"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ǳ����ĵ�ζƷ��\n");
		set("unit", "Щ");
		set("base_unit", "��");
		set("base_weight", 20);
		set("base_value", 5);
		set("medical_effect/ˮ", ({ 3, 2, -2 }) );
	}
	set_amount(1);
}

// black-robe.c ��ɫ����
// By dan

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ɫ����", ({"pao", "cloth", "chang pao"}) );
    set_weight(4500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "���Ǽ����Žྻ�ĺ�ɫ���ۡ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 3);
    }
    setup();
}

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("��ɫ����", ({"pao", "cloth", "chang pao"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "���Ǽ��ʵشֲڵİ�ɫ���ۣ�ǰ�غ󱳶�����һ�Ż���ʥ��\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}


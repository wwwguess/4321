// huishan.c ��ɫ����
// By Marz

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("��ɫ����", ({"shan", "cloth", "chang shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "���Ǽ��ʵشֲڵ���ɫ������\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}

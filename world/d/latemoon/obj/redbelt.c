#include <ansi.h>

#include <armor.h>
inherit WAIST;

void create()
{                              
     set_name(HIG "����"+ HIM "���δ�" NOR, ({"Red belt","belt"}) );
     set_weight(500);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
     set("long", "����һ��˿���ƵĲʴ����ʸмѣ������вʡ���ˮ�ơ�\n");
            set("unit", "��");
            set("value", 2000);
            set("material", "cloth");
            set("armor_prop/armor", 4);
     set("wear_msg", "$N��$n�ó�ϵ�����ϡ�\n");
    }
    setup();
}

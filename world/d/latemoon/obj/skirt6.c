#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name( "�ײ�ȹ", ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 400);
                set("material", "cloth");
               set("armor_prop/armor", 1);
        set("wear_msg", "$N��$n�ó�ϵ�����ϡ�\n");
        }
        setup();
}

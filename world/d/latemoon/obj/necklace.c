#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIM "��������" NOR, ({ "necklace" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "pearl");
                set("armor_prop/armor", 5);
                set("armor_prop/spells",5);
                set("wear_msg", "$N�ó�һ��$n���ھ����ϡ�\n");
        }
        setup();
}

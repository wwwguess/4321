
#include <armor.h>
inherit NECK;

void create()
{
        set_name( "��ʯ����", ({ "brooch diamond","brooch" }) );
        set("long","����һ������ʯ��ɵ��������Ρ�\n");
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1500);
                set("material", "gold");
                set("armor_prop/armor", 2);
        set("wear_msg", "$N��$n��������ó�������ǰ�����ϡ�\n");
        }
        setup();
}

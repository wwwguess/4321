// moon_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("˪�µ�", ({ "moon blade", "blade" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"����һ��ҫ�۵����У�����������е����ۣ����ǳ½���ĳ���������\n");
                        
                set("value", 1800);
                set("material", "steel");
                set("wield_msg", 
"ֻ������쬡���һ����$N�������Ѿ�����һ��$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        init_blade(40);
        setup();
}
 

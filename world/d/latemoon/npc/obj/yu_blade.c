#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("����", ({ "blade","yu-blade" }) );
       set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "iron");
                set("long", "����һ����ϸ�����񵶣��ᱡ��С��\n");
                set("wield_msg", "$N���һ����ϸ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
        init_blade(27);
        setup();
}

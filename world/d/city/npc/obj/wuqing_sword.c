// wuqing_sword.c"
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
    set_name( HIW"���齣" NOR,({"cool sword","sword"}));
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit", "��");
        set("long", "���溮�����ˣ���������������⡣\n");
                set("value", 24000);
                set("material", "�������");
        set("wield_msg", "$N��ৡ���һ�����һ�Ѻ������˵�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        set("replica_ob", "/obj/weapon/longsword");
    }
        init_sword(45);
        setup();
}


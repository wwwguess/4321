// duoqing_blade.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("�����",({"chunqiu_pen","pen"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","֧");
                set("long",
                    "����һ�ֵ�Ѩ���������\n");

                set("value", 20000);
                set("material", "steel");
                set("wield_msg",
    "ֻ��  ɭ  ��һ����$N��һ֧$n��������\n");
                set("unwield_msg",
   "ֻ��$N����һת���Ͱ���֧$n��������\n");
        }
        init_sword(80);
        setup();
}


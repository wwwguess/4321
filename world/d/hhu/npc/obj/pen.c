// duoqing_blade.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("ë��",({"pen","maobi"}));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","֧");
                set("long",
     "ë��ƽʱд�֣��ؼ�ʱ��������\n"
     );

                set("value",2000);
                set("material","wood");
                set("wield_msg",
    "ֻ��  ɭ  ��һ����$N��һ֧$n��������\n");
                set("unwield_msg",
   "ֻ��$N����һת���Ͱ���֧$n��������\n");
        }
        init_sword(25);
        setup();
}


// duoqing_blade.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("毛笔",({"pen","maobi"}));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","支");
                set("long",
     "毛笔平时写字，关键时当武器！\n"
     );

                set("value",2000);
                set("material","wood");
                set("wield_msg",
    "只听  森  的一声，$N把一支$n抄在手里\n");
                set("unwield_msg",
   "只见$N身形一转，就把那支$n藏了起来\n");
        }
        init_sword(25);
        setup();
}


// duoqing_blade.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("春秋笔",({"chunqiu_pen","pen"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","支");
                set("long",
                    "这是一种点穴的最佳武器\n");

                set("value", 20000);
                set("material", "steel");
                set("wield_msg",
    "只听  森  的一声，$N把一支$n抄在手里\n");
                set("unwield_msg",
   "只见$N身形一转，就把那支$n藏了起来\n");
        }
        init_sword(80);
        setup();
}


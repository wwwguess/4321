//ywswod.c 
//by dwolf
//97.11.8

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(RED "岳王剑" NOR, ({ "yuewang jian", "jian" }));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "剑由铉铁做成，黑黝黝毫不起眼，可它和倚天同炉铸成。\n");
                set("value", 10000);
                set("material", "greysteel");
                set("wield_msg", "$N「唰」的一声抽出一柄寒气逼人的$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(200);
        setup();
}

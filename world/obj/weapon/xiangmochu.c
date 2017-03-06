// xiangmochu.c 降魔杵

#include <weapon.h>
#include <ansi.h>
inherit PESTLE;

void create()
{
        set_name(BLK "降魔杵" NOR, ({ "xiangmo chu", "chu" }));
        set_weight(40000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long","一柄降魔杵,冒着寒气令人不寒而栗!\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背後的长囊间。\n");
                set("value", 500);
                set("material", "steel");
        }
        init_pestle(60);
        setup();
}

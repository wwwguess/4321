// ruanwei-jia.c

#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("软猥甲", ({ "ruanwei jia", "jia" }));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一件希世珍宝。\n");
                set("material", "cloth");
                set("new_taohua",1);
                set("unit", "件");
                set("value", 500000);
                set("wear_msg", HIY "只听「哗」的一声，$N打开一件软猥甲穿在身上。\n" NOR);
        set("remove_msg", HIY "$N将软猥甲身上脱了下来，折叠成小小的一块\n" NOR);
                set("armor_prop/armor", 500);
        }
 
        setup();
}

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(  GRN "真武剑" NOR, ({ "zhenwu sword","sword","zhenwu" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是武当镇山之宝，剑身通体碧绿，寒气摄人魂魄。\n"
);
                set("value", 250000);
                set("material", "steel");
                set("rigidity", 1000000);
                set("wield_msg", YEL "铮地一声,$N的手中已多了一把斩妖除魔的$n。\n" NOR);
                set("unequip_msg", HIY "$N将手中的$n插入腰间的剑鞘。\n" NOR);
        }

     init_sword(400);
        setup();

}
//int query_autoload() { return 1; } 
